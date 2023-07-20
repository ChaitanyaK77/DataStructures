

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *TOP;
void push();
void pop();
void display();
void peek();
void size();

int main()
{

    TOP = (struct node *)malloc(sizeof(struct node));
    TOP = NULL;
    int choice;
    printf("Stacks Using Linked List Program....\n");
    do
    {
        printf("\nEnter 1 to push an element\n");
        printf("Enter 2 to pop an element\n");
        printf("Enter 3 to perform peek operation\n");
        printf("Enter 4 to know the size of the current stack\n");
        printf("Enter 5 to display stack elements\n");
        printf("Enter 6 to exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            size();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("You chose to exit\n\nThank you....");
            break;
        default:
            printf("Invalid Choice\n");
        }

    } while (choice != 6);

    return (0);
}
void push()
{
    int val;
    printf("Enter the value to be pushed onto the stack\n");
    scanf("%d", &val);

    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;

    if (TOP == NULL)
    {
        new_node->next = NULL;
        TOP = new_node;
    }
    else
    {
        new_node->next = TOP;
        TOP = new_node;
    }
}

void pop()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (TOP == NULL)
    {
        printf("Stack underflow\n");
    }
    else
    {
        ptr = TOP;
        TOP = TOP->next;
        free(ptr);
    }
}
void display()
{

    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp = TOP;
    if (TOP == NULL)
        printf("Stack underflow\n");
    else
    {

        while (temp != NULL)
        {
            printf("%d------>", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}
void size()
{
    int count = 0;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp = TOP;
    if (TOP == NULL)
        printf("Stack underflow\n");
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Total Stack elements = %d\n", count);
}
void peek()
{
    if (TOP == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
        printf("Top of the stack = %d\n", TOP->data);
}
