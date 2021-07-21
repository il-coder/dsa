#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev,*next;
};

void insert_beg(struct node **head,int data)
{
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    if(*head==NULL)
    {
        newNode->prev = NULL;
        newNode->next = newNode;
    }
    else
    {
        newNode->prev = (*head)->prev;
        newNode->next = *head;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insert_end(struct node **head,int data)
{
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    if(*head==NULL)
    {
        newNode->prev = NULL;
        newNode->next = newNode;
        *head = newNode;
    }
    else
    {
        newNode->prev = (*head)->prev;
        newNode->next = *head;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
}

void insert_pos(struct node **head,int data,int pos)
{
    if(pos==1)
    {
        insert_beg(head,data);
    }
    else
    {
        int cnt=1;
        struct node *ptr = *head;
        while(cnt!=pos)
        {
            cnt++;
            ptr=ptr->next;
            if(ptr==*(head))
            {
                printf("Invalid position\n");
                return;
            }
        }
        struct node * newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->prev = ptr->prev;
        newNode->next = ptr;
        ptr->prev->next = newNode;
        ptr->prev= newNode;
    }
}

void display(struct node *head)
{
    struct node *ptr=head;
    printf("Linked list is : ");
    if(head==NULL)
    {
        printf("empty.\n");
        return;
    }
    while(ptr->next!=head)
    {
        printf("%d--",ptr->data);
        ptr=ptr->next;
    }
    printf("%d--HEAD\n",ptr->data);
}

int main()
{
    struct node * head = NULL,*newNode,*ptr;
    int data,ch=1,d,pos;
    while(ch)
    {
        printf("Enter data : ");
        scanf("%d",&data);
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        if(head==NULL)
        {
            head = newNode;
            newNode->prev = NULL;
        }
        else
        {
            ptr->next = newNode;
            head->prev = newNode;
            newNode->prev = ptr;
        }
        newNode->next = head;
        ptr=newNode;
        printf("Enter more nodes : ");
        scanf("%d",&ch);
    }
    head->prev= ptr;
    display(head);

    ch=1;
    while(ch)
    {
        printf("Select option 1.Insert(beginning)  2.Insert(end)  3.Insert(position)  4.Quit  : ");
        scanf("%d",&d);
        switch(d)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d",&data);
            insert_beg(&head,data);
            display(head);
            break;
        case 2:
            printf("Enter data : ");
            scanf("%d",&data);
            insert_end(&head,data);
            display(head);
            break;
        case 3:
            printf("Enter data & position : ");
            scanf("%d%d",&data,&pos);
            insert_pos(&head,data,pos);
            display(head);
            break;
        case 4:
            ch=0;
            break;
        default:
            printf("Wrong Choice\n");
        }
    }
    printf("\nFinal ");
    display(head);
	return 0;
}
