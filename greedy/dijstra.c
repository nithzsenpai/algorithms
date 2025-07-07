#include <stdio.h>
#define INF 9999

void dijkstra(int n, int cost[10][10], int src) {
    int dis[10], vis[10] = {0};
    int i, j, u, min;

    for (i = 0; i < n; i++) {
        dis[i] = cost[src][i];
        vis[i] = 0;
    }

    vis[src] = 1;

    for (i = 1; i < n; i++) {
        min = INF;
        for (j = 0; j < n; j++) {
            if (!vis[j] && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }

        vis[u] = 1;

        for (j = 0; j < n; j++) {
            if (!vis[j] && dis[u] + cost[u][j] < dis[j]) {
                dis[j] = dis[u] + cost[u][j];
            }
        }
    }

    printf("\nShortest path from vertex %d:\n", src);
    for (i = 0; i < n; i++) {
        if (dis[i] == INF)
            printf("%d -> %d = Unreachable\n", src, i);
        else
            printf("%d -> %d = %d\n", src, i, dis[i]);
    }
}

int main() {
    int cost[10][10], n, src;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 9999 for no connection):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(n, cost, src);

    return 0;
}
