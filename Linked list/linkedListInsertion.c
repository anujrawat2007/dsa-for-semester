#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node* insertionAtFirst(struct node *head, int data){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->next= head;
    ptr->data= data;
    return ptr;
}

struct node * insertionAtIndex(struct node *head, int data, int index){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while(i!=index-1){
        p= p->next;
        i++;
    }
    ptr->data=data;
    ptr->next= p->next;
    p->next= ptr;
    return head;
}

struct node * insertionAtEnd(struct node *head, int data){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *p = head;
    ptr->data= data;
    ptr->next=NULL;
    if (p==NULL)
    {
        return ptr;
    }
    
    while(p->next!=NULL){
        p = p->next;
    }
    p->next=ptr; 
    return head;
}

struct node * insertionAfterNode(struct node *head,struct node *prevNode, int data){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next= ptr;
    return head;
}
void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 20;
    head->next = second;

    second->data = 30;
    second->next = third;

    third->data = 40;
    third->next = fourth;

    fourth->data = 50;
    fourth->next = NULL;
    printf("before insertion...\n");
    traversal(head);
    // head = insertionAtFirst(head,10);
    // head = insertionAtIndex(head,70,2);
    // head = insertionAtEnd(head,80);
    head = insertionAfterNode(head,second,80);
    printf("\nAfter insertion..\n");
    traversal(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}