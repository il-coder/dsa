#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int arr[],int n)
{
    for(int i=1; i<n; i++)
    {
        int curr = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > curr)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
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
    printf("***** C PROGRAM TO IMPLEMENT INSERTION SORT ON AN ARRAY *****\n\n");
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter values of elements of array :  ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Before sorting, Array is : ");
    display(arr,n);
    insertion_sort(arr,n);
    printf("After sorting, Array is : ");
    display(arr,n);
    return 0;
}
