#include<stdio.h>
#include<stdlib.h>

//merge two unsorted stack into single stack in sorted order
struct node
{
    int data;
    struct node * next;
};

void push(struct node **head,int data)
{
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next=*head;
    *head = newNode;
}

void pop(struct node**head)
{
    if((*head)==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct node *ptr = *head;
        *head = (*head)->next;
        free(ptr);
    }
}

int top(struct node **head)
{
    return (*head)->data;
}

int isEmpty(struct node **head)
{
    if(*head==NULL)
        return 1;
    return 0;
}

void display(struct node *head)
{
    printf("Stack is ");
    struct node * ptr = head;
    if(head==NULL)
    {
        printf("empty.\n");
        return;
    }
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

/* One method can be to sort both stacks first using stack then merge like merging two sorted linked list */
/* Second method can be to insert into 3rd stack directly in sorted manner */
void merge_stack(struct node *head1, struct node *head2)
{
    int val;
    struct node *head = NULL;
    while(!isEmpty(&head1))
    {
        val = top(&head1);
        pop(&head1);
        if(isEmpty(&head) || top(&head)<=val)
        {
            push(&head,val);
        }
        else
        {
            while(!isEmpty(&head) && top(&head)>val)
            {
                push(&head1,top(&head));
                pop(&head);
            }
            push(&head,val);
        }
    }
    while(!isEmpty(&head2))
    {
        val = top(&head2);
        pop(&head2);
        if(isEmpty(&head) || top(&head)<=val)
        {
            push(&head,val);
        }
        else
        {
            while(!isEmpty(&head) && top(&head)>val)
            {
                push(&head2,top(&head));
                pop(&head);
            }
            push(&head,val);
        }
    }

    printf("Merged Sorted ");
    display(head);
}

int main()
{
    struct node *head1,*head2;
    head1=NULL;
    head2=NULL;
    int ch=1,d,data,val;
    printf("Enter 1st stack : \n");
    while(ch)
    {
        printf("Select option 1.Push  2.Stop : ");
        scanf("%d",&d);
        if(d==1)
        {
            printf("Enter value : ");
            scanf("%d",&data);
            push(&head1,data);
        }
        else if(d==2)
        {
            break;
        }
        else
        {
            printf("Wrong Choice\n");
        }
    }
    printf("\nEnter 2nd stack : \n");
    ch=1;
    while(ch)
    {
        printf("Select option 1.Push  2.Stop : ");
        scanf("%d",&d);
        if(d==1)
        {
            printf("Enter value : ");
            scanf("%d",&data);
            push(&head2,data);
        }
        else if(d==2)
        {
            break;
        }
        else
        {
            printf("Wrong Choice\n");
        }
    }

    printf("\n1st ");
    display(head1);
    printf("2nd ");
    display(head2);

    merge_stack(head1,head2);
    return 0;
}
