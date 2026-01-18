#include <stdio.h>
#include <stdlib.h>
// Node structure
struct Node {
int data;
struct Node* next;
};
// Function to create a new node
struct Node* createNode(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = NULL;
return newNode;
}
// Function to display the linked list
void displayList(struct Node* head) {
struct Node* current = head;
while (current != NULL) {
printf("%d -> ", current->data);
current = current->next;
}
printf("NULL\n");
}
// Function to insert a node at the beginning
struct Node* insertAtBegin(struct Node* head, int value) {
struct Node* newNode = createNode(value);
newNode->next = head;
head = newNode;
printf("Inserted at the beginning.\n");
return head;
}
// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* head, int value) {
struct Node* newNode = createNode(value);
if (head == NULL) {
head = newNode;
} else {
struct Node* current = head;
while (current->next != NULL) {
current = current->next;
}
current->next = newNode;
}
printf("Inserted at the end.\n");
return head;
}
// Function to insert a node at any position
struct Node* insertAtPos(struct Node* head, int value, int position) {
if (position < 1) {
printf("Invalid position. Please enter a position greater than 0.\n");
return head;
}
struct Node* newNode = createNode(value);
if (position == 1) {
newNode->next = head;
head = newNode;
printf("Inserted at position %d.\n", position);
return head;
}
struct Node* current = head;
int i;
for (i = 1; i < position - 1 && current != NULL; i++) {
current = current->next;
}
if (current == NULL) {
printf("Invalid position. Cannot insert at position %d.\n", position);
return head;
}
newNode->next = current->next;
current->next = newNode;
printf("Inserted at position %d.\n", position);
return head;
}
// Function to delete a node at the beginning
struct Node* deleteAtBegin(struct Node* head) {
if (head == NULL) {
printf("List is empty. Cannot delete from the beginning.\n");
return head;
}
struct Node* temp = head;
head = head->next;
free(temp);
printf("Deleted at the beginning.\n");
return head;
}
// Function to delete a node at the end
struct Node* deleteAtEnd(struct Node* head) {
if (head == NULL) {
printf("List is empty. Cannot delete from the end.\n");
return head;
}
if (head->next == NULL) {
free(head);
printf("Deleted at the end.\n");
return NULL;
}
struct Node* current = head;
while (current->next->next != NULL) {
current = current->next;
}
free(current->next);
current->next = NULL;
printf("Deleted at the end.\n");
return head;
}
// Function to delete a node at any position
struct Node* deleteAtPos(struct Node* head, int position) {
if (head == NULL) {
printf("List is empty. Cannot delete from the specified position.\n");
return head;
}
if (position == 1) {
struct Node* temp = head;
head = head->next;
free(temp);
printf("Deleted at position %d.\n", position);
return head;
}
struct Node* current = head;
int i;
for (i = 1; i < position - 1 && current != NULL; i++) {
current = current->next;
}
if (current == NULL || current->next == NULL) {
    printf("Invalid position. Cannot delete from position %d.\n", position);
return head;
}
struct Node* temp = current->next;
current->next = current->next->next;
free(temp);
printf("Deleted at position %d.\n", position);
return head;
}
// Function to free the entire linked list
void freeList(struct Node* head) {
struct Node* current = head;
struct Node* nextNode;
while (current != NULL) {
nextNode = current->next;
free(current);
current = nextNode;
}
}
int main() {
struct Node* head = NULL;
int choice, value, position;
do {
printf("\nMenu:\n");
printf("1. Insert at the beginning\n");
printf("2. Insert at the end\n");
printf("3. Insert at any position\n");
printf("4. Delete at the beginning\n");
printf("5. Delete at the end\n");
printf("6. Delete at any position\n");
printf("7. Display the list\n");
printf("8. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the value to insert: ");
scanf("%d", &value);
head = insertAtBegin(head, value);
break;
case 2:
printf("Enter the value to insert: ");
scanf("%d", &value);
head = insertAtEnd(head, value);
break;
case 3:
printf("Enter the value to insert: ");
scanf("%d", &value);
printf("Enter the position to insert: ");
scanf("%d", &position);
head = insertAtPos(head, value, position);
break;
case 4:
head = deleteAtBegin(head);
break;
case 5:
head = deleteAtEnd(head);
break;
case 6:
printf("Enter the position to delete: ");
scanf("%d", &position);
head = deleteAtPos(head, position);
break;
case 7:
displayList(head);
break;
case 8:
freeList(head); // free the entire list before exiting
printf("Exiting the program.\n");
break;
default:
printf("Invalid choice. Please enter a valid option.\n");
}
} while (choice != 8);
return 0;
}
