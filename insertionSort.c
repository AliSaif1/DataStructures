#include<stdio.h>
#define size 10

void insertionSort(int arr[]);

int main(){
    int arr[size] = {10, 34, 67, 29, 59, 12, 90, 56, 30, 78};
    insertionSort(arr);
    for(int i = 0; i < size-1; i++)
        printf("%d\t", arr[i]);
}

void insertionSort(int arr[]){
    int temp, j, i;
    for(i = 0; i < size-1; i++){
        temp = arr[i];
        j = i;
        while(j > 0 && temp < arr[j-1]){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
}
