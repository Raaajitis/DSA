#include <stdio.h>
#include <stdlib.h>

// Structuring a node
struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, count = 0;

    // Reading number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = head;
        head = newNode;
    }

    // Counting nodes
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Printing count
    printf("Number of nodes are: %d", count);

    return 0;
}
