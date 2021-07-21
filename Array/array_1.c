#include<stdio.h>
#include<stdlib.h>

//count of array elements with value in given range
int main()
{
    int n,i,cnt=0,x,y;
    printf("Enter number of array elements : ");
    scanf("%d",&n); //no of array elements
    int *arr = (int *)malloc(sizeof(int)*n); //array
    printf("Enter array elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);    //array input
    }
    printf("Enter x and y : ");
    scanf("%d%d",&x,&y);  //number input
    printf("Given Array : ");
    for(i=0;i<n;i++)
    {
        if(arr[i]>=x && arr[i]<=y)  //checking condiiton
        {
            cnt+=1;
        }
        printf("%d ",arr[i]);
    }
    printf("\nCount of elements with values in range %d to %d is : %d\n",x,y,cnt);
    return 0;
}
