#include<stdio.h>
#define SIZE 10

void push(int data);
void pop();
void displayStack();

int top = -1;
int arr[SIZE] = {0};
int main(){
    push(10);
    push(12);
    push(15);
    push(8);
    displayStack();
    printf("\n");

    pop();
    pop();
    printf("\n");
    displayStack();
}

void push(int data){
    if(top > SIZE - 1){
        printf("Stack Over Flow : \n");
        return;
    }
    top = top + 1;
    arr[top] = data;
}
void pop(){
    if(top < 0){
        printf("Stack Under Flow : \n");
        return;
    }
    int pop = arr[top];
    printf("Popped Value = %d\n", pop);
    top = top - 1;
}
void displayStack(){
    for(int i = top; i >= 0; i--)
        printf("%d\t", arr[i]);
}
