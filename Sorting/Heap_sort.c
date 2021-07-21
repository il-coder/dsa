#include<stdio.h>
#include<stdlib.h>

void heapify(int arr[],int i, int heap_size)
{
    int l = 2*i +1;
    int r = 2*i + 2;
    int largest = i;
    if(l < heap_size && arr[l] > arr[largest])
    {
        largest = l;
    }
    if(r < heap_size && arr[r] > arr[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapify(arr,largest,heap_size);
    }
}

void heap_sort(int arr[],int n)
{
    int heap_size = n,i;
    for(i = n/2-1 ; i >=0 ; i--)
    {
        heapify(arr,i,heap_size);
    }

    for(i = n-1; i >=0; i--)
    {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heap_size --;
        heapify(arr,0,heap_size);
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
    printf("***** C PROGRAM TO IMPLEMENT HEAP SORT ON AN ARRAY *****\n\n");
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
    heap_sort(arr,n);
    printf("After sorting, Array is : ");
    display(arr,n);
    return 0;
}
