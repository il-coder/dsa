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
        ptr1->next=NULL;
        ptr->next=ptr1;
        ptr=ptr1;
        cout<<"Enter data : ";
        cin>>data;
        ptr1->data=data;
        cout<<"Insert more nodes: ";
        cin>>ch;
    }
    int cnt=0;
    ptr=head;
    while(ptr!=NULL)
    {
        cnt++;
        ptr = ptr->next;
    }
    cout<<"Count of nodes = "<<cnt<<endl;
	return 0;
}
