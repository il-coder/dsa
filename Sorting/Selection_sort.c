#include<stdio.h>
#include<stdlib.h>

void selection_sort(int arr[],int n)
{
    for(int i=0; i < n-1; i++)
    {
        int min = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
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
    printf("***** C PROGRAM TO IMPLEMENT SELECTION SORT ON AN ARRAY *****\n\n");
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
    selection_sort(arr,n);
    printf("After sorting, Array is : ");
    display(arr,n);
    return 0;
}
