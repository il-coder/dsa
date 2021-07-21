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
	ptr1->next=NULL;
	if(*h==NULL)
	{
		*h = ptr1;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = ptr1;
	}
}

void insert_after(struct node**h , int data, int val)
{
    struct node * ptr1 = (struct node *)malloc(sizeof(struct node));
	struct node * ptr = *h;
	ptr1->data = data;
	while(ptr->data!=val)
    {
        ptr=ptr->next;
    }
    ptr1->next=ptr->next;
    ptr->next=ptr1;
}

void insert_before(struct node**h , int data, int val)
{
    struct node * ptr1 = (struct node *)malloc(sizeof(struct node));
	struct node * ptr = *h;
	ptr1->data = data;
	while(ptr->next!=NULL)
    {
        if(ptr->next->data==val)
        {
            break;
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
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<ptr->data;
	cout<<endl;
}

int main()
{
	struct node *head;
	head=NULL;
	struct node *ptr1, *ptr;
	int ch=1,d,data,val;
	while(ch)
    {
        cout<<"Enter data : ";
        cin>>data;
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = data;
        if(head==NULL)
        {
            ptr->next = ptr;
            head = ptr;
        }
        else
        {
            ptr1->next = ptr;
            ptr->next = head;
        }
        ptr1 = ptr;
        cout<<"Enter more nodes : ";
        cin>>ch;
    }
    printLL(head);
	return 0;
}
