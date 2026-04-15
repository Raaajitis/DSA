#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 3

struct Node {
    int key, value;
    struct Node *prev, *next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void addFront(struct Node* node) {
    node->next = head;
    node->prev = NULL;
    if (head)
        head->prev = node;
    head = node;
    if (!tail)
        tail = node;
}

void removeNode(struct Node* node) {
    if (node->prev)
        node->prev->next = node->next;
    else
        head = node->next;

    if (node->next)
        node->next->prev = node->prev;
    else
        tail = node->prev;
}

void moveToFront(struct Node* node) {
    removeNode(node);
    addFront(node);
}

void put(int key, int value) {

    struct Node* node = malloc(sizeof(struct Node));
    node->key = key;
    node->value = value;

    if (!head) {
        addFront(node);
        return;
    }

    int count = 0;
    struct Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    if (count == CAPACITY) {
        removeNode(tail);
    }

    addFront(node);
}

void display() {
    struct Node* temp = head;
    while (temp) {
        printf("(%d,%d) ", temp->key, temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {

    put(1,10);
    put(2,20);
    put(3,30);
    display();

    put(4,40); // removes least recently used
    display();

    return 0;
}