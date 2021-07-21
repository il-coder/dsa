#include<stdio.h>
#include<stdlib.h>

/*

*/
int main()
{
    int rows,cols,n,i,j;  //n = number of rows
    printf("Enter number of rows : ");
    scanf("%d",&n);
    rows = 3*n;
    cols = 2*n - 1;
    char pattern[rows+1][cols+1];

    for(i=1;i<=rows;i++) {
        for(j=1;j<=cols;j++) {
            pattern[i][j] = ' ';
        }
    }

    for(i=1;i<=rows;i++) {
        for(j=1;j<=cols;j++) {
            if(j == n) {
                if(i == (rows-n-2)/2 + 1 || i == (rows-n-2)/2 + n + 2)
                    pattern[i][j] = '*';
                else if(i > (rows-n-2)/2 + 1 && i < (rows-n-2)/2 + n + 2)
                    pattern[i][j] = '|';
            }
            else if(j > n) {
                if(i <= j && i >= (2*n-j)) {
                    pattern[i][j] = '*';
                }
            }
            else if(j < n) {
                if(i >= n+1+j && i<=3*n+1-j) {
                    pattern[i][j] = '*';
                }
            }
        }
    }

    for(int i=1;i<=rows;i++) {
        for(int j=1;j<=cols;j++) {
            printf("%c",pattern[i][j]);
        }
        printf("\n");
    }

    return 0;
}
