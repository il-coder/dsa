#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int arr[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        int changed = 0;
        for(int j=0; j< n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                changed = 1;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(changed == 0)
        {
            break;
        }
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
    printf("***** C PROGRAM TO IMPLEMENT BUBBLE SORT ON AN ARRAY *****\n\n");
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
    bubble_sort(arr,n);
    printf("After sorting, Array is : ");
    display(arr,n);
    return 0;
}
