#include<stdio.h>
#define SIZE 10

void mergeSorting(int arr[], int start, int last);
void mergeSort(int arr[], int start, int mid, int last);

int main(){
    int arr[SIZE] = {20, 15, 5, 10, 25, 40, 25, 35, 30, 45};
    mergeSorting(arr, 0, SIZE-1);
    for(int i = 0; i < SIZE; i++)
        printf("%d\t", arr[i]);
}

void mergeSorting(int arr[], int start, int last){
    int size = last-start+1;
    if(size <= 1)
        return;
    int mid = (last+start)/2;
    mergeSorting(arr, start, mid);
    mergeSorting(arr, mid+1, last);
    mergeSort(arr, start, mid+1, last);
}
void mergeSort(int arr[], int start, int mid, int last){
    int temp[last-start+1];
    int i = start, j = mid, k = -1;
    while(i < mid && j <= last){
        if(arr[i] <= arr[j]){
            k += 1;
            temp[k] = arr[i];
            i += 1;
        }
        else{
            k += 1;
            temp[k] = arr[j];
            j += 1;
        }
    }
    if(i >= mid){
        while(j <= last){
            k += 1;
            temp[k] = arr[j];
            j += 1;
        }
    }
    else{
        while(i < mid){
            k += 1;
            temp[k] = arr[i];
            i += 1;
        }
    }
    for(int i = 0; i <= k; i++){
        arr[start+i] = temp[i];
    }
}
