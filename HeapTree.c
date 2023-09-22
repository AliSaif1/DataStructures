#include<stdio.h>
#define SIZE 10

void insertNode(int arr[], int data);
void deleteNode(int arr[], int data);
void displayTree(int arr[]);
void swap(int *largest, int *minimum);
void heapify(int arr[], int i);

int size = 0;
int main(){
    int arr[SIZE] = {0};
    insertNode(arr, 10);
    insertNode(arr, 12);
    insertNode(arr, 25);
    insertNode(arr, 56);
    insertNode(arr, 15);
    insertNode(arr, 20);
    displayTree(arr);

    deleteNode(arr, 56);
    displayTree(arr);
}

void insertNode(int arr[], int data){
    if(size > SIZE){
        printf("Maximum Nodes are Inserted\n");
        return;
    }
    if(size == 0){
        arr[0] = data;
        size++;
        return;
    }
    arr[size] = data;
    size++;
    for(int i = size/2-1; i >= 0; i--){
        heapify(arr, i);
    }
}
void heapify(int arr[], int i){
    if(size == 1){
        printf("Only one Node in Tree:\n");
        return;
    }
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left < size && arr[left] > arr[largest])
        largest = left;
    if(right < size && arr[right] > arr[largest])
        largest = right;
    if(largest != i){
        swap(&arr[largest], &arr[i]);
        heapify(arr, largest);
    }
}
void swap(int *largest, int *minimum){
    int temp = *largest;
    *largest = *minimum;
    *minimum = temp;
}
void displayTree(int arr[]){
    for(int i = 0; i < size; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}
void deleteNode(int arr[], int data){
    if(size < 0){
        printf("Tree has no Nodes to Delete \n");
        return;
    }
    int i;
    for(i = 0; i < size; i++){
        if(arr[i] == data){
            printf("Data Found at index %d = %d\n", i, arr[i]);
            swap(&arr[size-1], &arr[i]);
            size--;
            break;
        }
    }
    for(int i = size/2-1; i >= 0; i--){
        heapify(arr, i);
    }
}
