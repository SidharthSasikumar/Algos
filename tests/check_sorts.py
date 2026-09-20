"""Compile strict C++17 with memory/undefined-behavior checks, then test output."""
from pathlib import Path
import re, subprocess, tempfile
root=Path(__file__).resolve().parents[1]
with tempfile.TemporaryDirectory() as temp:
 for source in sorted((root/'codes').glob('*.cpp')):
  binary=Path(temp)/source.stem
  subprocess.run(['clang++','-std=c++17','-pedantic-errors','-fsanitize=address,undefined',str(source),'-o',str(binary)],check=True)
  for values in [[5,4,3,2,1],[2,2,-1,0],[1],[]]:
   result=subprocess.run([str(binary)],input=str(len(values))+'\n'+' '.join(map(str,values))+'\n',text=True,capture_output=True)
   assert result.returncode==0,(source.name,result.stderr)
   marker={'bubblesort':'Array after bubble sort:','heapsort':':::::::SORTED FORM::::::','insertionsort':'Array after sorting :','selectionsort':'Arranged list is:'}.get(source.stem,'Sorted Data')
   actual=list(map(int,re.findall(r'-?\d+',result.stdout.split(marker)[-1])))
   assert actual==sorted(values,reverse=source.stem=='selectionsort'),(source.name,actual)
  for bad in ['-1\n','1000001\n','invalid\n','2\n1 nope\n']:
   result=subprocess.run([str(binary)],input=bad,text=True,capture_output=True)
   assert result.returncode!=0,source.name
  print(source.name+': 8 cases passed')
