#include <stdio.h>
#define MAX 10

int ha[MAX] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

int hash(int key, int i)
{
    int h;
    h = (key % 10 + i) % 10;
    if (ha[h] == -1)
    {
        ha[h] = key;
        return ha[h];
    }
    else
        hash(key, i + 1);
}

int main()
{
    int key, i = 0, n;
    printf("Enter number of values to store: ");
    scanf("%d", &n);
    for (int i = 0; i < MAX; i++)
        printf("%d\t", ha[i]);

    for (int j = 0; j < n; j++)
    {
        printf("\nEnter value: ");
        scanf("%d", &key);
        hash(key, i);
        i = 0;
    }

    for (int i = 0; i < MAX; i++)
        printf("%d\t", ha[i]);

    return 0;
}