#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;

    struct Node *next;
    struct Node *random;
};

struct Node* createNode(int value) {

    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;
    newNode->random = NULL;

    return newNode;
}

struct Node* cloneList(struct Node *head) {

    if (head == NULL) {
        return NULL;
    }

    struct Node *current = head;

    // Step 1: Insert copied nodes
    while (current != NULL) {

        struct Node *copy =
            createNode(current->data);

        copy->next = current->next;

        current->next = copy;

        current = copy->next;
    }

    // Step 2: Set random pointers
    current = head;

    while (current != NULL) {

        struct Node *copy = current->next;

        if (current->random != NULL) {

            copy->random =
                current->random->next;
        }

        current = copy->next;
    }

    // Step 3: Separate both lists
    current = head;

    struct Node *copyHead = head->next;

    while (current != NULL) {

        struct Node *copy = current->next;

        current->next = copy->next;

        if (copy->next != NULL) {

            copy->next =
                copy->next->next;
        }

        current = current->next;
    }

    return copyHead;
}

void printList(struct Node *head) {

    while (head != NULL) {

        printf("Node %d, Random -> ",
               head->data);

        if (head->random != NULL) {

            printf("%d", head->random->data);

        } else {

            printf("NULL");
        }

        printf("\n");

        head = head->next;
    }
}

int main() {

    struct Node *first = createNode(10);
    struct Node *second = createNode(20);
    struct Node *third = createNode(30);

    first->next = second;
    second->next = third;

    // Random pointers
    first->random = third;
    second->random = first;
    third->random = second;

    printf("Original List:\n");
    printList(first);

    struct Node *copy = cloneList(first);

    printf("\nCloned List:\n");
    printList(copy);

    return 0;
}