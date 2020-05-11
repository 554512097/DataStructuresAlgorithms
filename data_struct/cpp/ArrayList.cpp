//
// Created by Administrator on 2020/5/2 0002.
//

#include "ArrayList.h"


template<class T>
ArrayList<T>::ArrayList(int capacity) {
    assert(capacity >= 0);
    this->capacity = capacity;
    this->size = 0;
    list = new T[capacity];
}

template<class T>
ArrayList<T>::ArrayList(const ArrayList<T> &arr) {
    capacity = arr.capacity;
    size = arr.size;
    list = new T[capacity];
    if (NULL == list) {
        cout << "alloc err!" << endl;
        exit(-1);
    }
    for (int i = 0; i < size; i++) {
        list[i] = arr.list[i];
    }
}

template<class T>
ArrayList<T>::~ArrayList() {
    delete[] list;
    list = NULL;
}

template<class T>
ArrayList<T> &ArrayList<T>::operator=(const ArrayList<T> &arr) {
    if (&arr != this) {
        // 如果本对象中数组大小与 arr 不同，则释放数组原有内存，重新分配
        if (this->capacity != arr.capacity) {
            delete[] list;
            this->capacity = arr.capacity;
            list = new T[this->capacity];
            this->size = arr.size;
        }
        for (int i = 0; i < this->capacity; ++i) {
            list[i] = arr.list[i];
        }
    }
    return *this;
}

template<class T>
bool ArrayList<T>::operator==(const ArrayList<T> &arr) {
    if (this->size != arr.size) {
        return false;
    }
    // 判断内容是否相同
    for (int i = 0; i < this->size; i++) {
        if (this->list[i] != arr.list[i]) {
            return false;
        }
    }
    return true;
}

template<class T>
bool ArrayList<T>::operator!=(const ArrayList<T> &arr) {
    return !(*this == arr);
}

template<class T>
T &ArrayList<T>::operator[](int i) {
    assert(i >= 0 && i < size);                // 检查数组下标是否越界
    return list[i];
}

template<class T>
const T &ArrayList<T>::operator[](int i) const {
    assert(i >= 0 && i < size);
    return list[i];
}

template<class T>
int ArrayList<T>::getSize() const {
    return size;
}

template<class T>
void ArrayList<T>::add(T &item) {
    if (size < capacity) {
        list[size++] = item;
    } else {
        resize(capacity * 2);
        list[size++] = item;
    }
}

template<class T>
void ArrayList<T>::resize(int capacity) {
    assert(capacity >= 0);                    // 检查 capacity 是否非负
    if (this->capacity == capacity) {
        return;
    }
    cout << "resizing ..." << endl;
    T *newList = new T[capacity];
    if (NULL == newList) {
        cout << "alloc err!" << endl;
        exit(-1);
    }

    int n = (capacity > this->capacity) ? this->capacity : capacity;

    for (int i = 0; i < n; i++) {
        newList[i] = list[i];
    }
    delete[] list;
    list = newList;
    this->capacity = capacity;
}

template<class T>
void ArrayList<T>::foreachIndex(void (*action)(int, const T &)) {
    for (int i = 0; i < size; ++i) {
        action(i, list[i]);
    }
}

template<typename T>
void printItem(int index, T item) {
    cout << index << "------------" << item << endl;
}

void testArrayList() {
    auto list = new ArrayList<int>();
    for (int i = 0; i < 16; ++i) {
        list->add(i);
    }
    list->foreachIndex(printItem);

    cout << "--------------------------" << endl;

    for (int j = 0; j < 5; ++j) {
        list->add(j);
    }
    (*list)[1] = 5;
    list->foreachIndex(printItem);

    cout << "size is " << list->getSize() << endl;
}
