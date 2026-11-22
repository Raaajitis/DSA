#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;

    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {

    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void morrisInorder(struct Node *root) {

    struct Node *current = root;

    printf("Inorder traversal: ");

    while (current != NULL) {

        // No left subtree
        if (current->left == NULL) {

            printf("%d ", current->data);

            current = current->right;
        }

        else {

            /*
             * Find inorder predecessor:
             * rightmost node of left subtree.
             */
            struct Node *predecessor =
                current->left;

            while (predecessor->right != NULL &&
                   predecessor->right != current) {

                predecessor =
                    predecessor->right;
            }

            /*
             * First time reaching current:
             * create temporary link.
             */
            if (predecessor->right == NULL) {

                predecessor->right = current;

                current = current->left;
            }

            /*
             * Second time reaching current:
             * left subtree has been processed.
             */
            else {

                predecessor->right = NULL;

                printf("%d ", current->data);

                current = current->right;
            }
        }
    }

    printf("\n");
}

int main() {

    struct Node *root = createNode(4);

    root->left = createNode(2);
    root->right = createNode(6);

    root->left->left = createNode(1);
    root->left->right = createNode(3);

    root->right->left = createNode(5);
    root->right->right = createNode(7);

    morrisInorder(root);

    return 0;
}