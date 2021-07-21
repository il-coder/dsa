#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node * next;
};

void insert_beg(struct node **h,int data)
{
    struct node * ptr1 = (struct node *)malloc(sizeof(struct node));
	ptr1->data = data;
	if(*h==NULL)
	{
		ptr1->next=ptr1;
	}
	else
	{
		ptr1->next = *h;
		struct node *ptr = *h;
		while(ptr->next!=*h)
        {
            ptr=ptr->next;
        }
        ptr->next = ptr1;
	}
	*h = ptr1;
}

void insert_end(struct node **h,int data)
{
	struct node * ptr1 = (struct node *)malloc(sizeof(struct node));
	struct node * ptr = *h;
	ptr1->data = data;
	if(*h==NULL)
	{
		*h = ptr1;
	}
	else
	{
		while(ptr->next!=*h)
		{
			ptr = ptr->next;
		}
		ptr->next = ptr1;
	}
	ptr1->next=*h;
}

void insert_after(struct node**h , int data, int val)
{
    struct node * ptr1 = (struct node *)malloc(sizeof(struct node));
	struct node * ptr = *h;
	ptr1->data = data;
	while(ptr->data!=val)
    {
        if(ptr->next==*h)
        {
            cout<<"Not found\n";
            return;
        }
        ptr=ptr->next;
    }
    if(ptr->next==*h)
    {
        ptr1->next = *h;
        ptr->next = ptr1;
    }
    else
    {
        ptr1->next=ptr->next;
        ptr->next=ptr1;
    }
}

void insert_before(struct node**h , int data, int val)
{
    struct node * ptr1 = (struct node *)malloc(sizeof(struct node));
	struct node * ptr = *h;
	ptr1->data = data;
	while(ptr->next->data!=val)
    {
        if(ptr->next==*h)
        {
            cout<<"Not found\n";
            return;
        }
        ptr=ptr->next;
    }
    ptr1->next=ptr->next;
    ptr->next=ptr1;
}

void printLL(struct node *h)
{
    cout<<"Linked List is ";
	struct node * ptr = h;
	if(h==NULL)
    {
        cout<<"empty.\n";
        return;
    }
	while(ptr->next!=h)
	{
		cout<<ptr->data<<"->";
		ptr = ptr->next;
	}
	cout<<ptr->data;
	cout<<endl;
}

int main()
{
	struct node *head;
	head=NULL;
	int ch=1,d,data,val;
	while(ch)
    {
        cout<<"Enter type 1.Beginning 2. End  3.Before  4. After : ";
        cin>>d;
        if(d==1)
        {
            cout<<"Enter value : ";
            cin>>data;
            insert_beg(&head,data);
            printLL(head);
        }
        else if(d==2)
        {
            cout<<"Enter value : ";
            cin>>data;
            insert_end(&head,data);
            printLL(head);
        }
        else if(d==3)
        {
            cout<<"Enter value : ";
            cin>>data;
            cout<<"Enter value before which to insert : ";
            cin>>val;
            insert_before(&head,data,val);
            printLL(head);
        }
        else if(d==4)
        {
            cout<<"Enter value : ";
            cin>>data;
            cout<<"Enter value after which to insert : ";
            cin>>val;
            insert_after(&head,data,val);
            printLL(head);
        }
        else
        {
            cout<<"Wrong Choice\n";
        }
        cout<<"Enter more nodes : ";
        cin>>ch;
    }
	return 0;
}
