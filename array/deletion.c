#include<stdio.h>
void deletionAtStart(int arr[],int size){
  for (int  i = 0; i < size; i++)
  {
    arr[i-1]= arr[i];
  }
}
  
void display(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
}


int main()
{
    int arr[5]= {0,2,3,4,3};
    int size= 5;
    int delIdx;
    // printf("Enter at which index you want to delete an element");
    // scanf("%d",&delIdx);
    deletionAtStart(arr,size);
    display(arr,size);
    return 0;
}