#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right= NULL;
    return newNode;
}

struct node* BSTSearch(struct node* root, int key){
    if (root==NULL)
    {
        return NULL;
    }
    else if (root->data==key)
    {
        return root;
    }
    else if (root->data<key)
    {
        return BSTSearch(root->right,key);
    }
    else{
        return BSTSearch(root->left,key);
    }
    
}

int main()
{
    /* 
       Constructing a valid Binary Search Tree:
                 4
               /   \
              2     5
             / \
            1   3
    */
    struct node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->left->right = createNode(3);

    struct node* p = BSTSearch(root,9);
    if (p!=NULL){
        printf("found: %d at %d",p->data,p);
    }
    else{
        printf("element not found");
    }
    

    return 0;
}