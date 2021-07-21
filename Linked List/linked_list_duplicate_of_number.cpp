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
    cout<<"Enter number to search for duplicate: ";
    cin>>ch;
    while(ptr!=NULL)
    {
        if(ptr->data==ch)
            cnt++;
        ptr = ptr->next;
    }
    if(cnt>1)
    {
        cout<<cnt<<" no. of occurences of given number found.\n";
    }
    else
    {
        cout<<"No duplicate found of given number found.\n";
    }
	return 0;
}
