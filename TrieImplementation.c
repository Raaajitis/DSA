#include <stdio.h>
#include <stdlib.h>

#define ALPHABET 26

struct TrieNode {
    struct TrieNode* children[ALPHABET];
    int isEnd;
};

struct TrieNode* createNode() {

    struct TrieNode* node =
        (struct TrieNode*)malloc(sizeof(struct TrieNode));

    node->isEnd = 0;

    for (int i = 0; i < ALPHABET; i++)
        node->children[i] = NULL;

    return node;
}

void insert(struct TrieNode* root, char* word) {

    struct TrieNode* curr = root;

    for (int i = 0; word[i]; i++) {

        int idx = word[i] - 'a';

        if (!curr->children[idx])
            curr->children[idx] = createNode();

        curr = curr->children[idx];
    }

    curr->isEnd = 1;
}

int search(struct TrieNode* root, char* word) {

    struct TrieNode* curr = root;

    for (int i = 0; word[i]; i++) {

        int idx = word[i] - 'a';

        if (!curr->children[idx])
            return 0;

        curr = curr->children[idx];
    }

    return curr->isEnd;
}

int main() {

    struct TrieNode* root = createNode();

    insert(root, "apple");

    printf("%d\n", search(root,"apple"));
    printf("%d\n", search(root,"app"));

    return 0;
}