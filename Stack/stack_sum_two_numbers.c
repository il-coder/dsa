#include<stdio.h>
#include<stdlib.h>

//sum 2 numbers represented in stack
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

void merge_stack(struct node *head1, struct node *head2)
{
    int carry=0,val;
    struct node *head = NULL;
    while(!isEmpty(&head1) && !isEmpty(&head2))
    {
        val = top(&head1) + top(&head2) + carry;
        pop(&head1);
        pop(&head2);
        push(&head,val%10);
        carry = val/10;
    }
    while(!isEmpty(&head1))
    {
        val = top(&head1) + carry;
        pop(&head1);
        push(&head,val%10);
        carry = val/10;
    }
    while(!isEmpty(&head2))
    {
        val = top(&head2) + carry;
        pop(&head2);
        push(&head,val%10);
        carry = val/10;
    }
    if(carry)
    {
        push(&head,carry);
    }

    printf("Sum (MSB top) ");
    display(head);

    while(!isEmpty(&head))
    {
        push(&head1,top(&head));
        pop(&head);
    }
    printf("Sum (MSB bottom) ");
    display(head1);
}

int main()
{
    struct node *head1,*head2;
    head1=NULL;
    head2=NULL;
    int ch=1,d,data,val;
    printf("Enter 1st number stack : \n");
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
    printf("\nEnter 2nd number stack : \n");
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

    printf("\n1st number ");
    display(head1);
    printf("2nd number ");
    display(head2);

    merge_stack(head1,head2);
    return 0;
}
