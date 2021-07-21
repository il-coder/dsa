#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node * next;
};

void insert_end(struct node **h,int data)
{
	struct node * ptr1 = (struct node *)malloc(sizeof(struct node));
	struct node * ptr = *h;
	ptr1->data = data;
	if(*h==NULL)
	{
		*h = ptr1;
	}
	else
	{
		while(ptr->next!=*h)
		{
			ptr = ptr->next;
		}
		ptr->next = ptr1;
	}
	ptr1->next=*h;
}

void delete_beg(struct node **h)
{
    struct node * ptr = *h;
    if(*h==NULL)
    {
        cout<<"Linked list is empty.\n";
        return;
    }
    else if(ptr->next==*h)
    {
        free(ptr);
        *h = NULL;
        return;
    }
    while(ptr->next != *h)
    {
        ptr = ptr->next;
    }
    ptr->next = (*h)->next;
    ptr = *h;
    *h = (*h)->next;
    free(ptr);
}

void delete_pos(struct node **h, int pos)
{
    if(pos==1)
    {
        delete_beg(h);
    }
    else
    {
        int cnt=1;
        struct node *ptr = *h,*temp;
        temp = ptr->next;
        while(cnt<pos-1)
        {
            cnt++;
            ptr = ptr->next;
            temp = ptr->next;
            if(temp==*h)
            {
                cout<<"Invalid Position\n";
                return;
            }
        }
        if(temp==*h)
        {
            cout<<"Invalid Position\n";
            return;
        }
        ptr->next = ptr->next->next;
        free(temp);
    }
}

void printLL(struct node *h)
{
    cout<<"Linked List is ";
	struct node * ptr = h;
	if(h==NULL)
    {
        cout<<"empty.\n";
        return;
    }
	while(ptr->next!=h)
	{
		cout<<ptr->data<<"->";
		ptr = ptr->next;
	}
	cout<<ptr->data;
	cout<<endl;
}

int main()
{
	struct node *head;
	head=NULL;
	int ch=1,d,data,val;
	while(ch)
    {
        cout<<"Enter type 1.Insert 2.Delete(beginning)  3.Delete(position): ";
        cin>>d;
        if(d==1)
        {
            cout<<"Enter value : ";
            cin>>data;
            insert_end(&head,data);
            printLL(head);
        }
        else if(d==2)
        {
            delete_beg(&head);
            printLL(head);
        }
        else if(d==3)
        {
            cout<<"Enter position : ";
            cin>>data;
            delete_pos(&head,data);
            printLL(head);
        }
        else
        {
            cout<<"Wrong Choice\n";
        }
        cout<<"Enter more nodes : ";
        cin>>ch;
    }
	return 0;
}
