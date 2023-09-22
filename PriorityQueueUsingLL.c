#include<stdio.h>
#include<stdlib.h>

struct priorityQueue{
    int data;
    struct priorityQueue *next;
};

void insertElement(int data, struct priorityQueue **front, struct priorityQueue **rear);
void deleteElement(struct priorityQueue **front, struct priorityQueue **rear);
void displayQueue(int lists, struct priorityQueue *front1, struct priorityQueue *front2,
                   struct priorityQueue *rear1, struct priorityQueue *rear2);

int main(){
    struct priorityQueue *front1 = NULL, *rear1 = NULL, *front2 = NULL, *rear2 = NULL;
    insertElement(12, &front1, &rear1);
    insertElement(89, &front2, &rear2);
    insertElement(9, &front1, &rear1);
    insertElement(20, &front2, &rear2);
    insertElement(56, &front2, &rear2);
    insertElement(6, &front2, &rear2);
    insertElement(67, &front1, &rear1);
    displayQueue(2, front1, front2, rear1, rear2);

    deleteElement(&front1, &rear1);
    deleteElement(&front2, &rear2);
    displayQueue(2, front1, front2, rear1, rear2);
}

void insertElement(int data, struct priorityQueue **front, struct priorityQueue **rear){
    struct priorityQueue *newNode = (struct priorityQueue*)malloc(sizeof(struct priorityQueue));
    newNode->data = data;
    newNode->next = NULL;
    if(*rear == NULL){
        *rear = newNode;
        *front = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}
void deleteElement(struct priorityQueue **front, struct priorityQueue **rear){
    if(*front == NULL){
        printf("Queue is Empty :\n");
        return;
    }
    if(*front == *rear){
        printf("Deleted Element = %d\n", (*front)->data);
        *front = NULL;
        *rear = NULL;
        return;
    }
    struct priorityQueue *temp = *front;
    *front = (*front)->next;
    printf("Deleted Element = %d\n", temp->data);
    free(temp);
}
void displayQueue(int lists, struct priorityQueue *front1, struct priorityQueue *front2,
    struct priorityQueue *rear1, struct priorityQueue *rear2)
{
    struct priorityQueue *temp;
    int counter = 0, flag = 0;
    while(counter < lists){
        if(flag == 0)
            temp = front1;
        else if(flag == 1)
            temp = front2;
        do{
            printf("%d\t", temp->data);
            temp = temp->next;
        }while(temp != NULL);
        printf("\n");
        counter++;
        flag++;
    }
}
