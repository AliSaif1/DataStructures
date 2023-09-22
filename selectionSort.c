#include<stdio.h>
#define SIZE 10

void selectionSort(int arr[]);

int main(){
    int arr[SIZE] = {10, 5, 15, 45, 35, 25, 40, 30, 50, 20};
    selectionSort(arr);
    for(int i = 0; i < SIZE; i++)
        printf("%d\t", arr[i]);
}

void selectionSort(int arr[]){
    for(int i = 0; i < SIZE-1; i++){
        int min = i;
        for(int k = i; k < SIZE; k++){
            if(arr[min] > arr[k])
                min = k;
        }
        int j = arr[min];
        arr[min] = arr[i];
        arr[i] = j;
    }
}
