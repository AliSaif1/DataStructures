#include <stdio.h>

void quickSort(int arr[], int first, int last);
void swap (int *a, int *b);

void main () {
    int arr[] = {60,10,20,100,70,30,40,15,200,-1,50};
    //int arr[] = {5,10,15,20};
    int arrSize = sizeof(arr) / sizeof(int);

    quickSort(arr,0, arrSize - 1);

    for (int i = 0; i < arrSize; i++) {
        printf("%d\t", arr[i]);
    }

}

void quickSort(int arr[], int first, int last) {
    int loc = first, left = first, right = last;

    start:
    if (left <= right) {
        while (right != loc) {
            if (arr[loc] >= arr[right]) {
                break;
            }
          right--;
        }
        if (right == loc) {
            quickSort(arr,loc+1, last);
        }
        else{
            swap(&arr[right], &arr[loc]);
            left = loc+1;
            loc = right;
        }
        while (left != loc) {
            if (arr[loc] <= arr[left]) {
                break;
            }
          left++;
        }

        if (left == loc) {
            quickSort(arr, first, loc-1);
        }
        else{
            swap (&arr[left], &arr[loc]);
            right = loc-1;
            loc = left;
        }
    }
    goto start;
}

void swap (int *a, int *b) {
    printf("%d %d\n",*a,*b);
    int temp = *a;
    *a = *b;
    *b = temp;
}
