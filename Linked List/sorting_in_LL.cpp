#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node * next;
};

void insert_end(struct node **r,struct node **h,int data)
{
	struct node * ptr1 = (struct node *)malloc(sizeof(struct node));
	ptr1->data = data;
	ptr1->next=NULL;
    if(*h==NULL)
    {
        *h = ptr1;
    }
    else
    {
        (*r)->next = ptr1;
    }
	*r = ptr1;
}

void sortLL(struct node * h)
{
    struct node* ptr,*ptr1,*temp;
    ptr=h;
    ptr1=h;
    while(ptr!=NULL)
    {
        ptr1=ptr;
        temp = ptr;
        while(ptr1!=NULL)
        {
            if(temp->data > ptr1->data)
            {
                temp = ptr1;
            }
            ptr1=ptr1->next;
        }

        int t= ptr->data;
        ptr->data = temp->data;
        temp->data = t;

        ptr=ptr->next;
    }
}

void printLL(struct node *h)
{
    cout<<"Queue is ";
	struct node * ptr = h;
	if(h==NULL)
    {
        cout<<"empty.\n";
        return;
    }
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

int main()
{
	struct node *head,*rear;
	head = NULL;
	rear = NULL;
	int ch=1,d,data,val;
	while(ch)
    {
        cout<<"Enter type 1.Insert  2. Display : ";
        cin>>d;
        if(d==1)
        {
            cout<<"Enter value : ";
            cin>>data;
            insert_end(&rear,&head,data);
        }
        else if(d==2)
        {
            printLL(head);
        }
        else
        {
            cout<<"Wrong Choice\n";
        }
        cout<<"Perform more operations : ";
        cin>>ch;
    }
    sortLL(head);
    printLL(head);
	return 0;
}
