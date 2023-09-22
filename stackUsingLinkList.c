#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct{
    int data;
    struct stack *next;
}stack;

void push(int data);
void pop();
void displayStack();

stack *top = NULL;
int main(){
    push(20);
    push(25);
    push(12);
    push(0);
    push(3);
    displayStack();printf("\n");

    pop();
    pop();
    displayStack();
}

void push(int data){
    stack *temp = (stack*) malloc(sizeof(stack));
    temp->data = data;
    temp->next = top;
    top = temp;
}
void pop(){
    if(top == NULL){
        printf("Stack is Empty : \n");
        exit(0);
    }
    stack *temp = top;
    top = top->next;
    printf("Popped Data = %d\n", temp->data);
    free(temp);
}
void displayStack(){
    stack *temp = top;
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
