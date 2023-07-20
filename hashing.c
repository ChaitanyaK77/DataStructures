#include <stdio.h>
#define MAX 10
int Hash[MAX] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int LinearProbing(int key, int i);
int main()
{
    int n, key, i = 0;
    printf("Enter total number of entries to be mapped(less than or equal to 10)");
    scanf("%d", &n);

    for (int k = 0; k < n; k++)
    {
        printf("Enter Value %d  ", k);
        scanf("%d", &key);
        LinearProbing(key, i);
        i = 0;
    }

    for (int k = 0; k < MAX; k++)
    {
        printf("%d ", Hash[k]);
    }
    return (0);
}
int LinearProbing(int key, int i)
{
    int h;
    h = (key % 10 + i) % 10;
    if (Hash[h] == 0)
    {
        Hash[h] = key;
        return Hash[h];
    }
    else
    {
        LinearProbing(key, i + 1);
    }
}
