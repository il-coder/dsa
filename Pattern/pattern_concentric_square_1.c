#include<stdio.h>
#include<stdlib.h>

/*
N = 4

4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4

*/
int main()
{
    int start,end,n,size=0;  //n = number of rows
    printf("Enter number of rows : ");
    scanf("%d",&n);
    size = 2*n-1;
    int pattern[size][size];
    start = 0;
    end = size-1;

    while(n!=0) {
        for(int i = start; i <= end; i++) {
            for(int j = start; j <= end; j++) {
                if(i == start || i == end || j == start || j == end) {
                    pattern[i][j] = n;
                }
            }
        }
        start++;
        end--;
        n--;
    }

    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            printf("%d ",pattern[i][j]);
        }
        printf("\n");
    }

    return 0;
}
