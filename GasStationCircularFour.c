#include <stdio.h>

int canCompleteCircuit(int gas[], int cost[], int n) {

    int total = 0, curr = 0, start = 0;

    for (int i = 0; i < n; i++) {

        int diff = gas[i] - cost[i];
        total += diff;
        curr += diff;

        if (curr < 0) {
            start = i + 1;
            curr = 0;
        }
    }

    return (total >= 0) ? start : -1;
}

int main() {

    int gas[]  = {1,2,3,4,5};
    int cost[] = {3,4,5,1,2};
    int n = 5;

    printf("Start Index: %d\n",
           canCompleteCircuit(gas, cost, n));

    return 0;
}