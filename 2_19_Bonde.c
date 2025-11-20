#include <stdio.h>
#include <string.h>

#define MAX 10

int adj[MAX][MAX], n, visited[MAX], disc[MAX], low[MAX], parent[MAX];
int timeCounter = 0, apFound = 0;

void dfs(int u) {
    int children = 0;
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;

    for (int v = 0; v < n; v++) {
        if (adj[u][v]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                dfs(v);
                low[u] = (low[u] < low[v]) ? low[u] : low[v];
                if (parent[u] == -1 && children > 1) apFound = 1;
                if (parent[u] != -1 && low[v] >= disc[u]) apFound = 1;
            } else if (v != parent[u])
                low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
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

    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    dfs(0);

    int allVisited = 1;
    for (int i = 0; i < n; i++)
        if (!visited[i]) allVisited = 0;

    if (allVisited && !apFound)
        printf("Graph is Biconnected\n");
    else
        printf("Graph is NOT Biconnected\n");
    return 0;
}
