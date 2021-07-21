#include<stdio.h>
#include<stdlib.h>
#define minimum(a,b) (a>b?b:a)

//number of zeros to be flipped
int main()
{
    int n,i,cnt=0,x,y;
    printf("Enter number of array elements : ");
    scanf("%d",&n); //no of array elements
    int *arr = (int *)malloc(sizeof(int)*n); //array
    printf("Enter binary array elements : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);    //array input
    }
    printf("Enter number of zeros that can be flipped : ");
    scanf("%d",&x);
    printf("\nGiven Array : ");
    for(i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }

    //maximum number of consecutive ones is the length of array itself.
    //Number of zeros to be flipped is minimum of x and count of zeros in array
    for(i=0; i<=n; i++)
    {
        if(arr[i]==0)
        {
            cnt+=1;
        }
    }
    printf("\nNumber of zeros to be flipped : %d",minimum(x,cnt));
    return 0;
}
