#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int child[2];
} TrieNode;

void insertNumber(
    TrieNode *trie,
    int *nodeCount,
    unsigned int number
) {
    int current = 0;

    for (int bit = 30; bit >= 0; bit--) {
        int value = (number >> bit) & 1U;

        if (trie[current].child[value] == -1) {
            int newNode = (*nodeCount)++;

            trie[newNode].child[0] = -1;
            trie[newNode].child[1] = -1;

            trie[current].child[value] = newNode;
        }

        current = trie[current].child[value];
    }
}

unsigned int findBestXor(
    const TrieNode *trie,
    unsigned int number
) {
    int current = 0;
    unsigned int result = 0;

    for (int bit = 30; bit >= 0; bit--) {
        int value = (number >> bit) & 1U;
        int preferred = 1 - value;

        if (trie[current].child[preferred] != -1) {
            result |= 1U << bit;
            current = trie[current].child[preferred];
        } else {
            current = trie[current].child[value];
        }
    }

    return result;
}

int main(void) {
    int n;
    scanf("%d", &n);

    unsigned int *array =
        malloc(n * sizeof(unsigned int));

    for (int i = 0; i < n; i++) {
        scanf("%u", &array[i]);
    }

    int maximumNodes = 31 * n + 1;

    TrieNode *trie =
        malloc(maximumNodes * sizeof(TrieNode));

    trie[0].child[0] = -1;
    trie[0].child[1] = -1;

    int nodeCount = 1;
    unsigned int answer = 0;

    insertNumber(trie, &nodeCount, array[0]);

    for (int i = 1; i < n; i++) {
        unsigned int currentXor =
            findBestXor(trie, array[i]);

        if (currentXor > answer) {
            answer = currentXor;
        }

        insertNumber(trie, &nodeCount, array[i]);
    }

    printf("%u\n", answer);

    free(array);
    free(trie);

    return 0;
}