#include <stdio.h>

#define MAX 10

int adj[MAX][MAX], visited[MAX], n;

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            dfs(i);
}

void bfs(int start) {
    int q[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++) visited[i] = 0;
    visited[start] = 1;
    q[rear++] = start;

    while (front < rear) {
        int v = q[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++)
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;
                q[rear++] = i;
            }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("DFS starting from 0: ");
    for (int i = 0; i < n; i++) visited[i] = 0;
    dfs(0);
    printf("\nBFS starting from 0: ");
    bfs(0);
    return 0;
}
