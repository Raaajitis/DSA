#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* random;
};

struct Node* createNode(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->next = n->random = NULL;
    return n;
}

struct Node* cloneList(struct Node* head) {

    struct Node* curr = head;

    // Step 1: Insert clone nodes
    while (curr) {
        struct Node* temp = createNode(curr->data);
        temp->next = curr->next;
        curr->next = temp;
        curr = temp->next;
    }

    // Step 2: Set random pointers
    curr = head;
    while (curr) {
        if (curr->random)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    // Step 3: Separate lists
    struct Node* newHead = head->next;
    curr = head;

    while (curr) {
        struct Node* temp = curr->next;
        curr->next = temp->next;

        if (temp->next)
            temp->next = temp->next->next;

        curr = curr->next;
    }

    return newHead;
}

int main() {

    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    head->random = head->next->next;
    head->next->random = head;

    struct Node* clone = cloneList(head);

    printf("Cloned list created\n");

    return 0;
}