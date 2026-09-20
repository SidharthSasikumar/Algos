/* C++ Program - Insertion Sort */
		
#include<iostream>

using namespace std;
int main()
{

	int size, arr[50], i, j, temp;
	cout<<"Enter Array Size : ";
	cin>>size;
 if (!cin || size < 0 || size > 50) return 1;
	cout<<"Enter Array Elements : ";
	for(i=0; i<size; i++)
	{
		if (!(cin>>arr[i])) return 1;
	}
	cout<<"Sorting array using selection sort ... \n";
	for(i=1; i<size; i++)
	{
		temp=arr[i];
		j=i-1;
		while((j>=0) && (temp<arr[j]))
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
	}
	cout<<"Array after sorting : \n";
	for(i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}

}