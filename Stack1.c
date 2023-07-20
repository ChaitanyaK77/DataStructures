#include <stdio.h>
#define MAX 10
int top = -1;
int Stack[MAX];
void push(int x);
void pop();
void peek(void);
void display();

int main()
{
    int choice, x, num;
    do
    {
        printf("------------MAIN MENU-----------\n");
        printf("Enter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to peek\n");
        printf("Enter 4 to display our stack\n");
        printf("Enter 5 to exit\n");

        scanf("%d", &choice);
        printf("\n\n");

        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed:\n");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            printf("Before popping\n");
            display();
            pop();
            printf("After popping\n");
            display();

            break;
        case 3:
            peek();
            printf("\n");
            break;
        case 4:
            display();
            printf("\n");
            break;
        case 5:
            printf("You chose to exit\n");
            break;

        default:
            printf("Invalid Choice");
        }
    } while (choice != 5);
    return (0);
}

void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        Stack[top] = x;
    }
}
void pop()
{

    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {

        top = top - 1;
    }
}
void peek(void)
{
    if (top == -1)
        printf("Stack underflow\n");
    else
        printf("%d", Stack[top]);
}
void display()
{
    if (top == -1)
        printf("Stack underflow\n");
    else
    {
        printf("Our Stack\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", Stack[i]);
        }
    }
}
