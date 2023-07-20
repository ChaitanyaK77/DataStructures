struct node *Insert(struct node *root, int val)
{
    struct node *ptr, *parentptr, *nodeptr;
    ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = val;
    ptr->right = NULL;
    ptr->left = NULl;

    if (root == NULL)
    {
        root = ptr;
        root->right = NULL;
        root->left = NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr = root;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;

            if (val < nodeptr->data)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }
        if (val < parentptr->dat)
    }
}