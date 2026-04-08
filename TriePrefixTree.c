#include <stdio.h>
#include <stdlib.h>

#define ALPHABET 26

struct Trie {
    struct Trie* children[ALPHABET];
    int isEnd;
};

struct Trie* createNode() {
    struct Trie* node = malloc(sizeof(struct Trie));
    node->isEnd = 0;

    for (int i = 0; i < ALPHABET; i++)
        node->children[i] = NULL;

    return node;
}

void insert(struct Trie* root, char* key) {

    struct Trie* curr = root;

    for (int i = 0; key[i]; i++) {
        int index = key[i] - 'a';

        if (!curr->children[index])
            curr->children[index] = createNode();

        curr = curr->children[index];
    }

    curr->isEnd = 1;
}

int search(struct Trie* root, char* key) {

    struct Trie* curr = root;

    for (int i = 0; key[i]; i++) {
        int index = key[i] - 'a';

        if (!curr->children[index])
            return 0;

        curr = curr->children[index];
    }

    return curr->isEnd;
}

int main() {

    struct Trie* root = createNode();

    insert(root, "hello");

    printf("Search hello: %d\n", search(root, "hello"));
    printf("Search world: %d\n", search(root, "world"));

    return 0;
}