#include<stdio.h>

struct deQueue{
    int data;
    struct deQueue *next, *prev;
}*front = NULL, *rear = NULL;

void insertElement(int data);
void deleteElement(int side);
void displayQueue();

int main(){
    insertElement(23);
    insertElement(56);
    insertElement(27);
    insertElement(39);
    insertElement(3);
    displayQueue();

    deleteElement(2);
    deleteElement(1);
    deleteElement(2);
    deleteElement(1);
    deleteElement(2);
    deleteElement(1);

    insertElement(45);
    insertElement(37);
    displayQueue();
}

void insertElement(int data){
    struct deQueue *newNode = (struct deQueue*)malloc(sizeof(struct deQueue));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = rear;
    if(rear == NULL){
        rear = newNode;
        front = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}
void deleteElement(int side){
    if(front == NULL || rear == NULL){
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
    if(side == 1){
        printf("Deleted Element = %d\n", front->data);
        struct deQueue * temp = front;
        front = front->next;
        front->prev = NULL;
        free(temp);
    }
    if(side == 2){
        struct deQueue *temp = rear;
        printf("Deleted Element = %d\n", temp->data);
        rear = rear->prev;
        rear->next = NULL;
        free(temp);
    }
}
void displayQueue(){
    if(front == NULL){
        printf("Queue is Empty :\n");
        return;
    }
    struct deQueue *temp = front;
    do{
        printf("%d\t", temp->data);
        temp = temp->next;
    }while(temp->next != NULL);
    printf("%d\n", temp->data);
}
