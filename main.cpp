#include <iostream>
#include "sort.h"

int main() {
    int test[] = {3, 2, 8, 2, 7, 5, 1, 9, 6};
    size_t length = sizeof(test) / sizeof(int);
    cout << length << endl;
    bubbleSort(test, length);


    printArr(test, length);
    return 0;
}