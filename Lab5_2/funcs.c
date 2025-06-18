#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>

int bound_read(int low, int high) {
    int input;
    do {
        fflush(stdin);
        scanf("%d",&input);
    }
        while(input<low || input>high);
    return input;
}

int* createArray(int size) {
    int* arr = malloc(sizeof(int)*size);
    for(int i=0; i<size; i++) {
        arr[i] = rand()%size;
    }
    return arr;
}
void printArray(const int* arr, int size) {
    for(int i=0; i<size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int left, int mid, int right) {
    int i, j;
    int n1 = mid-left+1, n2 = right-mid;
    int leftArr[n1], rightArr[n2];
    for (i=0; i<n1; i++)
        leftArr[i] = arr[left+i];
    for (j=0; j<n2; j++)
        rightArr[j] = arr[mid+1+j];
    i = 0;
    j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int linearSearch(const int* arr, int size, int value) {
    for(int i=0; i<size; ++i) {
        if(arr[i] == value) {
            return 1;
        }
    }
    return 0;
}
int binarySearch(const int* arr, int size, int value) {
    int low = 0;
    int high = size-1;
    while(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid] == value) {
            return 1;
        }
        if(arr[mid] > value) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return 0;
}