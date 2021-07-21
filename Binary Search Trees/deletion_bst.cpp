/ Return the root of the modified BST after deleting the node with value X
// nbd = node to be deleted
// succ = inorder successor
// succ_parent = parent of successor
Node *deleteNode(Node *root,  int X)
{
    if(root==NULL)
    {
        return NULL;
    }
    Node *node = root,*nbd = NULL,*parent=root;
    while(true) //find node in the tree
    {
        if(node==NULL)
        {
            return root;
        }
        else if(node->data == X)
        {
            nbd = node;
            break;
        }
        else if(!node->left && !node->right)
        {
            return root;
        }
        else if(node->data > X)
        {
            parent = node;
            node = node->left;
        }
        else
        {
            parent = node;
            node = node->right;
        }
    }
    
    if(!nbd->left && !nbd->right) //if it's leaf node
    {
        if(nbd == root)
        {
            root = NULL;
        }
        else if(parent->left == nbd)
        {
            parent->left = NULL;
        }
        else if(parent->right == nbd)
        {
            parent->right = NULL; 
        }
    }
    else if(!nbd->left) //single child case
    {
        if(nbd==root)
        {
            root = nbd->right;
        }
        else if(parent->left == nbd)
        {
            parent->left = nbd->right;
        }
        else if(parent->right == nbd)
        {
            parent ->right = nbd->right; 
        }
    }
    else if(!nbd->right)    //single child case
    {
        if(nbd==root)
        {
            root = nbd->left;
        }
        else if(parent->left == nbd)
        {
            parent->left = nbd->left;
        }
        else if(parent->right == nbd)
        {
            parent->right = nbd->left; 
        }
    }
    else    //two child case
    {
        Node *succ = nbd->right, *succ_parent = nbd;
        while(succ->left!=NULL)
        {
            succ_parent = succ;
            succ = succ->left;
        }
        nbd->data = succ->data;
        if(succ_parent == nbd)
        {
            nbd->right = succ->right;
        }
        else
        {
            succ_parent->left = succ->right;
        }
        nbd = succ;
    }
    free(nbd);
    return root;
}