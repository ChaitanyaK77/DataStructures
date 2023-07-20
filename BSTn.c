#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *root;

struct node *Insert(struct node *root, int val);
void create(struct node *);
void inorder(struct node *root);
void postorder(struct node *root);
void preorder(struct node *root);

int main()
{
    int val, val1, val2;
    root = (struct node *)malloc(sizeof(struct node));
    create(root);

    printf("Enter value:");
    scanf("%d", &val);
    printf("Enter value:");
    scanf("%d", &val1);
    printf("Enter value:");
    scanf("%d", &val2);
    Insert(root, val2);
    preorder(root);

    return (0);
}
struct node *Insert(struct node *root, int val)
{
    struct node *ptr, *parentptr, *nodeptr;
    ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = val;
    ptr->right = NULL;
    ptr->left = NULL;
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
        if (val < parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    return root;
}
void create(struct node *root)
{
    root = NULL;
}
void preorder(struct node *root)
{
    if (root == NULL)
        return;

    preorder(root->left);
    preorder(root->right);
    printf("%d", root->data);
}
