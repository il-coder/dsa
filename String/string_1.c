#include<stdio.h>
#include<stdlib.h>

//characters to add in beginning to make string palindrome
int main()
{
    int n,i,cnt=0,j,u;
    printf("Enter length of string : ");
    scanf("%d",&n); //length of string
    char *str = (char *)malloc(sizeof(char)*(n+1)); //char array
    printf("Enter string : ");
    scanf("%s",str);

    //initialize u=len-1

    //check if 0 to u is palindrome using i=0 and j=u

    //if i and j character same, then increment i and decrement j

    //else if don't match, then reset i=0 and j=u
    //and increase count by 1 and decrease j and u by 1 because we need to add corresponding character at beginning
    //since 0 to u is not palindrome

    //repeat 2 to 4 until palindrome is found
    for(i=0,j=n-1,u=n-1; i<(n/2); i++,j--)
    {
        if(str[i]!=str[j])
        {
            cnt+=1;
            i=-1;
            j = u;
            u--;
        }
    }
    printf("\nCount of characters to be added : %d",cnt);
    return 0;
}
