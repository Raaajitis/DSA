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

void zigZag(struct Node *head) {

    if (head == NULL) {
        return;
    }

    int expectLess = 1;

    struct Node *current = head;

    while (current->next != NULL) {

        if (expectLess == 1) {

            // We want current < next
            if (current->data > current->next->data) {

                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
        }
        else {

            // We want current > next
            if (current->data < current->next->data) {

                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
        }

        // Change < to > or > to <
        expectLess = !expectLess;

        current = current->next;
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

    struct Node *head = createNode(4);

    head->next = createNode(3);
    head->next->next = createNode(7);
    head->next->next->next = createNode(8);
    head->next->next->next->next = createNode(6);
    head->next->next->next->next->next = createNode(2);
    head->next->next->next->next->next->next = createNode(1);

    printf("Original Linked List:\n");
    printList(head);

    zigZag(head);

    printf("\nZig-Zag Linked List:\n");
    printList(head);

    return 0;
}