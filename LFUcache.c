#include <stdio.h>

#define SIZE 100

struct Node {
    int key, value, freq;
};

struct Node cache[SIZE];
int count = 0;
int capacity = 2;

int get(int key) {

    for (int i = 0; i < count; i++) {

        if (cache[i].key == key) {
            cache[i].freq++;
            return cache[i].value;
        }
    }

    return -1;
}

void put(int key, int value) {

    for (int i = 0; i < count; i++) {

        if (cache[i].key == key) {
            cache[i].value = value;
            cache[i].freq++;
            return;
        }
    }

    if (count < capacity) {

        cache[count].key = key;
        cache[count].value = value;
        cache[count].freq = 1;
        count++;
    }
    else {

        int minFreq = cache[0].freq;
        int idx = 0;

        for (int i = 1; i < count; i++) {
            if (cache[i].freq < minFreq) {
                minFreq = cache[i].freq;
                idx = i;
            }
        }

        cache[idx].key = key;
        cache[idx].value = value;
        cache[idx].freq = 1;
    }
}

int main() {

    put(1,10);
    put(2,20);

    printf("%d\n", get(1));

    put(3,30);

    printf("%d\n", get(2));

    return 0;
}