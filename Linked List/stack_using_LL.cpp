#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node * next;
};

void push(struct node **h,int data)
{
	struct node * ptr1 = (struct node *)malloc(sizeof(struct node));
	ptr1->data = data;
	ptr1->next=*h;
	*h = ptr1;
}

void pop(struct node**h)
{
    if(*h==NULL)
    {
        cout<<"Stack is empty\n";
    }
    else
    {
        struct node *ptr = *h;
        *h = (*h)->next;
        free(ptr);
    }
}

void printStack(struct node *h)
{
    cout<<"Stack is ";
	struct node * ptr = h;
	if(h==NULL)
    {
        cout<<"empty.\n";
        return;
    }
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

int main()
{
	struct node *head;
	cout<<sizeof(struct node)<<endl;
	head=NULL;
	int ch=1,d,data,val;
	while(ch)
    {
        cout<<"Enter type 1.Push  2.Pop  3. Display : ";
        cin>>d;
        if(d==1)
        {
            cout<<"Enter value : ";
            cin>>data;
            push(&head,data);
        }
        else if(d==2)
        {
            pop(&head);
        }
        else if(d==3)
        {
            printStack(head);
        }
        else
        {
            cout<<"Wrong Choice\n";
        }
        cout<<"Perform more operations : ";
        cin>>ch;
    }
	return 0;
}
