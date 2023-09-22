#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Queue{
    int data;
    struct Queue *next;
}*front = NULL, *rear = NULL;

void insertElement(int data);
void deleteElement();
void displayQueue();

int main(){
    insertElement(10);
    insertElement(20);
    insertElement(13);
    insertElement(30);
    insertElement(45);
    displayQueue();

    deleteElement();
    deleteElement();
    displayQueue();
}

void insertElement(int data){
    struct Queue *newNode = (struct Queue*)malloc(sizeof(struct Queue));
    newNode->data = data;
    newNode->next = NULL;
    if(rear == NULL){
        rear = newNode;
        front = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}
void deleteElement(){
    if(front == NULL){
        printf("Queue is Empty : \n");
        return;
    }
    struct Queue *temp = front;
    front = front->next;
    printf("Deleted Element = %d\n", temp->data);
    free(temp);
}
void displayQueue(){
   if(front == NULL){
        printf("Queue is Empty : \n");
        return;
    }
    struct Queue *temp = front;
    while(temp->next != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}
