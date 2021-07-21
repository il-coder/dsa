#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node * next;
};

int main()
{
    struct node *head,*ptr,*ptr1,*next,*prev;
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

    /*  Method 1 : Just print in reverse order using Recursion
        Method 2 : Just insert every node at beginning so that list created is reversed
        Method 3 : Change the link of each node to previous node
    */
    ptr = head;
    prev = NULL;
    while(ptr!=NULL)
    {
        next = ptr->next;
        ptr->next = prev;   //make current node link to prev node
        prev = ptr;         //make current node prev node
        ptr = next;         //move to next node
    }
    head=prev;

    cout<<"Reversed Linked list : ";
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<(ptr->data)<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL\n";
    return 0;
}
