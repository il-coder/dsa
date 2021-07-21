#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node * next;
};

int main()
{
    struct node *head,*head1,*ptr,*ptr1;
    int data,ch=1;
    head=NULL;
    head1=NULL;
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

    ptr = head;
    while(ptr!=NULL)
    {
        ptr1 = (struct node *)malloc(sizeof(struct node));
        ptr1->data = ptr->data;
        if(head1==NULL)
        {
            ptr1->next=NULL;
        }
        else
        {
            ptr1->next = head1;
        }
        head1=ptr1;
        ptr=ptr->next;
    }

    cout<<"Reversed Linked list : ";
    ptr=head1;
    while(ptr!=NULL)
    {
        cout<<(ptr->data)<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL\n";

    ch=0;
    ptr=head;
    ptr1=head1;
    while(ptr!=NULL)
    {
        if(ptr->data!=ptr1->data)
        {
            ch=1;
            break;
        }
        ptr=ptr->next;
        ptr1=ptr1->next;
    }
    if(ch==0)
    {
        cout<<"Linked list is palindrome\n";
    }
    else
    {
        cout<<"Linked list is not palindrome\n";
    }
    return 0;
}
