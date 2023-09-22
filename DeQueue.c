#include<stdio.h>
#define SIZE 10

//Input Restricted Queue:
void insertElement(int arr[],int data);
void deleteElement(int arr[], int side);
void displayQueue(int arr[]);

int front = -1, rear = -1;
int main(){
    int arr[SIZE] = {0};
    displayQueue(arr);
    insertElement(arr, 23);
    insertElement(arr, 3);
    insertElement(arr, 38);
    insertElement(arr, 20);
    insertElement(arr, 45);
    displayQueue(arr);

    deleteElement(arr, 2);
    deleteElement(arr, 1);
    deleteElement(arr, 2);
    deleteElement(arr, 2);
    deleteElement(arr, 2);
    deleteElement(arr, 2);
    displayQueue(arr);

    insertElement(arr, 5);
    insertElement(arr, 67);
    insertElement(arr, 4);
    insertElement(arr, 98);
    displayQueue(arr);
}

void insertElement(int arr[], int data){
    if(rear > SIZE -1){
        printf("Queue is Full : \n");
        return;
    }
    rear += 1;
    arr[rear] = data;
    if(front == -1)
        front = 0;
}
void deleteElement(int arr[], int side){
    if(front == -1 && rear == -1){
        printf("Queue is Empty : \n");
        return;
    }
    if(side == 1){
        if(front == rear){
            printf("Deleted Element = %d\n", arr[front]);
            front = -1;
            rear = -1;
            return;
        }
        if(front > SIZE - 1){
            printf("Deleted Element = %d\n", arr[front]);
            front = -1;
            return;
        }
        printf("Deleted Element = %d\n", arr[front]);
        front += 1;
    }
    else if(side == 2){
        if(front == rear){
            printf("Deleted Element = %d\n", arr[rear]);
            front = -1;
            rear = -1;
            return;
        }
        printf("Deleted Element = %d\n", arr[rear]);
        rear -= 1;
    }
}
void displayQueue(int arr[]){
    if(front == -1){
        printf("Queue is Empty : \n");
        return;
    }
    for(int i = front; i <= rear; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}
