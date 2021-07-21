#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node * next;
};

void printLL(struct node *head)
{
    struct node * ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<"NULL\n";
}

void swap_nodes(struct node *head)
{
    struct node *ptr,*ptr1;
    ptr=head;
    if(ptr==NULL)
        return;
    ptr1=head->next;
    while(ptr!=NULL && ptr1!=NULL)
    {
        int t = ptr->data;
        ptr->data = ptr1->data;
        ptr1->data = t;
        ptr=ptr->next->next;
        if(ptr1->next==NULL)
            return;
        ptr1=ptr1->next->next;
    }
}

int main()
{
    struct node *head,*ptr,*newNode;
    head=NULL;
    int ch,data;
    ch=1;
    while(ch)
    {
        cout<<"Enter data : ";
        cin>>data;
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next=NULL;
        if(head==NULL)
        {
            head = newNode;
        }
        else
        {
            ptr->next = newNode;
        }
        ptr = newNode;
        cout<<"Enter more nodes : ";
        cin>>ch;
    }
    printLL(head);
    swap_nodes(head);
    printLL(head);
    return 0;
}
