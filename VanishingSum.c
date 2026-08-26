#include <stdio.h>

#define HASH_SIZE 262147

typedef long long ll;

typedef struct {
    ll key;
    int index;
    int used;
} Entry;

Entry table[HASH_SIZE];

unsigned int hashFunction(ll x) {
    unsigned long long h = (unsigned long long)x;

    h ^= h >> 33;
    h *= 0xff51afd7ed558ccdULL;
    h ^= h >> 33;

    return (unsigned int)(h % HASH_SIZE);
}

int getIndex(ll key) {

    unsigned int pos = hashFunction(key);

    while (table[pos].used) {

        if (table[pos].key == key)
            return table[pos].index;

        pos = (pos + 1) % HASH_SIZE;
    }

    return -1;
}

void insert(ll key, int index) {

    unsigned int pos = hashFunction(key);

    while (table[pos].used) {

        /*
         * Keep the earliest occurrence.
         */
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
    scanf("%d", &n);

    /*
     * Prefix sum 0 occurs before the array.
     */
    insert(0, 0);

    ll prefix = 0;
    int longest = 0;

    for (int i = 1; i <= n; i++) {

        ll x;
        scanf("%lld", &x);

        prefix += x;

        int previous = getIndex(prefix);

        if (previous != -1) {

            int length = i - previous;

            if (length > longest)
                longest = length;
        }

        /*
         * Only the first occurrence is useful.
         */
        insert(prefix, i);
    }

    if (longest == 0)
        printf("-1\n");
    else
        printf("%d\n", longest);

    return 0;
}