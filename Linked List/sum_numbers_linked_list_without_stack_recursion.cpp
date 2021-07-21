#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node * next;
};

int main()
{
    struct node *head,*head1,*ptr,*ptr1,*next,*prev,*bhead;
    int data,ch=1,cnt1=0,cnt2=0;
    head=NULL;
    head1=NULL;
    /* 1st Number Input begins */
    cout<<"Enter 1st number\n";
    while(ch)
    {
        ptr1 = (struct node *)malloc(sizeof(struct node));
        cout<<"Enter data : ";
        cin>>data;
        cnt1++;
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

    cout<<"1st Number Linked list : ";
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<(ptr->data)<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL\n";
    /* 1st Number Input ends */

    /* 2nd Number Input begins */
    ch=1;
    cout<<"\nEnter 2nd number\n";
    while(ch)
    {
        ptr1 = (struct node *)malloc(sizeof(struct node));
        cout<<"Enter data : ";
        cin>>data;
        cnt2++;
        ptr1->data=data;
        ptr1->next=NULL;
        if(head1==NULL)
        {
            head1 = ptr1;
        }
        else
        {
            ptr->next = ptr1;
        }
        ptr=ptr1;
        cout<<"Insert more nodes: ";
        cin>>ch;
    }

    cout<<"2nd Number Linked list : ";
    ptr=head1;
    while(ptr!=NULL)
    {
        cout<<(ptr->data)<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL\n";
    /* 2nd Number Input ends */

    /* Step 2 : Reverse both Linked List*/
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

    ptr = head1;
    prev = NULL;
    while(ptr!=NULL)
    {
        next = ptr->next;
        ptr->next = prev;   //make current node link to prev node
        prev = ptr;         //make current node prev node
        ptr = next;         //move to next node
    }
    head1=prev;
    /* Step 2 Ends */

    cout<<"\nReversed 1st Number Linked list : ";
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<(ptr->data)<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL\n";

    cout<<"Reversed 2nd Number Linked list : ";
    ptr=head1;
    while(ptr!=NULL)
    {
        cout<<(ptr->data)<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL\n";

    /* Step 3: If 1st number >= 2nd number (in terms of length) then ptr=head, ptr1=head1 else ptr=head1, ptr1=head */
    if(cnt1>=cnt2)
    {
        ptr=head;
        ptr1=head1;
        bhead = head;
    }
    else
    {
        ptr=head1;
        ptr1=head;
        bhead = head1;
    }
    /*Step 3 ends */

    /*Step 4: Traverse both linked lists and keep calculating carry and remainder and at last reverse ans linked list*/
    int carry = 0;
    while(ptr!=NULL)
    {
        ptr->data = (ptr->data + carry);
        if(ptr1!=NULL)
        {
            ptr->data = (ptr->data + ptr1->data);
            ptr1=ptr1->next;
        }
        carry = ptr->data/10;
        ptr->data = ptr->data % 10;
        ptr=ptr->next;
    }
    ptr = bhead;
    prev = NULL;
    while(ptr!=NULL)
    {
        next = ptr->next;
        ptr->next = prev;   //make current node link to prev node
        prev = ptr;         //make current node prev node
        ptr = next;         //move to next node
    }
    bhead=prev;
    if(carry)
    {
        ptr1 = (struct node *)malloc(sizeof(struct node));
        ptr1->data = carry;
        ptr1->next = bhead;
        bhead = ptr1;
    }
    /* Step 4 ends*/

    /*Step 5 Print the result */
    cout<<"\nResultant Number Linked list : ";
    ptr=bhead;
    while(ptr!=NULL)
    {
        cout<<(ptr->data)<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL\n";
    /*Step 5 ends */

    return 0;
}
