#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 262147

typedef struct {
    unsigned int key;
    int index;
    int used;
} HashEntry;

HashEntry table[HASH_SIZE];

unsigned int hashFunction(unsigned int x) {

    x ^= x >> 16;
    x *= 0x7feb352d;
    x ^= x >> 15;
    x *= 0x846ca68b;
    x ^= x >> 16;

    return x % HASH_SIZE;
}

/*
 * Return the earliest index at which key
 * occurred.
 *
 * Returns -1 if it doesn't exist.
 */
int getIndex(unsigned int key) {

    unsigned int pos =
        hashFunction(key);

    while (table[pos].used) {

        if (table[pos].key == key)
            return table[pos].index;

        pos = (pos + 1) % HASH_SIZE;
    }

    return -1;
}

/*
 * Insert only if the key doesn't already exist.
 *
 * We want the EARLIEST occurrence.
 */
void insert(unsigned int key, int index) {

    unsigned int pos =
        hashFunction(key);

    while (table[pos].used) {

        if (table[pos].key == key)
            return;

        pos = (pos + 1) % HASH_SIZE;
    }

    table[pos].used = 1;
    table[pos].key = key;
    table[pos].index = index;
}

int main() {

    int n;
    unsigned int k;

    scanf("%d %u", &n, &k);

    /*
     * Prefix XOR = 0 occurs before the array
     * starts, at index 0.
     */
    insert(0, 0);

    unsigned int prefix = 0;

    int longest = 0;

    for (int i = 1; i <= n; i++) {

        unsigned int x;

        scanf("%u", &x);

        prefix ^= x;

        /*
         * We need:
         *
         * oldPrefix XOR prefix = K
         *
         * Therefore:
         *
         * oldPrefix = prefix XOR K
         */
        unsigned int required =
            prefix ^ k;

        int start =
            getIndex(required);

        if (start != -1) {

            int length =
                i - start;

            if (length > longest)
                longest = length;
        }

        /*
         * Store the earliest occurrence only.
         */
        insert(prefix, i);
    }

    if (longest == 0)
        printf("-1\n");
    else
        printf("%d\n", longest);

    return 0;
}