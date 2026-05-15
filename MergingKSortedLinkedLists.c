#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int x) {

    struct Node* n =
        (struct Node*)malloc(sizeof(struct Node));

    n->data = x;
    n->next = NULL;

    return n;
}

struct Node* merge(struct Node* a,
                   struct Node* b) {

    if (!a) return b;
    if (!b) return a;

    struct Node* result = NULL;

    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

int main() {

    struct Node* a = createNode(1);
    a->next = createNode(4);
    a->next->next = createNode(5);

    struct Node* b = createNode(1);
    b->next = createNode(3);
    b->next->next = createNode(4);

    struct Node* c = merge(a,b);

    while (c) {
        printf("%d ", c->data);
        c = c->next;
    }

    return 0;
}