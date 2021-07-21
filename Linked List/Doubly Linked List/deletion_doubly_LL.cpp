#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *prev,*next;
};

void delete_beg(struct node **head)
{
    if(*head!=NULL)
    {
        if((*head)->next==NULL)
        {
            free(*head);
            *head=NULL;
        }
        else
        {
            struct node *ptr=*head;
            ptr->next->prev=NULL;
            *head = (*head)->next;
            free(ptr);
        }
    }
}

void delete_end(struct node **head)
{
    if(*head!=NULL)
    {
        if((*head)->next==NULL)
        {
            free(*head);
            *head=NULL;
        }
        else
        {
            struct node*ptr=*head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->prev->next=NULL;
            free(ptr);
        }
    }

}

void delete_pos(struct node **head,int pos)
{
    if(pos==1)
    {
        delete_beg(head);
    }
    else
    {
        int cnt=1;
        struct node *ptr = *head;
        while(ptr!=NULL && cnt!=pos)
        {
            cnt++;
            ptr=ptr->next;
        }
        if(ptr==NULL)
        {
            cout<<"Invalid position\n";
            return;
        }
        ptr->prev->next=ptr->next;
        if(ptr->next!=NULL)
        {
            ptr->next->prev = ptr->prev;
        }
        free(ptr);
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
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = data;
        ptr->next=NULL;
        if(head==NULL)
        {
            ptr->prev=NULL;
            head = ptr;
        }
        else
        {
            ptr->prev=ptr1;
            ptr1->next = ptr;
        }
        ptr1=ptr;

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

    delete_beg(&head);
    delete_end(&head);

    ptr=head;
    cout<<"Linked list is : ";
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"--";
        ptr=ptr->next;
    }
    cout<<"NULL\n";

    delete_pos(&head,4);
    ptr=head;
    cout<<"Linked list is : ";
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"--";
        ptr=ptr->next;
    }
    cout<<"NULL\n";
	return 0;
}
