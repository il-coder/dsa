#include<stdio.h>
#include<stdlib.h>

/*
*
**
***
****
***
**
*
*/
int main()
{
    int row,col,n,k=0;  //n = number of rows
    printf("Enter number of rows : ");
    scanf("%d",&n);
    for(int row=1; row<=n; row++)
    {
        k = (row<=(n+1)/2?row:n-row+1);
        for(int col = 1; col<=(n+1)/2; col++)
        {
            if(col<=k) {
                printf("*");
            }
//            if(row<=(n+1)/2 && col <=row)
//            {
//                printf("*");
//            }
//            else if(row>(n+1)/2 && col <= n-row+1)
//            {
//                printf("*");
//            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
