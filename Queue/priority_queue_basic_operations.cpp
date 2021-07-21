#include<bits/stdc++.h>
using namespace std;

struct myqueue
{
    int *arr;
    int queue_size,f,r;
    myqueue(int s)
    {
        queue_size = s;
        arr = (int *)malloc(sizeof(int)*s);
        f=-1;
        r=-1;
    }
};

void enqueue(struct myqueue &s, int element)
{
	if(s.r>=s.queue_size-1)
	{
		cout<<"Queue Overflow"<<endl;
		return;
	}
	else if(s.f ==-1 && s.r ==-1)
	{
		s.f+=1;
		s.r+=1;
		s.arr[s.r] = element;
	}
	else
	{
		int i;
        for(i=s.r;i>=s.f;i--)
        {
            if(s.arr[i]<element)
            {
                s.arr[i+1]=s.arr[i];
            }
            else
            {
                break;
            }
        }
        s.r += 1;
        s.arr[i+1] = element;
	}
	cout<<"Element enqueued"<<endl;
}

void dequeue(struct myqueue &s)
{
	if(s.f==-1 && s.r==-1)
	{
		cout<<"Queue Undeflow"<<endl;
		return;
	}
	else if(s.f == s.r)
	{
		s.r=-1;
		s.f = -1;
	}
	else
	{
		s.f += 1;
	}
	cout<<"Element dequeued"<<endl;
}

void display(struct myqueue &s)
{
    int i = s.f,n= s.r;
    if(i==-1 && n==-1)
    {
        cout<<"Queue Empty"<<endl;
        return;
    }
    cout<<"Queue elements are : ";
    for(;i<=n;i++)
    {
        cout<<s.arr[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    int queue_size=10,i=1,ch,ele;
    cout<<"********** Priority Queue (High Value => High Priority) **********"<<endl;
	cout<<"Enter size of queue : ";
	cin>>queue_size;

	struct myqueue mys(queue_size);

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
            enqueue(mys,ele);
            break;
        case 2:
            dequeue(mys);
            break;
        case 3:
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
