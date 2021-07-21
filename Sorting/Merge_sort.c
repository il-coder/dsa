#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int beg, int mid, int end, int aux[])
{
    int i = beg, j = mid+1, k = beg;

    while(i<=mid && j<=end)
    {
        if(arr[i] < arr[j])
        {
            aux[k] = arr[i];
            i++;
        }
        else
        {
            aux[k] = arr[j];
            j++;
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
    int a = beg,b = end, mid = (beg+end)/2;
    merge_sort(arr,beg,mid,aux);
    merge_sort(arr,mid+1,end,aux);
    merge(arr,beg,mid,end,aux);
}

void display(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    printf("***** C PROGRAM TO IMPLEMENT MERGE SORT ON AN ARRAY *****\n\n");
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);
    int arr[n],aux[n];
    printf("Enter values of elements of array :  ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Before sorting, Array is : ");
    display(arr,n);
    merge_sort(arr,0,n-1,aux);
    printf("After sorting, Array is : ");
    display(arr,n);
    return 0;
}
