#include <stdio.h>
#include <stdlib.h>

// Structuring a node
struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, value;

    // Reading number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        // Allocating memory for new node
        newNode = (struct node *)malloc(sizeof(struct node));

        // Reading data
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        // If list is empty, making new node the head
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            // Link new node at the end
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Traversing and printing linked list
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}
