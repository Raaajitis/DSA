#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 26
#define MAX_PREFIX 100

struct TrieNode {
    struct TrieNode *children[ALPHABET];
    int childCount;
    int isEnd;
};

struct TrieNode* createNode() {

    struct TrieNode *node =
        (struct TrieNode*)malloc(sizeof(struct TrieNode));

    node->childCount = 0;
    node->isEnd = 0;

    for (int i = 0; i < ALPHABET; i++) {
        node->children[i] = NULL;
    }

    return node;
}

void insert(struct TrieNode *root, char word[]) {

    struct TrieNode *current = root;

    for (int i = 0; word[i] != '\0'; i++) {

        int index = word[i] - 'a';

        if (current->children[index] == NULL) {

            current->children[index] = createNode();
            current->childCount++;
        }

        current = current->children[index];
    }

    current->isEnd = 1;
}

void longestCommonPrefix(struct TrieNode *root,
                         char prefix[]) {

    struct TrieNode *current = root;

    int length = 0;

    while (current->childCount == 1 &&
           current->isEnd == 0) {

        int childIndex = -1;

        for (int i = 0; i < ALPHABET; i++) {

            if (current->children[i] != NULL) {

                childIndex = i;
                break;
            }
        }

        prefix[length++] = 'a' + childIndex;

        current = current->children[childIndex];
    }

    prefix[length] = '\0';
}

int main() {

    char words[][20] = {
        "flower",
        "flow",
        "flight"
    };

    int n = sizeof(words) / sizeof(words[0]);

    struct TrieNode *root = createNode();

    for (int i = 0; i < n; i++) {
        insert(root, words[i]);
    }

    char prefix[MAX_PREFIX];

    longestCommonPrefix(root, prefix);

    if (strlen(prefix) == 0) {

        printf("No common prefix exists.\n");

    } else {

        printf("Longest common prefix: %s\n", prefix);
    }

    return 0;
}