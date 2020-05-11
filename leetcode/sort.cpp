//
// Created by Administrator on 2020/5/11 0011.
//

#include "sort.h"

void printArr(const int *arr, size_t arrLength) {
    for (int i = 0; i < arrLength; ++i) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void bubbleSort(int *arr, size_t arrLength) {
    for (int i = 0; i < arrLength; i++) {
        for (int j = 0; j < arrLength - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
