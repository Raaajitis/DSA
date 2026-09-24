#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

struct Node* findIntersection(struct Node *headA,
                              struct Node *headB) {

    if (headA == NULL || headB == NULL)
        return NULL;

    struct Node *p1 = headA;
    struct Node *p2 = headB;

    while (p1 != p2) {

        if (p1 == NULL)
            p1 = headB;
        else
            p1 = p1->next;

        if (p2 == NULL)
            p2 = headA;
        else
            p2 = p2->next;
    }

    return p1;
}

int main() {
    struct Node *common = createNode(7);
    common->next = createNode(8);
    common->next->next = createNode(9);

    struct Node *headA = createNode(1);
    headA->next = createNode(2);
    headA->next->next = createNode(3);
    headA->next->next->next = common;

    struct Node *headB = createNode(4);
    headB->next = createNode(5);
    headB->next->next = common;

    struct Node *intersection =
        findIntersection(headA, headB);

    if (intersection != NULL)
        printf("Intersection Node: %d\n",
               intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}