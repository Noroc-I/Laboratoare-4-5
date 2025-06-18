
#ifndef FUNCS_H
#define FUNCS_H

int bound_read(int low, int high);

int* createArray(int size);

void printArray(const int* arr, int size);

void bubbleSort(int* arr, int size);

void merge(int arr[], int left, int mid, int right);

void mergeSort(int* arr, int left, int right);

#endif //FUNCS_H
