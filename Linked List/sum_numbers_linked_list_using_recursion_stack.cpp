#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node * next;
};

void same_length(struct node *h1, struct node *h2, int &carry)
{
    if(h1==NULL && h2==NULL)
    {
        return;
    }
    same_length(h1->next,h2->next,carry);
    h1->data = h1->data + h2->data + carry;
    carry = h1->data/10;
    h1->data = h1->data % 10;
}

void more_length(struct node *h1, struct node *last, int &carry)
{
    if(h1==last)
    {
        return;
    }
    more_length(h1->next,last,carry);
    h1->data = h1->data + carry;
    carry = h1->data/10;
    h1->data = h1->data % 10;
}

int main()
{
    struct node *head,*head1,*ptr,*ptr1,*bhead;
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

    /* Step 2 : Check both linked list length. If same then just recur to go to end, then backtrack to get desired output*/
    int carry = 0,t=1,diff;
    if(cnt1==cnt2)
    {
        same_length(head,head1,carry);
        bhead = head;
    }
    /* Step 2 Ends */

    /* Step 3: else if linked lists have different length, then move larger linked list upto point where length becomes equal*/
    else if(cnt1>cnt2)
    {
        ptr=head;
        t=1;
        diff = cnt1-cnt2+1;
        while(t!=diff)
        {
            ptr=ptr->next;
            t++;
        }
        same_length(ptr,head1,carry);
        more_length(head,ptr,carry);
        bhead = head;
    }
    else
    {
        ptr=head1;
        t=1;
        diff = cnt2-cnt1+1;
        while(t!=diff)
        {
            ptr=ptr->next;
            t++;
        }
        same_length(ptr,head,carry);
        more_length(head1,ptr,carry);
        bhead = head1;
    }
    /*Step 3 ends */

    /* Step 4 if carry remains, add it to result */
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
