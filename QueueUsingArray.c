#include<stdio.h>
#define SIZE 10

void insertElement(int data);
void deleteElement();
void displayQueue();

int front = -1, rear = -1;
int arr[SIZE] = {0};
int main(){
    insertElement(45);
    insertElement(5);
    insertElement(50);
    insertElement(23);
    insertElement(34);
    displayQueue();

    deleteElement();
    deleteElement();
    displayQueue();
}

void insertElement(int data){
    if(rear > SIZE - 1){
        printf("Queue is Full :");
        exit(0);
    }
    rear = rear + 1;
    arr[rear] = data;
    if(front == -1)
        front = 0;
}
void deleteElement(){
    int deleteData = 0;
    if(rear == 0){
        printf("Queue is Empty ");
        exit(0);
    }
    if(rear == front){
        deleteData = arr[rear];
        printf("Deleted Element = %d\n", deleteData);
        rear = -1;
        front = rear;
        exit(0);
    }
    deleteData = arr[front];
    printf("Deleted Element = %d\n", deleteData);
    front += 1;
}
void displayQueue(){
    printf("Queue Elements :\t");
    for(int i = front; i <= rear; i++)
        printf("%d\t", arr[i]);
     printf("\n\n");
}
