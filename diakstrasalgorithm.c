#include <stdio.h>

#define MAX_NODES 5
#define INFINITY 9999

int cost[MAX_NODES][MAX_NODES];

void findMinimumCostPath(int startNode, int endNode, int numPaths, int paths[][MAX_NODES]) {
    int minCost = INFINITY;
    int minPathIndex = -1;

    for (int i = 0; i < numPaths; i++) {
        int currentCost = 0;

        for (int j = 0; paths[i][j + 1] != 0; j++) {
            int currentNode = paths[i][j];
            int nextNode = paths[i][j + 1];

            currentCost += cost[currentNode][nextNode];
        }

        if (currentCost < minCost) {
            minCost = currentCost;
            minPathIndex = i;
        }
    }

    if (minPathIndex != -1) {
        printf("Minimum cost: %d\n", minCost);
        printf("Minimum cost path: ");
        for (int i = 0; paths[minPathIndex][i] != 0; i++) {
            printf("%d ", paths[minPathIndex][i]);
        }
    } else {
        printf("No valid path found.\n");
    }
}

int main() {
    int numPaths;
    int paths[10][MAX_NODES];
    int startNode = 1;
    int endNode = 5;

    printf("Enter the Cost Matrix:\n");
    for (int i = 1; i <= MAX_NODES; i++) {
        for (int j = 1; j <= MAX_NODES; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter the number of paths: ");
    scanf("%d", &numPaths);

    printf("Enter the possible paths:\n");
    for (int i = 0; i < numPaths; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            scanf("%d", &paths[i][j]);
        }
    }

    findMinimumCostPath(startNode, endNode, numPaths, paths);

    return 0;
}
