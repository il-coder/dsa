#include <iostream>
#include <math.h>
using namespace std;

struct mystack  //structure for stack
{
    int tos,len;
    int *arr;
    mystack(int n) //constructor
    {
        tos = -1;
        len = n;
        arr = (int *)malloc(sizeof(int)*n);
    }
};

void push(struct mystack &s,int n) //function for push operation
{
    if(s.tos>=s.len-1)
    {
        cout<<"WARNING: STACK OVERFLOW"<<endl;
    }
    else
    {
        s.arr[++s.tos]=n;
    }
}

void pop(struct mystack &s) //function for pop operation
{
    if(s.tos<=-1)
    {
        cout<<"WARNING: STACK UNDERFLOW"<<endl;
    }
    else
    {
        s.tos-=1;
    }
}

bool isEmpty(struct mystack &s) //function to check if stack is empty
{
    if(s.tos<=-1)
    {
        return true;
    }
    return false;
}

int getValue(struct mystack &s) //function to get value of top of stack
{
    if(!isEmpty(s))
    {
        return s.arr[s.tos];
    }
    return -1;
}

int evalPostfix(string str) //function to evaluate postfix expression
{
    struct mystack mys(70);
    int ans=0,a,b;
    for(int i=0;str[i];i++)
    {
        if(str[i]>=48 && str[i]<=57)
        {
            push(mys,str[i]-48);
        }
        else
        {
            a = getValue(mys);
            pop(mys);
            b = getValue(mys);
            pop(mys);
            if(str[i]=='*') push(mys,(a*b));
            else if(str[i]=='/') push(mys,b/a);
            else if(str[i]=='^') push(mys,pow(b,a));
            else if(str[i]=='+') push(mys,a+b);
            else if(str[i]=='-') push(mys,b-a);
        }
    }
    ans = getValue(mys);
    pop(mys);
    return ans;
}

int main()
{
    int n,j;
    string str;
    cout<<"Enter number of strings : ";
    cin>>n;
    for(j=0;j<n;j++)
    {
        cout<<"Enter string : ";
        cin>>str;
        cout<<evalPostfix(str)<<endl;
    }
    return 0;
}
