#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[]={1,2,3,4,5,6,78,98,102,561,1022,2547};
	int n,i,j,k,flag=0;
	int x = 3647;
	n = sizeof(arr)/sizeof(int);
	for(i=0;i<n;i++)
    {
        j=i+1;
        k=n-1;
        while(j<=k) // two pointer algorithm because array is sorted.
        {           // Instead frequency array can also be used for limited range of array elements
            if(arr[i]+arr[j]+arr[k]==x)
            {
                cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<"\n";
                flag=1;
                break;
            }
            else if(arr[i]+arr[j]+arr[k]>x)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
        if(flag)
        {
            break;
        }
    }
    if(flag==0)
    {
        cout<<"No triplet found\n";
    }
	return 0;
}
