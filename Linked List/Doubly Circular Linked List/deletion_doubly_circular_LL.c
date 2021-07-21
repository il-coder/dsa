#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev,*next;
};

void delete_beg(struct node **head)
{
    if(*head!=NULL)
    {
        struct node *ptr = *head;
        if(ptr->next == *head)
        {
            *head = NULL;
        }
        else
        {
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
            *head = ptr->next;
        }
        free(ptr);
    }
}

void delete_end(struct node **head)
{
    if(*head!=NULL)
    {
        struct node *ptr = *head;
        if(ptr->next == *head)
        {
            *head = NULL;
        }
        else
        {
            ptr=ptr->prev; //go to last node
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
        }
        free(ptr);
    }
}

void delete_pos(struct node **head,int pos)
{
    if(*head!=NULL)
    {
        if(pos==1)
        {
            delete_beg(head);
        }
        else
        {
            struct node *ptr = *head;
            int cnt=1;
            while(cnt!=pos)
            {
                cnt++;
                ptr=ptr->next;
                if(ptr==*head)
                {
                    printf("Invalid position\n");
                    return;
                }
            }
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
        }
    }
}

void display(struct node *head)
{
    struct node *ptr=head;
    printf("Linked list is ");
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
        printf("Select option 1.Delete(beginning)  2.Delete(end)  3.Delete(position)  4.Quit  : ");
        scanf("%d",&d);
        switch(d)
        {
        case 1:
            delete_beg(&head);
            display(head);
            break;
        case 2:
            delete_end(&head);
            display(head);
            break;
        case 3:
            printf("Enter position : ");
            scanf("%d",&pos);
            delete_pos(&head,pos);
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
