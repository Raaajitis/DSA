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

int detectAndRemoveLoop(struct Node *head) {

    if (head == NULL) {
        return 0;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    // Detect loop
    while (fast != NULL &&
           fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    // No loop found
    if (fast == NULL ||
        fast->next == NULL) {

        return 0;
    }

    /*
       Find beginning of loop.
    */

    slow = head;

    while (slow != fast) {

        slow = slow->next;
        fast = fast->next;
    }

    // slow is now the start of the loop
    struct Node *loopStart = slow;

    /*
       Find the last node in the cycle.
    */

    struct Node *current = loopStart;

    while (current->next != loopStart) {

        current = current->next;
    }

    // Break the loop
    current->next = NULL;

    return 1;
}

void printList(struct Node *head) {

    while (head != NULL) {

        printf("%d", head->data);

        if (head->next != NULL) {
            printf(" -> ");
        }

        head = head->next;
    }

    printf(" -> NULL\n");
}

int main() {

    struct Node *head = createNode(10);

    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next =
        createNode(50);

    /*
       Create loop:

       50 -> 30
    */

    head->next->next->next->next->next =
        head->next->next;

    if (detectAndRemoveLoop(head)) {

        printf("Loop detected and removed.\n");

    } else {

        printf("No loop detected.\n");
    }

    printf("\nLinked List:\n");

    printList(head);

    return 0;
}