// Infix to Postfix expression program
// Chaitanya Kakade
// Batch :C21
// Roll No, : 2104076
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];

int TOP = -1;
void push(char);
int operator(char);
int precedence(char);
void InfixToPostfix(char inf[], char post[]);
int pop();

int main()
{
    char infix[MAX], postfix[MAX];
    printf("\nEnter Infix expression : ");
    gets(infix);

    InfixToPostfix(infix, postfix);
    printf("Postfix Expression: ");
    puts(postfix);

    return 0;
}
void push(char val)
{
    if (TOP == MAX - 1)
    {
        printf("\nStack Overflow.");
    }
    else
    {
        TOP++;
        stack[TOP] = val;
    }
}
int pop()
{
    char Val;

    if (TOP == -1)
    {
        printf("Stack Underflow");
        return (1);
    }
    else
    {
        Val = stack[TOP];
        TOP--;
        return (Val);
    }
}

int operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char symbol)
{
    if (symbol == '^')
    {
        return (3);
    }
    else if (symbol == '*' || symbol == '/')
    {
        return (2);
    }
    else if (symbol == '+' || symbol == '-')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void InfixToPostfix(char InfixExpr[], char PostfixExpr[])
{
    int i, j;
    char value;
    char x;

    push('(');
    strcat(InfixExpr, ")");

    i = 0;
    j = 0;
    value = InfixExpr[i];

    while (value != '\0')
    {
        if (value == '(')
        {
            push(value);
        }
        else if (isdigit(value) || isalpha(value))
        {
            PostfixExpr[j] = value;
            j++;
        }
        else if (operator(value) == 1)
        {
            x = pop();
            while (operator(x) == 1 && precedence(x) >= precedence(value))
            {
                PostfixExpr[j] = x;
                j++;
                x = pop();
            }
            push(x);

            push(value);
        }
        else if (value == ')')
        {
            x = pop();
            while (x != '(')
            {
                PostfixExpr[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {

            printf("\nInvalid infix Expression.\n");
        }
        i++;

        value = InfixExpr[i];
    }
    if (TOP > 0)
    {
        printf("\nInvalid infix Expression.\n");
        getchar();
        exit(1);
    }
    if (TOP > 0)
    {
        printf("\nInvalid infix Expression.\n");
        getchar();
        exit(1);
    }

    PostfixExpr[j] = '\0';
}
