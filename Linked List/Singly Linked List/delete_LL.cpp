#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node * next;
};

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

void delete_beg(struct node **h)
{
	if(*h==NULL)
	{
		cout<<"Linked List is empty\n";
	}
	else
	{
	    struct node * ptr = *h;
		*h = ptr->next;
		free(ptr);
	}
}

void delete_end(struct node **h)
{
	if(*h==NULL)
	{
		cout<<"Linked List is empty\n";
	}
	else
	{
	    int f=0;
	    struct node * ptr=*h,*ptr1=*h;
		while(ptr->next!=NULL)
        {
            f=1;
            ptr1=ptr;
            ptr=ptr->next;
        }
        if(f==0)
            *h = NULL;
        else
            ptr1->next=NULL;
		free(ptr);
	}
}

void delete_pos(struct node**h , int pos)
{
    if(*h==NULL)
    {
        cout<<"Linked list is empty\n";
    }
    else
    {
        int cnt = 1,f=0;
        struct node *ptr=*h,*ptr1=*h;
        while(cnt!=pos && ptr->next!=NULL)
        {
            f=1;
            cnt++;
            ptr1=ptr;
            ptr=ptr->next;
        }
        if(cnt!=pos)
        {
            cout<<"Invalid position\n";
            return;
        }
        if(f==0)
        {
            *h = ptr->next;
        }
        else
        {
            ptr1->next = ptr->next;
        }
        free(ptr);
    }
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
	head=NULL;
	int ch=1,d,data,val;
	while(ch)
    {
        cout<<"Enter type 1.Insert  2.Delete at beginning  3.Delete at end  4.Delete at particular position :";
        cin>>d;
        if(d==1)
        {
            cout<<"Enter value : ";
            cin>>data;
            insert_end(&head,data);
            printLL(head);
        }
        else if(d==2)
        {
            delete_beg(&head);
            printLL(head);
        }
        else if(d==3)
        {
            delete_end(&head);
            printLL(head);
        }
        else if(d==4)
        {
            cout<<"Enter position : ";
            cin>>data;
            delete_pos(&head,data);
            printLL(head);
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
