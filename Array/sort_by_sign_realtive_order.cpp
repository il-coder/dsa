#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int beg, int mid, int end, int aux[])
{
    int i = beg, j = mid+1, k = beg;

    while(i<=mid && j<=end)
    {
        if(arr[i] > arr[j] && arr[j] < 0 && arr[i] >= 0)
        {
            aux[k] = arr[j];
            j++;
        }
        else
        {
            aux[k] = arr[i];
            i++;
        }
        k++;
    }

    while(i <= mid)
    {
        aux[k] = arr[i];
        i++;
        k++;
    }

    while(j <= end)
    {
        aux[k] = arr[j];
        j++;
        k++;
    }

    for(k = beg; k <= end; k++)
    {
        arr[k] = aux[k];
    }
}

void merge_sort(int arr[],int beg, int end, int aux[])
{
    if(beg >= end)
    {
        return;
    }
    int mid = (beg+end)/2;
    merge_sort(arr,beg,mid,aux);
    merge_sort(arr,mid+1,end,aux);
    merge(arr,beg,mid,end,aux);
}

int main()
{
    int arr[] = {5,6,-3,-10,-1,12,58,-36,8,-2,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Inital List : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int aux[n];
    merge_sort(arr,0,n-1,aux);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
