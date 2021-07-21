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

bool check_priority(char a, char b)
{
    if(a=='^' || ((a=='*' || a=='/') && (b=='+' || b=='-')) || b=='(')
    {
        return false;
    }
    /*else if(((a=='*' || a=='/') && (b=='*' || b=='/')) || ((a=='-' || a=='+') && (b=='-' || b=='+')))
    {
        return true;
    }*/
    return true;
}

string toPostfix(string str) //function to convert infix expression to postfix
{
    struct mystack mys(70);
    string res="";
    for(int i=0;str[i];i++)
    {
        if(str[i]=='(')
        {
            push(mys,str[i]);
        }
        else if((str[i]>=48 && str[i]<=57) || (str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122))
        {
            res += str[i];
        }
        else if(str[i]==')')
        {
            while(getValue(mys)!='(')
            {
                res += getValue(mys);
                pop(mys);
            }
            pop(mys);
        }
        else
        {
            if(getValue(mys)=='(')
            {
                push(mys,str[i]);
            }
            else
            {
                while(check_priority(str[i],getValue(mys)))
                {
                    res += getValue(mys);
                    pop(mys);
                }
                push(mys,str[i]);
            }
        }
    }
    return res;
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
        str = "(" + str + ")";
        cout<<toPostfix(str)<<endl;
    }
    return 0;
}
