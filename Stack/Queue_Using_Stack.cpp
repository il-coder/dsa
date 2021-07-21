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
        cout<<"WARNING: QUEUE OVERFLOW"<<endl;
    }
    else
    {
        s.arr[++s.tos] = n;
    }
}

void pop(struct mystack &s)
{
    if(s.tos<=-1)
    {
        cout<<"WARNING: QUEUE UNDERFLOW"<<endl;
    }
    else
    {
        s.tos = s.tos -1;
    }
}

void display(struct mystack &s)
{
    int counter = s.tos;
    if(counter==-1)
    {
        cout<<"Empty Queue";
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


int main()
{
	int queue_size=10,i=1,ch,ele;
	cout<<"Enter size of queue : ";
	cin>>queue_size;

	struct mystack s1(queue_size),s2(queue_size); //declaration of stack

	while(i)
    {
        ch = 10;
        cout<<"\nEnter choice (1. Enqueue  2. Dequeue  3. Display  4. Quit) : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter element : ";
            cin>>ele;
            push(s1,ele);
            break;
        case 2:
            while(s1.tos!=-1)
            {
                push(s2,s1.arr[s1.tos]);
                pop(s1);
            }
            pop(s2);
            while(s2.tos!=-1)
            {
                push(s1,s2.arr[s2.tos]);
                pop(s2);
            }
            break;
        case 3:
            cout<<"Queue elements are : ";
            while(s1.tos!=-1)
            {
                push(s2,s1.arr[s1.tos]);
                pop(s1);
            }
            display(s2);
            while(s2.tos!=-1)
            {
                push(s1,s2.arr[s2.tos]);
                pop(s2);
            }
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
