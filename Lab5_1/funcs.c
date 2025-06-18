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
        arr[i] = rand()%100;
    }
    return arr;
}
void printArray(const int* arr, int size) {
    for(int i=0; i<size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void bubbleSort(int* arr, int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
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
