#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
int main()
{
    struct node *p; //creating the root node
    p = (struct node*)malloc(sizeof(struct node)); // allocating memory in the heap
    p->data= 2;
    p->left=NULL;
    p->right=NULL;

    struct node *p1; //creating the second node
    p1 = (struct node*)malloc(sizeof(struct node)); //allocating memory in the heap
    p1->data= 4;
    p1->left = NULL;
    p1->right = NULL;

    struct node *p2;  //creating the third node
    p2 = (struct node*)malloc(sizeof(struct node)); //allocating memory in the heap
    p2->data= 4;
    p2->left = NULL;
    p2->right = NULL;

    //linking the root node from left and right children
    p->left= p1;
    p->right = p2;

    return 0;
}