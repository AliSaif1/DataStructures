#include<stdio.h>

struct circularQueue{
    int data;
    struct circularQueue *next;
}*front = NULL, *rear = NULL;

void insertElement(int data);
void deleteElement();
void displayQueue();

int main(){
    insertElement(23);
    insertElement(56);
    insertElement(27);
    insertElement(39);
    insertElement(3);
    displayQueue();

    deleteElement();
    deleteElement();
    deleteElement();

    insertElement(45);
    insertElement(37);
    displayQueue();
}

void insertElement(int data){
    struct circularQueue *newNode = (struct circularQueue*)malloc(sizeof(struct circularQueue));
    newNode->data = data;
    newNode->next = NULL;
    if(rear == NULL){
        rear = newNode;
        front = newNode;
        rear->next = front;
        return;
    }
    rear->next = newNode;
    rear = newNode;
    rear->next = front;
}
void deleteElement(){
    if(front == NULL){
        printf("Queue is Empty :\n");
        return;
    }
    if(rear == front){
        printf("Deleted Element = %d\n", front->data);
        rear = NULL;
        front = NULL;
        free(front);
        return;
    }
    struct circularQueue *temp = front;
    printf("Deleted Element = %d\n", temp->data);
    front = front->next;
    free(temp);
}
void displayQueue(){
    if(front == NULL){
        printf("Queue is Empty :\n");
        return;
    }
    struct circularQueue *temp = front;
    do{
        printf("%d\t", temp->data);
        temp = temp->next;
    }while(temp->next != front);
    printf("%d\n", temp->data);
}
