#include <iostream>
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

bool isBalanced(string str) //function to check if parenthesis are balanced
{
    struct mystack mys(50);
    for(int i=0;str[i];i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            push(mys,str[i]);
        }
        else if(str[i]==')' || str[i]=='}' || str[i]==']')
        {
            if(isEmpty(mys))
            {
                return false;
            }
            else if(getValue(mys)- str[i]<=2) //ASCII value
            {
                pop(mys);
            }
            else
            {
                return false;
            }
        }
    }
    if(isEmpty(mys)) //if stack is empty, parenthesis are balanced
    {
        return true;
    }
    return false;
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
        if(isBalanced(str))
        {
            cout<<"Balanced\n";
        }
        else
        {
            cout<<"Unbalanced\n";
        }
        cout<<endl;
    }
    return 0;
}
