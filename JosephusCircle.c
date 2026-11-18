#include <stdio.h>

int josephus(int n, int k) {

    int survivor = 0;

    for (int size = 2; size <= n; size++) {

        survivor = (survivor + k) % size;
    }

    // Convert from 0-based to 1-based numbering
    return survivor + 1;
}

int main() {

    int n = 7;
    int k = 3;

    int result = josephus(n, k);

    printf("Last surviving person: %d\n", result);

    return 0;
}