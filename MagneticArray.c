#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define HASH_SIZE 262147

typedef struct {
    long long key;
    int value;
    int used;
} HashEntry;

HashEntry plusTable[HASH_SIZE];
HashEntry minusTable[HASH_SIZE];

unsigned long long hashFunction(long long x) {

    unsigned long long h = (unsigned long long)x;

    h ^= h >> 33;
    h *= 0xff51afd7ed558ccdULL;
    h ^= h >> 33;
    h *= 0xc4ceb9fe1a85ec53ULL;
    h ^= h >> 33;

    return h;
}

int get(HashEntry table[], long long key) {

    unsigned long long pos =
        hashFunction(key) % HASH_SIZE;

    while (table[pos].used) {

        if (table[pos].key == key)
            return table[pos].value;

        pos = (pos + 1) % HASH_SIZE;
    }

    return 0;
}

void update(HashEntry table[], long long key, int value) {

    unsigned long long pos =
        hashFunction(key) % HASH_SIZE;

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

int main() {

    int n;
    scanf("%d", &n);

    long long answer = 0;

    for (int i = 0; i < n; i++) {

        long long x;
        scanf("%lld", &x);

        long long plusKey = x + i;
        long long minusKey = x - i;

        /*
         * Best sequence that can connect through
         * A[i] + i.
         */
        int bestPlus = get(plusTable, plusKey);

        /*
         * Best sequence that can connect through
         * A[i] - i.
         */
        int bestMinus = get(minusTable, minusKey);

        int current = 1;

        if (bestPlus + 1 > current)
            current = bestPlus + 1;

        if (bestMinus + 1 > current)
            current = bestMinus + 1;

        update(plusTable, plusKey, current);
        update(minusTable, minusKey, current);

        if (current > answer)
            answer = current;
    }

    printf("%lld\n", answer);

    return 0;
}