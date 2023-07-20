#include <stdio.h>
#include <ctype.h>
#define SIZE 40

int stack[SIZE], top = -1;
char postfix[SIZE];

void push(int val);
int pop();

int main()
{
    int check, a, b, result, ans;
    printf("Enter a postfix integer expression:\n");
    scanf("%s", postfix);

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        check = postfix[i];

        if (isdigit(check))
        {
            push(check - '0');
        }
        else if (check == '+' || check == '-' || check == '*' || check == '/')
        {
            b = pop();
            a = pop();
            switch (check)
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            default:
                printf("Invalid expression\n");
            }
            push(result);
        }
    }
    ans = pop();
    printf("Answer - %d", ans);
    return (0);
}
void push(int val)
{
    if (top == SIZE - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top = top + 1;
        stack[top] = val;
    }
}
int pop()
{
    if (top == -1)
    {
        return 0;
    }
    else
    {

        return stack[top--];
    }
}