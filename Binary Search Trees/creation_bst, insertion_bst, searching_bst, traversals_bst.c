#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree *left,*right;
}*root,*newNode;

void create_node(int value)
{
    newNode = (struct tree *)malloc(sizeof(struct tree));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
}

void search_bst(struct tree *ptr)
{
    if(newNode->data < ptr->data && ptr->left==NULL)
    {
        ptr->left = newNode;
    }
    else if(newNode->data < ptr->data && ptr->left!=NULL)
    {
        search_bst(ptr->left);
    }
    else if(newNode->data > ptr->data && ptr->right==NULL)
    {
        ptr->right = newNode;
    }
    else if(newNode->data > ptr->data && ptr->right!=NULL)
    {
        search_bst(ptr->right);
    }
}

void insert_bst()
{
    if(root==NULL)
    {
        root = newNode;
    }
    else
    {
        search_bst(root);
    }
}

void preOrder(struct tree * ptr)
{
    if(ptr==NULL)
        return;
    printf("%d ",ptr->data);
    preOrder(ptr->left);
    preOrder(ptr->right);
}

void inOrder(struct tree * ptr)
{
    if(ptr==NULL)
        return;
    inOrder(ptr->left);
    printf("%d ",ptr->data);
    inOrder(ptr->right);
}

void postOrder(struct tree * ptr)
{
    if(ptr==NULL)
        return;
    postOrder(ptr->left);
    postOrder(ptr->right);
    printf("%d ",ptr->data);
}

int main()
{
    int n,i;
    int val;
    root=NULL;
    printf("Enter number of values : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&val);
        create_node(val);
        insert_bst();
    }

    printf("\n\n");

    printf("Pre-order traversal : ");
    preOrder(root);
    printf("\n");

    printf("In-order traversal : ");
    inOrder(root);
    printf("\n");

    printf("Post-order traversal : ");
    postOrder(root);
    printf("\n");

    scanf(" ");
	return 0;
}
