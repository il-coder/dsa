#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *prev,*next;
};

void insert_beg(struct node **head,int data)
{
    struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
    ptr1->data = data;
    ptr1->prev = NULL;
    if(*head==NULL)
    {
        ptr1->next = NULL;
    }
    else
    {
        ptr1->next = *head;
        (*head)->prev = ptr1;
    }
    *head = ptr1;
}

void insert_end(struct node **head, int data)
{
    struct node * ptr1 = (struct node *)malloc(sizeof(struct node));
    ptr1->data = data;
    ptr1->next = NULL;
    if(*head==NULL)
    {
        ptr1->prev = NULL;
        *head = ptr1;
    }
    else
    {
        struct node * ptr = *head;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next = ptr1;
        ptr1->prev=ptr;
    }
}

void insert_pos(struct node **head, int data, int pos)
{
    if(pos==1)
    {
        insert_beg(head,data);
    }
    else
    {
        struct node *ptr = *head;
        int cnt = 1;
        while(cnt<pos-1)
        {
            ptr=ptr->next;
            cnt++;
        }
        struct node *ptr1= (struct node *)malloc(sizeof(struct node));
        ptr1->data = data;

        ptr1->next = ptr->next;
        ptr1->prev=ptr;
        if(ptr->next!=NULL)
        {
            ptr->next->prev = ptr1;
        }
        ptr->next = ptr1;
    }
}

int main()
{
    struct node * head = NULL,*ptr1,*ptr;
    int data,ch=1,d,pos;
    while(ch)
    {
        cout<<"Enter data : ";
        cin>>data;
        cout<<"Enter position : ";
        cin>>pos;
        insert_pos(&head,data,pos);
        cout<<"Enter more nodes : ";
        cin>>ch;
    }
    ptr = head;
    cout<<"Linked list is : ";
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"--";
        ptr=ptr->next;
    }
    cout<<"NULL\n";
	return 0;
}
