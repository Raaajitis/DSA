#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 262147

typedef long long ll;

typedef struct {
    ll key;
    int frequency;
    int used;
} Entry;

Entry table[HASH_SIZE];

unsigned int hashFunction(ll x) {

    unsigned long long h =
        (unsigned long long)x;

    h ^= h >> 33;
    h *= 0xff51afd7ed558ccdULL;
    h ^= h >> 33;

    return (unsigned int)(h % HASH_SIZE);
}

int findIndex(ll key) {

    unsigned int pos =
        hashFunction(key);

    while (table[pos].used) {

        if (table[pos].key == key)
            return pos;

        pos = (pos + 1) % HASH_SIZE;
    }

    return -1;
}

int getFrequency(ll key) {

    int index = findIndex(key);

    if (index == -1)
        return 0;

    return table[index].frequency;
}

void add(ll key) {

    unsigned int pos =
        hashFunction(key);

    while (table[pos].used) {

        if (table[pos].key == key) {
            table[pos].frequency++;
            return;
        }

        pos = (pos + 1) % HASH_SIZE;
    }

    table[pos].used = 1;
    table[pos].key = key;
    table[pos].frequency = 1;
}

void removeValue(ll key) {

    int index = findIndex(key);

    if (index != -1)
        table[index].frequency--;
}

int main() {

    int n, k;

    scanf("%d %d", &n, &k);

    ll *a =
        malloc(n * sizeof(ll));

    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);

    int left = 0;
    int distinct = 0;

    ll answer = 0;

    for (int right = 0; right < n; right++) {

        /*
         * If this value wasn't already present,
         * it introduces a new distinct value.
         */
        if (getFrequency(a[right]) == 0)
            distinct++;

        add(a[right]);

        /*
         * Shrink the window until it has
         * at most K distinct values.
         */
        while (distinct > k) {

            removeValue(a[left]);

            if (getFrequency(a[left]) == 0)
                distinct--;

            left++;
        }

        /*
         * Every subarray ending at 'right'
         * and beginning between left and right
         * is valid.
         */
        answer += right - left + 1;
    }

    printf("%lld\n", answer);

    free(a);

    return 0;
}