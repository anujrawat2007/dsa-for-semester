#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr){
    if (ptr->top==ptr->size-1)
    {
        return 1;
    }
    else{
        return 0;
    } 
}

int isEmpty(struct stack *ptr){
    if (ptr->top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

void push(struct stack *ptr, int element){
    if (isFull(ptr))
    {
        printf("Stack overflow, can not push %d in the stack \n",element);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=element;
    }
}
void pop(struct stack *ptr){
    if (isEmpty(ptr))
    {
       printf("Stack is empty \n"); 
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        printf("popped out %d \n",val);
    }
}

void display(struct stack *ptr){
    for (int i = 0; i <=ptr->top; i++)
    {
        printf("%d ",ptr->arr[i]);
    }
    
}

int main()
{
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size= 10;
    sp->top=-1;
    sp->arr= (int*)malloc(sp->size*sizeof(int));
    printf("stack has been created successfully \n");


    printf("before pushing elements, FUll:  %d \n",isFull(sp));
    printf("before pushing elements, EMPTY:  %d \n",isEmpty(sp));
    push(sp,5);
    push(sp,5);
    push(sp,5);
    push(sp,5);
    push(sp,5);
    push(sp,5);
    push(sp,5);
    push(sp,5);
    push(sp,5);
    push(sp,5);
    push(sp,5);  //stack overflow
    pop(sp);
    push(sp,9);

    printf("before pushing elements, FUll:  %d \n",isFull(sp));
    printf("before pushing elements, EMPTY:  %d \n",isEmpty(sp));
    display(sp);

    
    
    return 0;
}