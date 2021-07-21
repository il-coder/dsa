#include<stdio.h>
#include<stdlib.h>

//check whether two stacks are same or not
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

void check_same(struct node *head1, struct node *head2,int cnt1, int cnt2)
{
    if(cnt1==cnt2)
    {
        while(!isEmpty(&head1) && !isEmpty(&head2) && top(&head1)==top(&head2))
        {
            pop(&head1);
            pop(&head2);
        }
        if(isEmpty(&head1) && isEmpty(&head2))
        {
            printf("Stacks are SAME.\n");
        }
        else
        {
            printf("Stack are not SAME.\n");
        }
        return;
    }
    printf("Stack are not SAME.\n");
}

int main()
{
    struct node *head1,*head2;
    head1=NULL;
    head2=NULL;
    int ch=1,d,data,val,cnt1=0,cnt2=0;
    printf("Enter 1st stack : \n");
    while(ch)
    {
        printf("Select option 1.Push  2.Stop : ");
        scanf("%d",&d);
        if(d==1)
        {
            printf("Enter value : ");
            scanf("%d",&data);
            cnt1++;
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
            cnt2++;
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

    check_same(head1,head2,cnt1,cnt2);
    return 0;
}
