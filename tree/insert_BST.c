#include <stdio.h>
#include <stdlib.h>

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

void insert(struct Node *root, int key){
    struct Node* prev = NULL;
    while (root!=NULL)
    {
        prev = root;
        if (key==root->data)
        {
            printf("failed to insert key, already exists in BST !");
            return;
        }
        else if (key<root->data)
        {
            root= root->left;
        }
        else{
            root = root->right;
        }  
    }
    struct Node *new = createNode(key);
    if (prev->data<key)
    {
        prev->right = new;
    }
    else{
        prev->left = new;
    }
    
    
}

void inOrder(struct Node *root){
    if(root!=NULL){   
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);  
    }
    
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

    
    insert(root,6);
    inOrder(root);
    return 0;
}