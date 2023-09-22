#include<stdio.h>
#define SIZE 10

void insertElement(int data);
void deleteElement();
void displayQueue();

int front = -1, rear = -1;
int arr[SIZE] = {0};
int main(){
    insertElement(10);
    insertElement(20);
    insertElement(15);
    insertElement(19);
    insertElement(0);
    insertElement(13);
    insertElement(17);
    displayQueue();

    deleteElement();
    deleteElement();
    deleteElement();
    displayQueue();

    insertElement(29);
    insertElement(16);
    insertElement(9);
    insertElement(6);
    insertElement(90);
    insertElement(7);
    insertElement(43);
    insertElement(65);
    insertElement(87);
    displayQueue();

    deleteElement();
    deleteElement();
    deleteElement();
    deleteElement();
    displayQueue();
}

void insertElement(int data){
    if((rear > SIZE - 1 && front == 0) || front == rear + 1){
        printf("Queue is Full :\n");
        return;
    }
    if(rear > SIZE - 1)
        rear = -1;
    rear = rear + 1;
    arr[rear] = data;
    if(front == -1)
        front = 0;
}
void deleteElement(){
    if(front == -1){
        printf("Queue is Empty : \n");
        return;
    }
    if(front == rear){
        printf("Deleted Element = %d\n", arr[front]);
        front = -1;
        rear = -1;
        return;
    }
    if(front > SIZE - 1){
        printf("Deleted Element = %d\n", arr[front]);
        front = 0;
        return;
    }
    printf("Deleted Element = %d\n", arr[front]);
    front += 1;
}
void displayQueue(){
    if(front > rear){
        for(int i = front; i < SIZE; i++)
            printf("%d\t", arr[i]);
        for(int i = 0; i <= rear; i++)
            printf("%d\t", arr[i]);
    }
    else
        for(int i = front; i <= rear; i++)
            printf("%d\t", arr[i]);
    printf("\n");
}
