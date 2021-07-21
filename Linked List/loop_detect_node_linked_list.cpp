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
    int data,ch=1,total_nodes=0;
    head=NULL;
    while(ch)
    {
        ptr1 = (struct node *)malloc(sizeof(struct node));
        total_nodes++;
        cout<<"Enter data : ";
        cin>>data;
        ptr1->data=data;
        ptr1->next=NULL;
        if(total_nodes==4)  //for creating loop at 4th position manually for testing
        {
            temp = ptr1;
        }
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
    cout<<temp->data<<"\n";

    ptr1->next = temp;  //creating loop

    //detecting loop using Tortoise and Hare algorithm
    ptr = head;
    if(ptr->next==NULL)
    {
        cout<<"No Loop\n";
    }
    else
    {
        ptr1 = ptr->next;
    }
    while(ptr!=ptr1 && ptr1->next!=NULL && ptr1->next->next!=NULL)
    {
        ptr=ptr->next;
        ptr1=ptr1->next->next;
    }
    if(ptr==ptr1)
    {
        cout<<"Loop found\n";
        temp = ptr;
        int cnt=1;
        ptr=ptr->next;
        while(ptr!=temp)
        {
            ptr=ptr->next;
            cnt++;
        }
        cout<<"Length of loop = "<<cnt<<" and Starting node = "<<(total_nodes-cnt+1)<<"\n";
    }
    else
    {
        cout<<"No Loop\n";
    }
    return 0;
}
