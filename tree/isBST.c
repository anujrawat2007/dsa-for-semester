#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h> 

// Structure definition for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Helper function to allocate a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};


bool isBSTUtil(struct Node* root, int min, int max) {
    // Base case: An empty tree or leaf child boundary is a valid BST
    if (root == NULL) {
        return true;
    }

    // Check if the current node's data violates the permissible range constraints
    if (root->data <= min || root->data >= max) {
        return false;
    }

    // Recursively validate subtrees with updated constraints:
    // For the left subtree, the upper bound (max) becomes the current node's data.
    // For the right subtree, the lower bound (min) becomes the current node's data.
    return isBSTUtil(root->left, min, root->data) && 
           isBSTUtil(root->right, root->data, max);
}


bool isBST(struct Node* root) {
    // Initial evaluation begins with the absolute bounds of an integer range
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    /* 
       Constructing a valid Binary Search Tree:
                 4
               /   \
              2     5
             / \
            1   3
    */
    struct Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->left->right = createNode(3);

    // Validate and print the result
    if (isBST(root)) {
        printf("The binary tree is a valid Binary Search Tree (BST).\n");
    } else {
        printf("The binary tree is NOT a valid Binary Search Tree (BST).\n");
    }

    // Freeing allocated memory can be appended here to prevent memory leaks

    return 0;
}