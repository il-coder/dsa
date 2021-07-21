#include<bits/stdc++.h>
using namespace std;

void print_array(int arr[],int size)
{
    cout<<"Array : ";
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int arr[100],ans[100],i,j,nzero=0,n;
    cout<<"Enter number of elements in array (<=100): ";
    cin>>n;
    cout<<"Enter array elements : ";
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<"\n";
    print_array(arr,n);

    j=1;
    for(; j;)
    {
        j=0;
        for(i=0; i<n-1; i++)
        {
            if(arr[i]==arr[i+1] && arr[i]!=0)
            {
                arr[i]+=arr[i+1];
                arr[i+1] = 0;
                j=1;
            }
        }
    }

    /* Building final array */
    for(i=0,j=0; i<n; i++)
    {
        if(arr[i])
        {
            ans[j]=arr[i];
            j++;
        }
        else
        {
            nzero++;
        }
    }
    while(j<n)
    {
        ans[j] = 0;
        j++;
    }

    cout<<"Final ";
    print_array(ans,n);
    return 0;
}
