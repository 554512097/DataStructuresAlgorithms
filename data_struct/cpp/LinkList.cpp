//
// Created by Administrator on 2020/5/2 0002.
//

#include "LinkList.h"

template<class T>
LinkList<T>::LinkList() {
    header = nullptr;
    tailer = nullptr;
    size = 0;
}

template<class T>
T &LinkList<T>::operator[](int i) {
    assert(i < size);
    Node<T> *temp = header;
    for (int j = 0; j <= i; ++j) {
        temp = temp->next;
    }
    return *(temp->data);
}

template<class T>
const T &LinkList<T>::operator[](int i) const {
    return (*this)[i];
}

template<class T>
void LinkList<T>::add(T &item) {
    auto node = new Node<T>();
    node->data = &item;
    node->next = nullptr;
    if (header == nullptr && tailer == nullptr) {
        header = node;
        tailer = node;
    } else {
        tailer->next = node;
        tailer = node;
    }
    size++;
}

template<class T>
int LinkList<T>::getSize() const {
    return size;
}

template<class T>
void LinkList<T>::foreachIndex(void (*action)(int, const T &)) {
    int index = 0;
    Node<T> *temp = header;
    while (temp != nullptr) {
        action(index, *(temp->data));
        temp = temp->next;
        index++;
    }
}

template<typename T>
void printItem(int index, T item) {
    cout << index << "------------" << item << endl;
}

void testLinkList() {
    auto list = new LinkList<int>();
    int *arr = new int[16]();
    for (int i = 0; i < 16; ++i) {
        arr[i] = i;
        list->add(arr[i]);
    }
    list->foreachIndex(printItem);
    cout << "--------------------------" << endl;
    (*list)[1] = 5;
    list->foreachIndex(printItem);

    cout << "size is " << list->getSize() << endl;
}