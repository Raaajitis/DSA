#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *next;
};

struct Node* createNode(int value) {

    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

struct Node* reverseList(struct Node *head) {

    struct Node *previous = NULL;
    struct Node *current = head;
    struct Node *nextNode;

    while (current != NULL) {

        nextNode = current->next;

        current->next = previous;

        previous = current;

        current = nextNode;
    }

    return previous;
}

int isPalindrome(struct Node *head) {

    if (head == NULL || head->next == NULL) {
        return 1;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    // Find the middle
    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;

        fast = fast->next->next;
    }

    // Reverse second half
    struct Node *secondHalf = reverseList(slow);

    struct Node *firstHalf = head;

    // Compare both halves
    while (secondHalf != NULL) {

        if (firstHalf->data != secondHalf->data) {

            return 0;
        }

        firstHalf = firstHalf->next;

        secondHalf = secondHalf->next;
    }

    return 1;
}

void printList(struct Node *head) {

    while (head != NULL) {

        printf("%d", head->data);

        if (head->next != NULL) {
            printf(" -> ");
        }

        head = head->next;
    }

    printf("\n");
}

int main() {

    struct Node *head = createNode(1);

    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    printf("Linked List:\n");

    printList(head);

    if (isPalindrome(head)) {

        printf("The linked list is a palindrome.\n");

    } else {

        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}