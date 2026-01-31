#include <stdio.h>
#include <stdlib.h>

// Node's structure
struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp = NULL, *prev = NULL, *newNode = NULL;
    int n, x;

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

    // Asking for the value to delete
    printf("Enter the value to delete: ");
    scanf("%d", &x);

    // If the head node needs to be deleted
    if (head != NULL && head->data == x) {
        temp = head;
        head = head->next;
        free(temp);
    } else {
        temp = head;

        // Searching for the node
        while (temp != NULL && temp->data != x) {
            prev = temp;
            temp = temp->next;
        }

        // If we find the value
        if (temp != NULL) {
            prev->next = temp->next;
            free(temp);
        }
    }

    // Printing the updated list
    printf("The updated list is:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}
