#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 262147

typedef long long ll;

typedef struct {
    ll key;
    int index;
    int used;
} Entry;

Entry table[HASH_SIZE];

unsigned int hashFunction(ll x) {

    unsigned long long h =
        (unsigned long long)x;

    h ^= h >> 33;
    h *= 0xff51afd7ed558ccdULL;
    h ^= h >> 33;
    h *= 0xc4ceb9fe1a85ec53ULL;
    h ^= h >> 33;

    return (unsigned int)(h % HASH_SIZE);
}

void update(ll key, int index) {

    unsigned int pos = hashFunction(key);

    while (table[pos].used) {

        if (table[pos].key == key) {

            /*
             * Since we process from right to left,
             * the new index is the nearest occurrence.
             */
            table[pos].index = index;
            return;
        }

        pos = (pos + 1) % HASH_SIZE;
    }

    table[pos].used = 1;
    table[pos].key = key;
    table[pos].index = index;
}

int get(ll key) {

    unsigned int pos = hashFunction(key);

    while (table[pos].used) {

        if (table[pos].key == key)
            return table[pos].index;

        pos = (pos + 1) % HASH_SIZE;
    }

    return -1;
}

int main() {

    int n;
    scanf("%d", &n);

    ll *a = malloc(n * sizeof(ll));
    ll *prefix = malloc((n + 1) * sizeof(ll));
    int *answer = malloc(n * sizeof(int));

    prefix[0] = 0;

    for (int i = 0; i < n; i++) {

        scanf("%lld", &a[i]);

        prefix[i + 1] =
            prefix[i] + a[i];
    }

    /*
     * Process prefix indices from right to left.
     *
     * For starting position i, we need the
     * nearest prefix index > i having the
     * same prefix sum.
     */
    for (int i = n - 1; i >= 0; i--) {

        int next = get(prefix[i]);

        if (next == -1)
            answer[i] = -1;
        else
            answer[i] = next;

        /*
         * prefix[i] is now available for positions
         * further to the left.
         */
        update(prefix[i], i);
    }

    for (int i = 0; i < n; i++) {

        printf("%d", answer[i]);

        if (i + 1 < n)
            printf(" ");
    }

    printf("\n");

    free(a);
    free(prefix);
    free(answer);

    return 0;
}