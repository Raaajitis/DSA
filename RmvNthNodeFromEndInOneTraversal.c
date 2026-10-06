#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value) {

    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

struct Node* removeNthFromEnd(struct Node *head, int n) {

    // Dummy node handles deletion of head easily
    struct Node dummy;

    dummy.data = 0;
    dummy.next = head;

    struct Node *fast = &dummy;
    struct Node *slow = &dummy;

    // Move fast pointer n nodes ahead
    for (int i = 0; i < n; i++) {

        fast = fast->next;

        if (fast == NULL) {
            printf("Invalid value of n.\n");
            return head;
        }
    }

    // Move both pointers together
    while (fast->next != NULL) {

        fast = fast->next;
        slow = slow->next;
    }

    // Node to be deleted
    struct Node *temp = slow->next;

    slow->next = slow->next->next;

    free(temp);

    return dummy.next;
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

    struct Node *head = createNode(10);

    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    int n = 2;

    printf("Original Linked List:\n");
    printList(head);

    head = removeNthFromEnd(head, n);

    printf("\nAfter removing %dth node from end:\n", n);
    printList(head);

    return 0;
}