#include<stdio.h>
#include<stdlib.h>
#define SIZE 15

void insertNode(int arr[], int data, int i);
void deleteNode(int data);
void searchMin();
void searchMax(int arr[]);
void searchAnyNode(int arr[], int data);
void InOrder(int arr[], int i);

int main(){
    int arr[SIZE] = {};
    int i = 0;
    insertNode(arr, 25, i);
    insertNode(arr, 5, i);
    insertNode(arr, 50, i);
    insertNode(arr, 20, i);
    insertNode(arr, 4, i);
    insertNode(arr, -2, i);
    insertNode(arr, 100, i);

    searchAnyNode(arr, 100);
    InOrder(arr, i);
}

void insertNode(int arr[], int data, int i){
    if(arr[i] == 0 && (sizeof(arr)/sizeof(int)) < SIZE - 1){
        arr[i] = data;
        return;
    }
    if(data < arr[i]){
        i = (2*i)+1;
        insertNode(arr, data, i);
    }
    if(data > arr[i]){
        i = (2*i)+2;
        insertNode(arr, data, i);
    }
}
void InOrder(int arr[], int i){
    if(i > SIZE-1)
        return;
    InOrder(arr, (2*i)+1);
    printf("%d\t", arr[i]);
    InOrder(arr, (2*i)+2);
}
void searchAnyNode(int arr[], int data){
    for(int i = 0; i < SIZE-1; i++){
        if(arr[i] == data){
            printf("Data = %d\n", arr[i]);
            return;
        }
    }
    printf("Data not Found \n");
}
