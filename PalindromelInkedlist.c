#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

struct Node* reverse(struct Node* head) {

    struct Node* prev = NULL;
    struct Node* curr = head;

    while (curr) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int isPalindrome(struct Node* head) {

    struct Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* second = reverse(slow);
    struct Node* first = head;

    while (second) {
        if (first->data != second->data)
            return 0;
        first = first->next;
        second = second->next;
    }

    return 1;
}

int main() {

    struct Node* head = create(1);
    head->next = create(2);
    head->next->next = create(2);
    head->next->next->next = create(1);

    if (isPalindrome(head))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}