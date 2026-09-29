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

struct Node* findIntersection(struct Node *head1,
                              struct Node *head2) {

    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;

    while (ptr1 != ptr2) {

        if (ptr1 == NULL) {
            ptr1 = head2;
        }
        else {
            ptr1 = ptr1->next;
        }

        if (ptr2 == NULL) {
            ptr2 = head1;
        }
        else {
            ptr2 = ptr2->next;
        }
    }

    return ptr1;
}

int main() {

    // Common part
    struct Node *common1 = createNode(50);
    struct Node *common2 = createNode(60);
    struct Node *common3 = createNode(70);

    common1->next = common2;
    common2->next = common3;

    // First linked list: 10 -> 20 -> 30 -> 50 -> 60 -> 70
    struct Node *head1 = createNode(10);

    head1->next = createNode(20);
    head1->next->next = createNode(30);

    head1->next->next->next = common1;

    // Second linked list: 40 -> 50 -> 60 -> 70
    struct Node *head2 = createNode(40);

    head2->next = common1;

    struct Node *result = findIntersection(head1, head2);

    if (result != NULL) {

        printf("Intersection point: %d\n", result->data);

    } else {

        printf("The linked lists do not intersect.\n");
    }

    return 0;
}