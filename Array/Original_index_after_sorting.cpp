#include<bits/stdc++.h>
using namespace std;

int N;

void merge(int arr[],int arr1[], int beg, int mid, int end, int aux[])
{
    int i = beg, j = mid+1, k = beg,u=0;
    while(i<=mid && j<=end)
    {
        if(arr[i] > arr[j])
        {
            aux[k] = arr[j];
            arr1[k] = (arr1[k] + (arr1[j]%N)*N);
            j++;
        }
        else
        {
            aux[k] = arr[i];
            arr1[k] = (arr1[k] + (arr1[i]%N)*N);
            i++;
        }
        k++;
    }

    while(i <= mid)
    {
        aux[k] = arr[i];
        arr1[k] = (arr1[k] + (arr1[i]%N)*N);
        i++;
        k++;
    }

    while(j <= end)
    {
        aux[k] = arr[j];
        arr1[k] = (arr1[k] + (arr1[j]%N)*N);
        j++;
        k++;
    }

    for(k = beg,u=0; k <= end; k++,u++)
    {
        arr[k] = aux[k];
        arr1[k] = arr1[k]/N;
    }
}

void merge_sort(int arr[], int arr1[], int beg, int end, int aux[])
{
    if(beg >= end)
    {
        return;
    }
    int mid = (beg+end)/2;
    merge_sort(arr,arr1,beg,mid,aux);
    merge_sort(arr,arr1,mid+1,end,aux);
    merge(arr,arr1,beg,mid,end,aux);
}

int main()
{
    int arr[] = {1,78,45,12,36};
    int n = sizeof(arr)/sizeof(arr[0]);
    int arr1[n];
    cout<<"Inital List : ";
    for(int i=0;i<n;i++)
    {
        arr1[i] = i;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    N = n;
    int aux[n];
    merge_sort(arr,arr1,0,n-1,aux);

    /*for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;*/

    for(int i=0;i<n;i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    return 0;
}
