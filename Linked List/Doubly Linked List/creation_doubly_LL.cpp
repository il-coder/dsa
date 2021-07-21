#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *prev,*next;
};

int main()
{
    struct node * head = NULL,*ptr1,*ptr;
    int data,ch=1,d;
    while(ch)
    {
        cout<<"Enter data : ";
        cin>>data;
        ptr1 = (struct node *)malloc(sizeof(struct node));
        ptr1->data = data;
        ptr1->next = NULL;
        if(head==NULL)
        {
            head = ptr1;
            ptr1->prev = NULL;
        }
        else
        {
            ptr->next = ptr1;
            ptr1->prev = ptr;
        }
        ptr=ptr1;
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
