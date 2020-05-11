//
// Created by Administrator on 2020/5/2 0002.
//

#ifndef DATASTRUCTURESANDALGORITHMS_LINKLIST_H
#define DATASTRUCTURESANDALGORITHMS_LINKLIST_H

#include <iostream>
#include <cassert>

using namespace std;

template<class T>
class Node {
public:
    T *data;
    Node *next;
};

template<class T>
class LinkList {
public:
    Node<T> *header;
    Node<T> *tailer;
    int size;

    LinkList();

    // 重载 [] 运算符
    T &operator[](int i);

    // [] 运算符对 const 的重载
    const T &operator[](int i) const;

    void add(T &item);

    // 取数组的大小
    int getSize() const;

    void foreachIndex(void (*action)(int, const T &));
};

void testLinkList();


#endif //DATASTRUCTURESANDALGORITHMS_LINKLIST_H
