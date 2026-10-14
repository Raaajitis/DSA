#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value) {

    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

struct Node* partition(struct Node *head, int x) {

    struct Node beforeDummy;
    struct Node afterDummy;

    beforeDummy.next = NULL;
    afterDummy.next = NULL;

    struct Node *before = &beforeDummy;
    struct Node *after = &afterDummy;

    struct Node *current = head;

    while (current != NULL) {

        // Save next node before changing links
        struct Node *nextNode = current->next;

        current->next = NULL;

        if (current->data < x) {

            before->next = current;
            before = current;

        } else {

            after->next = current;
            after = current;
        }

        current = nextNode;
    }

    // Connect the two partitions
    before->next = afterDummy.next;

    return beforeDummy.next;
}

void printList(struct Node *head) {

    while (head != NULL) {

        printf("%d", head->data);

        if (head->next != NULL) {
            printf(" -> ");
        }

        head = head->next;
    }

    printf("\n");
}

int main() {

    struct Node *head = createNode(3);

    head->next = createNode(5);
    head->next->next = createNode(8);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(10);
    head->next->next->next->next->next = createNode(2);
    head->next->next->next->next->next->next =
        createNode(1);

    int x = 5;

    printf("Original List:\n");
    printList(head);

    head = partition(head, x);

    printf("\nList after partitioning around %d:\n", x);
    printList(head);

    return 0;
}