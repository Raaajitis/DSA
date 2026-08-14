#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define HASH_SIZE 262147
#define NEGATIVE -1000000000

typedef struct {
    long long key;
    int value;
    int used;
} Entry;

Entry table[HASH_SIZE];

unsigned int hashKey(unsigned int x) {

    x ^= x >> 16;
    x *= 0x7feb352d;
    x ^= x >> 15;
    x *= 0x846ca68b;
    x ^= x >> 16;

    return x;
}

void updateState(unsigned int key, int value) {

    unsigned int pos =
        hashKey(key) % HASH_SIZE;

    while (table[pos].used) {

        if (table[pos].key == key) {

            if (value > table[pos].value)
                table[pos].value = value;

            return;
        }

        pos = (pos + 1) % HASH_SIZE;
    }

    table[pos].used = 1;
    table[pos].key = key;
    table[pos].value = value;
}

int getState(unsigned int key) {

    unsigned int pos =
        hashKey(key) % HASH_SIZE;

    while (table[pos].used) {

        if (table[pos].key == key)
            return table[pos].value;

        pos = (pos + 1) % HASH_SIZE;
    }

    return NEGATIVE;
}

int main() {

    int n;

    scanf("%d", &n);

    unsigned int *a =
        malloc((n + 1) * sizeof(unsigned int));

    a[0] = 0;

    for (int i = 1; i <= n; i++)
        scanf("%u", &a[i]);

    /*
     * Initially:
     *
     * key = 0
     * rooms entered = 0
     */
    updateState(0, 0);

    for (int i = 1; i <= n; i++) {

        /*
         * Save all states that existed before
         * processing this room.
         *
         * We cannot iterate directly over the hash
         * table while inserting new states.
         */
        int currentSize = 0;

        for (int j = 0; j < HASH_SIZE; j++) {
            if (table[j].used)
                currentSize++;
        }

        Entry *states =
            malloc(currentSize * sizeof(Entry));

        int index = 0;

        for (int j = 0; j < HASH_SIZE; j++) {

            if (table[j].used) {
                states[index++] = table[j];
            }
        }

        /*
         * Try entering this room from every
         * possible previous key.
         */
        unsigned int required =
            a[i] ^ a[i - 1];

        for (int j = 0; j < currentSize; j++) {

            unsigned int key = states[j].key;
            int count = states[j].value;

            if (key == required) {

                unsigned int newKey =
                    key ^ a[i];

                updateState(newKey, count + 1);
            }
        }

        free(states);
    }

    int answer = 0;

    for (int i = 0; i < HASH_SIZE; i++) {

        if (table[i].used &&
            table[i].value > answer) {

            answer = table[i].value;
        }
    }

    printf("%d\n", answer);

    free(a);

    return 0;
}