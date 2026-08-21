#include<stdio.h>
#include<stdlib.h>
int insertionAtStart(int arr[], int *size, int capacity, int element){
     if(*size>=capacity){
        printf("Invalid index");
        return -1;
    }
    else
    {
        for (int i = *size; i>=0; i--)
        {
            arr[i+1]= arr[i];
        }
        arr[0]= element;
        *size= *size + 1; 
        return 1;
    }
}
int insertionAtEnd(int arr[], int *size, int capacity, int element){
    if(*size>=capacity){
        printf("Invalid index");
        return -1;
    }
    else
    {     
        arr[*size]= element;
        *size= *size + 1; 
        return 1;
    }
    
}



int insertionAtAnyIndex(int arr[], int *size, int capacity,int index, int element){
    if(*size>=capacity){
        printf("Invalid index");
        return -1;
    }
    else
    {
        for (int i = *size; i>=index; i--)
        {
            arr[i+1]= arr[i];
        }
        arr[index]= element;
        *size= *size + 1; 
    }
    
}
int display(int arr[], int *size,int capacity){
 if(*size>=capacity){
        return -1;
    }
else{    for (int i = 0; i < *size; i++)
    {
        printf("%d ",arr[i]);
    }
    
}
}

int main()
{
    int capacity = 10;
    int *arr = (int*)malloc(capacity * sizeof(int));
    int size = 0;
    int index= 2;
    insertionAtStart(arr, &size, capacity, 2);
    insertionAtEnd(arr, &size, capacity, 23);
    insertionAtEnd(arr, &size, capacity, 25);
    insertionAtEnd(arr, &size, capacity, 78);
    insertionAtEnd(arr, &size, capacity, 65);
    insertionAtAnyIndex(arr, &size, capacity,index, 0);
    display(arr, &size,capacity);
   
    return 0;
}