#include <stdio.h>
#include <stdlib.h>

// Node's structure
struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    struct node *prev = NULL, *current = NULL, *next = NULL;
    int n;

    // Creating a linked list
    printf("Enter number of required nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = head;
        head = newNode;
    }

    // Reversing linked list
    current = head;
    while (current != NULL) {
        next = current->next;   // Storing the next node
        current->next = prev;   // Reversing the link
        prev = current;         // Moving previous forward
        current = next;         // Moving current forward
    }
    head = prev;

    // Printing the final reversed list
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}
