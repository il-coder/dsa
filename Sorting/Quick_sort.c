#include<stdio.h>
#include<stdlib.h>
/* using Hoare partition scheme */
int partition(int arr[],int beg,int end)
{
    int a = beg,b = end, p = beg;
    while(1)
    {
        while(b > p && arr[p] <= arr[b])
        {
            b -= 1;
        }
        if(b != p)
        {
            int t = arr[p];
            arr[p] = arr[b];
            arr[b] = t;
            p = b;
        }

        while(a < p && arr[p] >= arr[a])
        {
            a +=1;
        }
        if(a != p)
        {
            int t = arr[p];
            arr[p] = arr[a];
            arr[a] = t;
            p = a;
        }

	if(a >= b)
	{
		return p;
	}
    }
}

void quick_sort(int arr[], int beg, int end)
{
	if(beg < end)
        {
	    int p = partition(arr,beg,end);
            quick_sort(arr,beg,p-1);
            quick_sort(arr,p+1,end);
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
    printf("***** C PROGRAM TO IMPLEMENT QUICK SORT ON AN ARRAY *****\n\n");
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
    quick_sort(arr,0,n-1);
    printf("After sorting, Array is : ");
    display(arr,n);
    return 0;
}
