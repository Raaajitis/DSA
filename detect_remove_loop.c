#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void removeLoop(struct Node *head) {

    if (head == NULL || head->next == NULL)
        return;

    struct Node *slow = head;
    struct Node *fast = head;

    // Step 1: Detect loop
    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // No loop
    if (slow != fast)
        return;

    // Step 2: Find beginning of loop
    slow = head;

    if (slow == fast) {

        // Special case: loop starts at head
        while (fast->next != slow)
            fast = fast->next;

    } else {

        while (slow->next != fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Step 3: Remove loop
    fast->next = NULL;
}

void printList(struct Node *head) {

    while (head != NULL) {
        printf("%d ", head->data);
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

    // Create loop:
    // 1 -> 2 -> 3 -> 4 -> 5
    //           ^         |
    //           |_________|
    head->next->next->next->next->next =
        head->next->next;

    removeLoop(head);

    printf("Linked List after removing loop: ");
    printList(head);

    return 0;
}