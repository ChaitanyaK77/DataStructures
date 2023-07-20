#include <stdio.h>
#include <string.h>

#define MAX 15
int Top = -1, Stack[MAX];
int pair(char open, char close);
int paranthesischeck(char exp[]);
void push(char c);
void pop();
int main()
{
    char exp[MAX];
    printf("Enter an expression:");
    gets(exp);
    if (paranthesischeck(exp))
    {
        printf("Expression is balanced\n");
    }
    else
        printf("Expression is not balnaced\n");

    return (0);
}
int pair(char open, char close)
{
    return (((open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']')));
}
int paranthesischeck(char exp[])
{
    int length;
    length = strlen(exp);
    for (int i = 0; i < length; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (Top == -1 || !pair(Stack[Top], exp[i]))
            {
                return 0;
            }

            else
            {
                pop();
            }
        }
    }
    return (Top == -1) ? 1 : 0;
}

void push(char c)
{
    if (Top == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        Top++;
        Stack[Top] = c;
    }
}
void pop()
{
    if (Top == -1)
        printf("Stack underflow");
    else
    {
        Top = Top - 1;
    }
}
