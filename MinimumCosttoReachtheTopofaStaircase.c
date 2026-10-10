#include <stdio.h>

int min(int a, int b) {

    if (a < b) {
        return a;
    }

    return b;
}

int minCostClimbingStairs(int cost[], int n) {

    if (n == 1) {
        return cost[0];
    }

    int previous2 = cost[0];
    int previous1 = cost[1];

    for (int i = 2; i < n; i++) {

        int current =
            cost[i] + min(previous1, previous2);

        previous2 = previous1;
        previous1 = current;
    }

    // We can reach the top from either
    // of the final two stairs.
    return min(previous1, previous2);
}

int main() {

    int cost[] = {
        1, 100, 1, 1, 1,
        100, 1, 1, 100, 1
    };

    int n = sizeof(cost) / sizeof(cost[0]);

    int result = minCostClimbingStairs(cost, n);

    printf("Minimum cost: %d\n", result);

    return 0;
}