#include <stdio.h>
int main() {
    int cost[10][10], dist[10][10], next[10][10];
    int n, i, j, k, change;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            dist[i][j] = cost[i][j];
            next[i][j] = j;
        }
    }
    do {
        change = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                for(k = 0; k < n; k++) {
                    if(dist[i][j] > cost[i][k] + dist[k][j]) {
                        dist[i][j] = cost[i][k] + dist[k][j];
                        next[i][j] = k;
                        change = 1;
                    }
                }
            }
        }
    } while(change);
    for(i = 0; i < n; i++) {
        printf("\nRouter %d:\n", i + 1);
        for(j = 0; j < n; j++) {
            printf("To %d via %d dist %d\n",
                   j + 1, next[i][j] + 1, dist[i][j]);
        }
    }
    return 0;
}
