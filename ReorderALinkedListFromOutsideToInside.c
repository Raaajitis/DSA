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

struct Node* reverseList(struct Node *head) {

    struct Node *previous = NULL;
    struct Node *current = head;

    while (current != NULL) {

        struct Node *nextNode = current->next;

        current->next = previous;

        previous = current;
        current = nextNode;
    }

    return previous;
}

void reorderList(struct Node *head) {

    if (head == NULL || head->next == NULL) {
        return;
    }

    // Step 1: Find middle
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast->next != NULL &&
           fast->next->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Separate and reverse second half
    struct Node *second = slow->next;

    slow->next = NULL;

    second = reverseList(second);

    // Step 3: Merge both halves
    struct Node *first = head;

    while (second != NULL) {

        struct Node *firstNext = first->next;
        struct Node *secondNext = second->next;

        first->next = second;
        second->next = firstNext;

        first = firstNext;
        second = secondNext;
    }
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

    struct Node *head = createNode(1);

    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List:\n");
    printList(head);

    reorderList(head);

    printf("\nReordered List:\n");
    printList(head);

    return 0;
}