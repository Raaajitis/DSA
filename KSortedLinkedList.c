#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* merge(struct Node* l1, struct Node* l2) {

    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

struct Node* mergeKLists(struct Node* lists[], int k) {

    if (k == 0) return NULL;

    while (k > 1) {
        int i = 0, j = k - 1;

        while (i < j) {
            lists[i] = merge(lists[i], lists[j]);
            i++;
            j--;
        }
        k = (k + 1) / 2;
    }

    return lists[0];
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {

    struct Node* l1 = createNode(1);
    l1->next = createNode(4);
    l1->next->next = createNode(5);

    struct Node* l2 = createNode(1);
    l2->next = createNode(3);
    l2->next->next = createNode(4);

    struct Node* l3 = createNode(2);
    l3->next = createNode(6);

    struct Node* lists[3] = {l1, l2, l3};

    struct Node* result = mergeKLists(lists, 3);

    printList(result);

    return 0;
}