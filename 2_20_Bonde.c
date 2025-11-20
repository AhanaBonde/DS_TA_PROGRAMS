#include <stdio.h>

#define MAX 10

int adj[MAX][MAX], n, visited[MAX];
int stack[MAX], top = -1;

void topoDFS(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            topoDFS(i);
    stack[++top] = v;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (int i = 0; i < n; i++)
        if (!visited[i])
            topoDFS(i);

    printf("Topological Order: ");
    while (top >= 0)
        printf("%d ", stack[top--]);
    return 0;
}
