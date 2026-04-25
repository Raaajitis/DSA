#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;
    return n;
}

struct Node* rotate(struct Node* head, int k) {

    if (!head) return head;

    struct Node* temp = head;
    int len = 1;

    while (temp->next) {
        temp = temp->next;
        len++;
    }

    temp->next = head; // make circular

    k = k % len;
    int steps = len - k;

    while (steps--)
        temp = temp->next;

    struct Node* newHead = temp->next;
    temp->next = NULL;

    return newHead;
}

void print(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {

    struct Node* head = create(1);
    head->next = create(2);
    head->next->next = create(3);
    head->next->next->next = create(4);
    head->next->next->next->next = create(5);

    head = rotate(head, 2);

    print(head);

    return 0;
}