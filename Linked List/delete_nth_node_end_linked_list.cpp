#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node * next;
};

int main()
{
    struct node *head,*ptr,*ptr1,*temp;
    int data,ch=1;
    head=NULL;
    while(ch)
    {
        ptr1 = (struct node *)malloc(sizeof(struct node));
        cout<<"Enter data : ";
        cin>>data;
        ptr1->data=data;
        ptr1->next=NULL;
        if(head==NULL)
        {
            head = ptr1;
        }
        else
        {
            ptr->next = ptr1;
        }
        ptr=ptr1;
        cout<<"Insert more nodes: ";
        cin>>ch;
    }

    cout<<"Original Linked list : ";
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<(ptr->data)<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL\n";

    cout<<"Enter value of n for nth node from end : ";
    cin>>data;
    ptr=head;
    temp = head;
    ptr1=head;
    int cnt=1;
    while(cnt!=data)
    {
        ptr=ptr->next;
        cnt++;
    }
    while(ptr->next!=NULL)
    {
        temp = ptr1;
        ptr1=ptr1->next;
        ptr=ptr->next;
    }
    cout<<data<<" node from end = "<<ptr1->data<<"\n";
    temp->next=ptr1->next;
    free(ptr1);
    cout<<"After deletion, Linked list : ";
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<(ptr->data)<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL\n";
    return 0;
}
