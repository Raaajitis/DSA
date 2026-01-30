#include <stdio.h>
#include <stdlib.h>

// Node's structure
struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, x, position = 1;

    // Creating linked list
    printf("Enter number of required nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = head;
        head = newNode;
    }

    // Reading element to search
    printf("Enter element to search: ");
    scanf("%d", &x);

    // Searching element
    temp = head;
    while (temp != NULL) {
        if (temp->data == x) {
            printf("Element found at position %d", position);
            return 0;
        }
        temp = temp->next;
        position++;
    }

    // If not found
    printf("Element not found");

    return 0;
}
