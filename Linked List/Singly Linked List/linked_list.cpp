#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node * next;
};

void insert_node(struct node **h,int data)
{
	struct node * ptr1 = (struct node *)malloc(sizeof(struct node));
	struct node * ptr = *h;
	ptr1->data = data;
	ptr1->next=NULL;
	if(*h==NULL)
	{
		*h = ptr1;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = ptr1;
	}
}

void printLL(struct node **h)
{
	struct node * ptr = *h;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

int main()
{
	struct node *head;
	head=NULL;
	insert_node(&head,10);
	insert_node(&head,20);
	insert_node(&head,30);
	insert_node(&head,40);
	printLL(&head);
	return 0;
}
