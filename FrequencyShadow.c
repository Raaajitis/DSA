#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define HASH_SIZE 262147

typedef struct {
    int key;
    int freq;
    int used;
} HashEntry;

HashEntry table[HASH_SIZE];

int stack[MAXN];

unsigned int hashFunction(int x) {
    unsigned int h = (unsigned int)x;
    h ^= h >> 16;
    h *= 0x45d9f3b;
    h ^= h >> 16;
    return h % HASH_SIZE;
}

void addFrequency(int value) {

    unsigned int pos = hashFunction(value);

    while (table[pos].used) {

        if (table[pos].key == value) {
            table[pos].freq++;
            return;
        }

        pos = (pos + 1) % HASH_SIZE;
    }

    table[pos].used = 1;
    table[pos].key = value;
    table[pos].freq = 1;
}

int getFrequency(int value) {

    unsigned int pos = hashFunction(value);

    while (table[pos].used) {

        if (table[pos].key == value)
            return table[pos].freq;

        pos = (pos + 1) % HASH_SIZE;
    }

    return 0;
}

int main() {

    int n;
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));
    int *freq = malloc(n * sizeof(int));
    int *answer = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        addFrequency(a[i]);
    }

    /*
     * Stack stores indices.
     *
     * Frequencies on the stack are kept
     * in decreasing order.
     */
    int top = -1;

    for (int i = n - 1; i >= 0; i--) {

        freq[i] = getFrequency(a[i]);

        /*
         * Remove elements whose frequency is
         * not greater than the current frequency.
         */
        while (top >= 0 &&
               freq[stack[top]] <= freq[i]) {

            top--;
        }

        if (top == -1)
            answer[i] = -1;
        else
            answer[i] = stack[top] + 1;

        stack[++top] = i;
    }

    for (int i = 0; i < n; i++) {

        printf("%d", answer[i]);

        if (i + 1 < n)
            printf(" ");
    }

    printf("\n");

    free(a);
    free(freq);
    free(answer);

    return 0;
}