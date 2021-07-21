#include<stdio.h>
#include<stdlib.h>

/*
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/
int main()
{
    int row,col,n;  //n = number of rows
    printf("Enter number of rows : ");
    scanf("%d",&n);
    for(int row=1; row<=2*n-1; row++)
    {
        for(int col = 1; col<=2*n-1; col++)
        {
            if(row<=n && col >= n+1-row && col <= 2*n-1-(n-row))
            {
                printf("*");
            }
            else if(row > n && col >= row-n+1 && col <= 2*n-1-(row-n)) {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
