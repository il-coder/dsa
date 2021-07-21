#include<stdio.h>
#include<stdlib.h>

//segregate even and odd in an array
int main()
{
    int n,i,cnt=0,x,y;
    printf("Enter number of array elements : ");
    scanf("%d",&n); //no of array elements
    int *arr = (int *)malloc(sizeof(int)*n); //array
    printf("Enter array elements : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);    //array input
    }
    printf("\nGiven Array : ");
    for(i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    y=n-1;
    for(i=0; i<=y; i++)
    {
        if(arr[i]%2==1)
        {
            int t = arr[i];
            arr[i] = arr[y];
            arr[y] = t;
            i--;
            y--;
        }
    }
    printf("\nModified Array : ");
    for(i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
