#include <stdio.h>
#include <stdlib.h>

// Node's structure
struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    struct node *slow = NULL, *fast = NULL;
    int n;

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

    // Finding middle
    slow = head;
    fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Printing the middle element
    if (slow != NULL) {
        printf("Middle element is: %d", slow->data);
    }

    return 0;
}
