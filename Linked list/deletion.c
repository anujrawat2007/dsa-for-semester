#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* deletionAtfirst(struct node *head){
    struct node *ptr= (struct node*)malloc(sizeof(struct node));
    ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct node* deletionAtIndex(struct node *head,int index){
    struct node *p = (struct node*)malloc(sizeof(struct node));
    struct node *q = (struct node*)malloc(sizeof(struct node));
    p=head;
    q=p->next;
    int i = 0;
    while (i!=index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
}

void traversal(struct node *ptr){
    while (ptr!=NULL)
    {
        printf("element: %d \n",ptr->data);
        ptr=ptr->next;
    }
    
}
int main()
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *second = (struct node*)malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));
    struct node *fourth = (struct node*)malloc(sizeof(struct node));
    
    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=NULL;
    
    printf("before deletion \n");
    traversal(head);

    printf("After deletion \n");
    // head = deletionAtfirst(head);
    head = deletionAtIndex(head,2);
    traversal(head);


    return 0;
}