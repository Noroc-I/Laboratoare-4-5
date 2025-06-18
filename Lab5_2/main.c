#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcs.h"
int main(void) {
    srand(time(NULL));
    int *array = NULL, option = 0, size=0;
    while(1) {
        printf("1. Create sorted array\n");
        printf("2. Print array\n");
        printf("3. Linear search\n");
        printf("4. Binary search\n");
        printf("5. Free array\n");
        printf("6. Exit\n");
        printf("Option: ");
        option = bound_read(1,6);
        switch(option) {
            case 1: {
                if(array) {
                    printf("Array already exists\n");
                    break;
                }
                printf("Array size: ");
                do {
                    fflush(stdin);
                    scanf("%d", &size);
                } while(size < 1);
                array = createArray(size);
                mergeSort(array, 0, size-1);
            } break;
            case 2: {
                if(!array) {
                    printf("Array is empty\n");
                    break;
                }
                printArray(array,size);
            } break;
            case 3: {
                if(!array) {
                    printf("Array is empty\n");
                    break;
                }
                int search_value = rand()%size;
                struct timespec start,end;
                clock_gettime(CLOCK_MONOTONIC,&start);
                int return_value = linearSearch(array, size, search_value);
                clock_gettime(CLOCK_MONOTONIC,&end);
                double time_taken = (end.tv_sec - start.tv_sec) * 1e9;
                time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
                if(return_value)
                    printf("Found in %f seconds\n", time_taken);
                else printf("Not found in %f seconds\n", time_taken);
            } break;
            case 4: {
                if(!array) {
                    printf("Array is empty\n");
                    break;
                }
                int search_value = rand()%size;
                struct timespec start,end;
                clock_gettime(CLOCK_MONOTONIC,&start);
                int return_value = binarySearch(array, size, search_value);
                clock_gettime(CLOCK_MONOTONIC,&end);
                double time_taken = (end.tv_sec - start.tv_sec) * 1e9;
                time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
                if(return_value)
                    printf("Found in %f seconds\n", time_taken);
                else printf("Not found in %f seconds\n", time_taken);
            } break;
            case 5: {
                if(!array) {
                    printf("Array is empty\n");
                    break;
                }
                free(array);
                array = NULL;
            }break;
            case 6: return 0;
            default: break;
        }

    }
}
