#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node * next;
};

int main()
{
	struct node *head,*ptr,*ptr1;
	int data,ch=1;
	head=NULL;
	ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next=NULL;
    cout<<"Enter data : ";
    cin>>data;
    ptr->data=data;
    head = ptr;
	cout<<"Insert more nodes: ";
	cin>>ch;
	while(ch)
    {
        ptr1 = (struct node *)malloc(sizeof(struct node));
        cout<<"Enter data : ";
        cin>>data;
        ptr1->data=data;
        ptr1->next=ptr;
        ptr=ptr1;
        cout<<"Insert more nodes: ";
        cin>>ch;
    }
    head=ptr1;
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<(ptr->data)<<" ";
        ptr=ptr->next;
    }
	return 0;
}
