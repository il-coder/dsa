#include<iostream>
using namespace std;

struct mystack
{
    int tos,stack_size;
    int *arr;
    mystack(int n)
    {
        stack_size = n;
        tos = -1;
        arr = (int *)malloc(sizeof(int)*n);
    }
};

void push(struct mystack &s, int n)
{
    if(s.tos>=s.stack_size-1)
    {
        cout<<"WARNING: STACK OVERFLOW"<<endl;
    }
    else
    {
        s.arr[++s.tos] = n;
        cout<<"Element pushed successfully."<<endl;
    }
}

void pop(struct mystack &s)
{
    if(s.tos<=-1)
    {
        cout<<"WARNING: STACK UNDERFLOW"<<endl;
    }
    else
    {
        s.tos = s.tos -1;
        cout<<"Element popped out successfully."<<endl;
    }
}

void display(struct mystack &s)
{
    int counter = s.tos;
    if(counter==-1)
    {
        cout<<"Empty Stack";
    }
    else
    {
        while(counter>=0)
        {
            cout<<s.arr[counter--]<<" ";
        }
    }
    cout<<endl;
}

//main function starts here
int main()
{
	int stack_size=10,i=1,ch,ele;
	cout<<"Enter size of stack : ";
	cin>>stack_size;

	struct mystack mys(stack_size);

	while(i)
    {
        ch = 10;
        cout<<"\nEnter choice (1. Push  2. Pop  3. Display  4. Quit) : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter element : ";
            cin>>ele;
            push(mys,ele);
            break;
        case 2:
            pop(mys);
            break;
        case 3:
            cout<<"Stack elements are : ";
            display(mys);
            break;
        case 4:
            i = 0;
            break;
        default:
            cout<<"Wrong Choice"<<endl;
            if(ch==10)
            {
                i=0;
            }
            break;
        }
    }

	return 0;
}
