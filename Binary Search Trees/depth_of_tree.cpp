// function should return level of the target node
int getLevel(struct Node *node, int target)
{
    if(node == NULL)
    {
        return 0;
    }
	if(node->data == target)
	{
	    return 1;
	}
	int p = getLevel(node->left,target);
	int q = getLevel(node->right,target);
	if(p==0 && q==0)
	{
	    return 0;
	}
	if(p!=0)
	{
	    return (1 + p);
	}
	return (1+q);
}