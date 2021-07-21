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
		ptr->next =ptr1;
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

int nth_end_1(struct node *head,int pos)
{
    struct node *ptr1;
    int cnt=1;
    ptr1=head;
    while(ptr1!=NULL)
    {
        ptr1 = ptr1->next;
        cnt++;
    }
    pos = cnt - pos;
    cnt = 1;
    ptr1 = head;
    while(cnt!=pos)
    {
        cnt++;
        ptr1 = ptr1->next;
    }
    return ptr1->data;
}

int nth_end_2(struct node *head,int pos)
{
    struct node *ptr,*ptr1;
    ptr=head;
    ptr1=head;
    int cnt=1;
    while(cnt!=pos)
    {
        cnt++;
        ptr=ptr->next;
    }
    while(ptr->next!=NULL)
    {
        ptr1=ptr1->next;
        ptr=ptr->next;
    }
    return ptr1->data;
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
        cout<<"Enter type 1.Insert :";
        cin>>d;
        if(d==1)
        {
            cout<<"Enter value : ";
            cin>>data;
            insert_end(&head,data);
            printLL(head);
        }
        else
        {
            cout<<"Wrong Choice\n";
        }
        cout<<"Perform more operations : ";
        cin>>ch;
    }
    cout<<"Enter n : ";
    cin>>val;
    cout<<nth_end_1(head,val)<<endl;
    cout<<nth_end_2(head,val)<<endl;
	return 0;
}
