#include<iostream>
#include<iomanip>

using namespace std;
int main()
{
     int a[50], n,i,j;
     cout<<"\nEnter the size of list: ";
     cin>>n;
 if (!cin || n < 0 || n > 50) return 1;
     cout<<"Enter "<<n<<" values: ";
     for(i=0; i<n; i++)
           if (!(cin>>a[i])) return 1;
     for(i=0; i<n-1; i++)
           for(j=i+1; j<n; j++)
                if(a[i] < a[j])
                {
                     int t = a[i];
                     a[i] = a[j];
                     a[j] = t;
                 }
     cout<<"\nArranged list is: ";
     for(i=0; i<n; i++)
           cout<< setw(5) << a[i];
}
