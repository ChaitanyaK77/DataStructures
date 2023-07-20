/*
Experiment 6(a)
Chaitanya Kakade
Roll No.-2104076
Batch - C21
AIM: Write a menu driven code to implement Singly Linked List
*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void InsertAtBeg();
void InsertAtEnd();
void InsertBefore();
void InsertAt();
void DeleteAtBeg();
void DeleteAtEnd();
void display();
void nodecount();
void sortnode();
void search();
void forwardTraverse();
void DelAfter();
int revTrav(struct node *head);
int main()
{
    int choice;
    int x1;

    head = (struct node *)malloc(sizeof(struct node));
    head = NULL;
    do
    {
        printf("----------MAIN MENU----------\n");
        printf("Enter 1 to Insert at beginning\n");
        printf("Enter 2 to Insert at end\n");
        printf("Enter 3 to Insert before a node\n");
        printf("Enter 4 to Insert at a specific position\n");
        printf("Enter 5to Delete at beginning\n");
        printf("Enter 6 to Delete at end\n");
        printf("Enter 7 to Delete after a specific node\n");
        printf("Enter 8 to Delete at a specific position\n");
        printf("Enter 9 for forward traversal\n");
        printf("Enter 10 for reverse traversal\n");
        printf("Enter 11 to count total nodes present\n");
        display();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            InsertAtBeg();
            display();
            break;
        case 2:
            InsertAtEnd();
            display();
            break;
        case 3:
            InsertBefore();
            display();
        case 4:
            InsertAt();
            display();
            break;
        case 5:
            DeleteAtBeg();
            display();
        case 6:
            DeleteAtEnd();
            display();
        case 7:
            DelAfter();
            display();
            break;
        case 9:
            forwardTraverse();
            break;
        case 10:
            revTrav(head);
            break;
        case 11:
            nodecount();
            break;
        }
    } while (1);

    printf("Existing linked list is as follows:\n");

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp = head;
    while (temp != NULL)
    {
        printf("%d---->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    return (0);
}

void InsertAtBeg()
{
    int val;
    printf("Enter the value to be inserted at beginning:\n");
    scanf("%d", &val);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}
void InsertAtEnd()

{
    int val;
    printf("Enter the value to be inserted at the end\n");
    scanf("%d", &val);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp = head;
    newnode->data = val;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
}
void InsertBefore()
{
    int pos, val;
    printf("Enter the position before which you want to insert the element\n");
    scanf("%d", &pos);
    printf("Enter the value you would like to insert\n");
    scanf("%d", &val);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;

    temp = head;
    // Logic to insert before a node:
    while (temp->next->data != pos)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}
void InsertAt()
{
    int pos, val;
    printf("Enter the position where you would like to insert the node:\n");
    scanf("%d", &pos);
    printf("Enter the value you would like to insert:\n");
    scanf("%d", &val);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    temp = head;

    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        for (int i = 1; i <= pos - 2; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void display()
{

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
        printf("List is empty\n");
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d------>", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}
void DeleteAtBeg()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void DeleteAtEnd()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    struct node *temp1;
    temp1 = (struct node *)malloc(sizeof(struct node));
    struct node *temp2;
    temp2 = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
        printf("List is empty\n");
    else if (head->next == NULL)
    {
        temp = head;
        head = NULL;
        free(temp);
    }
    else
    {
        temp1 = temp2 = head;
        while (temp1->next != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        free(temp1);
        temp2->next = NULL;
    }
}
void forwardTraverse()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    int i = 1;
    while (temp != NULL)
    {
        printf("%d element = %d\n", i, temp->data);
        i++;
        temp = temp->next;
    }
}
int revTrav(struct node *head)
{
    if (head == NULL)
    {
        return (0);
    }
    else
    {
        revTrav(head->next);
        printf("%d\t", head->data);
        return (0);
    }
}
void DelAfter()
{
    int number;
    printf("Enter number in linked list to delete after it:\n");
    scanf("%d", &number);

    struct node *temp1;
    temp1 = (struct node *)malloc(sizeof(struct node));
    struct node *temp2;
    temp2 = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Underflow\n");
    }
    else
    {

        temp1 = temp2 = head;
        while (temp1->data != number)
        {
            temp1 = temp2;
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        free(temp2);
    }
}
void nodecount()
{
    int count = 1;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    if (head == NULL)
        printf("Zero nodes present\n");
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }
        printf("Total number of nodes present in the existing linked list is %d\n", count);
    }
}
