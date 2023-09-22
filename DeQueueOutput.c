#include<stdio.h>
#define SIZE 10

//Output Restricted Queue:
void insertElement(int arr[], int data, int side);
void deleteElement(int arr[]);
void displayQueue(int arr[]);

int front = -1, rear = -1;
int main(){
    int arr[SIZE] = {0};
    insertElement(arr, 34, 1);
    insertElement(arr, 4, 1);
    insertElement(arr, 3, 1);
    insertElement(arr, 56, 2);
    displayQueue(arr);

    deleteElement(arr);
    deleteElement(arr);
    deleteElement(arr);
    displayQueue(arr);

    insertElement(arr, 6, 2);
    insertElement(arr, 9, 2);
    insertElement(arr, 64, 2);
    displayQueue(arr);
}

void insertElement(int arr[], int data, int side){
    if(side == 1){
        if(rear > SIZE - 1){
            printf("Queue is Full from Rear : \n");
            return;
        }
        rear += 1;
        arr[rear] = data;
        if(front == -1)
            front = 0;
    }
    else if(side == 2){
        if(front < 0){
            printf("Queue is Full from Front : \n");
            return;
        }
        front -= 1;
        arr[front] = data;
        if(rear == -1)
            rear = 0;
    }
}
void deleteElement(int arr[]){
    if(rear == -1 && front == -1){
        printf("Queue is Empty :\n");
        return;
    }
    if(front == rear){
        printf("Deleted Element = %d\n", arr[front]);
        front = -1;
        rear = -1;
        return;
    }
    printf("Deleted Element = %d\n", arr[front]);
    front += 1;
}
void displayQueue(int arr[]){
    if(rear == -1 && front == -1){
        printf("Queue is Empty :\n");
        return;
    }
    for(int i = front; i <= rear; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}
