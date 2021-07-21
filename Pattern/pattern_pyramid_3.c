#include<stdio.h>
#include<stdlib.h>

/*
    1
   A B
  1 2 3
 A B C D
1 2 3 4 5
*/
int main()
{
    int row,col,n;  //n = number of rows
//    printf("Enter number of rows : ");
//    scanf("%d",&n);
    n=4;
    for(int row=1; row<=n; row++)
    {
        int flag = 1,u=1;
        for(int col = 1; col<=2*n-1; col++)
        {
            if(col > n-row && col < n+row && flag)
            {
                if(row%2) {
                    printf("%d",u);
                }
                else {
                    printf("%c",64+u);
                }
                u++;
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
