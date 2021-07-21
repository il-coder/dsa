#include<stdio.h>
#include<stdlib.h>

/*
    *
   ***
  *****
 *******
*********
*/
int main()
{
    int row,col,n;  //n = number of rows
    printf("Enter number of rows : ");
    scanf("%d",&n);
    for(int row=1; row<=n; row++)
    {
        for(int col = 1; col<=2*n-1; col++)
        {
            if(col > n-row && col < n+row)
            {
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
