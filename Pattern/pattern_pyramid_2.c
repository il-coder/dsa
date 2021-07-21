#include<stdio.h>
#include<stdlib.h>

/*
    *
   * *
  * * *
 * * * *
* * * * *
*/
int main()
{
    int row,col,n;  //n = number of rows
    printf("Enter number of rows : ");
    scanf("%d",&n);
    for(int row=1; row<=n; row++)
    {
        int flag = 1;
        for(int col = 1; col<=2*n-1; col++)
        {
            if(col > n-row && col < n+row && flag)
            {
                printf("*");
                flag=0;
            }
            else
            {
                printf(" ");
                flag=1;
            }
        }
        printf("\n");
    }
    return 0;
}
