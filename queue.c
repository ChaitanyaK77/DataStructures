/*
AIM:Write a menu driven program to implement QUEUE ADT using arrays.
Name:Chaitanya Kakade
Roll NO.:2104076
Batch:C21
*/

#include <stdio.h>
#define MAX 10
int Queue[MAX], FRONT = -1, REAR = -1;

void Enqueue();
void Dequeue();
void Get_Front();
void Get_Rear();
void Size();
void Display();
int is_Empty();
int is_Full();

int main()
{
    int choice;
    printf("A 'C' program that implements linear Queue\n");

    do
    {
        printf("\nEnter 1 to perform Enqueue operation\n");
        printf("Enter 2 to perform Dequeue operation\n");
        printf("Enter 3 to get Front value of queue\n");
        printf("Enter 4 to get Rear value of queue\n");
        printf("Enter 5 to get the current size of the queue\n");
        printf("Enter 6 to display the current linear queue\n");
        printf("Enter 7 to exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Enqueue();
            break;
        case 2:

            Dequeue();
            break;
        case 3:
            Get_Front();
            break;
        case 4:
            Get_Rear();
            break;
        case 5:

            Size();
            break;
        case 6:
            Display();
            break;
        case 7:
            printf("You chose to exit\n\nThank you...\n");
            break;
        default:
            printf("Invalid Choice\n");
        }
    } while (choice != 7);
    return (0);
}

int is_Empty()
{
    if (REAR == -1 && FRONT == -1)
        return (1);
    else
        return (0);
}
int is_Full()
{
    if (REAR == MAX - 1)
        return (1);
    else
        return (0);
}
void Enqueue()
{
    int value;
    printf("Enter the value you would like to insert in the queue\n");
    scanf("%d", &value);

    if (is_Full())
    {
        printf("Queue overflow\n");
    }
    else if (FRONT == -1 && REAR == -1)
    {
        FRONT = REAR = 0;
        Queue[FRONT] = value;
    }

    else
    {

        REAR++;
        Queue[REAR] = value;
    }
}
void Dequeue()
{
    if (is_Empty())
    {
        printf("Queue underflow\n");
        REAR = FRONT = 0;
    }
    else
    {
        FRONT++;
        if (FRONT > REAR)
            FRONT = REAR = -1;
    }
}
void Get_Front()
{
    printf("The Front of queue = %d\n", Queue[FRONT]);
}
void Get_Rear()
{
    printf("The Rear of queue = %d\n", Queue[REAR]);
}
void Size()
{
    printf("The size of the current Queue is %d\n", REAR + 1 - FRONT);
}
void Display()
{
    printf("The current Queue is :");
    for (int i = FRONT; i <= REAR; i++)
    {
        printf("%d  ", Queue[i]);
    }
}
