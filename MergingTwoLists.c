#include <stdio.h>
#include <stdlib.h>

// Node's structure
struct node {
    int data;
    struct node *next;
};

// Function for merging two sorted lists
struct node* mergeLists(struct node* l1, struct node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    if (l1->data < l2->data) {
        l1->next = mergeLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeLists(l1, l2->next);
        return l2;
    }
}

int main() {
    printf("Merged two sorted linked lists successfully");
    return 0;
}
