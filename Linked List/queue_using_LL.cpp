#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node * next;
};

void enqueue(struct node **r,struct node **h,int data)
{
	struct node * ptr1 = (struct node *)malloc(sizeof(struct node));
	ptr1->data = data;
	ptr1->next=NULL;
    if(*h==NULL)
    {
        *h = ptr1;
    }
    else
    {
        (*r)->next = ptr1;
    }
	*r = ptr1;
}

void dequeue(struct node**h)
{
    if(*h==NULL)
    {
        cout<<"Queue is empty\n";
    }
    else
    {
        struct node *ptr = *h;
        *h = (*h)->next;
        free(ptr);
    }
}

void printQueue(struct node *h)
{
    cout<<"Queue is ";
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
	struct node *head,*rear;
	head = NULL;
	rear = NULL;
	int ch=1,d,data,val;
	while(ch)
    {
        cout<<"Enter type 1.Enqueue  2.Dequeue  3. Display : ";
        cin>>d;
        if(d==1)
        {
            cout<<"Enter value : ";
            cin>>data;
            enqueue(&rear,&head,data);
        }
        else if(d==2)
        {
            dequeue(&head);
        }
        else if(d==3)
        {
            printQueue(head);
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
