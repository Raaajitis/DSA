#include <stdio.h>

#define SIZE 100

int cache[SIZE];
int used[SIZE];
int capacity = 3;

void init() {
    for (int i = 0; i < SIZE; i++) {
        cache[i] = -1;
        used[i] = 0;
    }
}

int get(int key) {
    if (cache[key] == -1)
        return -1;

    used[key]++; // mark recently used
    return cache[key];
}

void put(int key, int value) {

    if (cache[key] != -1) {
        cache[key] = value;
        used[key]++;
        return;
    }

    int lru = -1, minUse = 1e9;

    for (int i = 0; i < SIZE; i++) {
        if (cache[i] != -1 && used[i] < minUse) {
            minUse = used[i];
            lru = i;
        }
    }

    if (lru != -1)
        cache[lru] = -1;

    cache[key] = value;
    used[key] = 1;
}

int main() {

    init();

    put(1, 10);
    put(2, 20);
    put(3, 30);

    printf("%d\n", get(1)); // 10

    put(4, 40); // removes least used

    printf("%d\n", get(2)); // may be -1

    return 0;
}