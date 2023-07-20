#include <stdio.h>
int G[10][10], v[10], n;

void DFS(int);
int main()
{
    printf("Vertices \n");
    scanf("%d", &n);
    printf("Enter adjacency matrix:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }
    DFS(0);
}
void DFS(int i)
{
    int j;
    printf("%d\n", i);
    v[i] = 1;
    for (j = 0; j < n; j++)
    {
        if (!v[j] && G[i][j] == 1)
            DFS(j);
    }
}