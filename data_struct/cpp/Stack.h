//
// Created by Administrator on 2020/5/2 0002.
//

#ifndef DATASTRUCTURESANDALGORITHMS_STACK_H
#define DATASTRUCTURESANDALGORITHMS_STACK_H

#include <iostream>
#include <cassert>

using namespace std;

template<class T>
class StackFrame {
public:
    T *data;
    StackFrame *bottom;
};

template<class T>
class Stack {
public:
    StackFrame<T> *top;

    T &pop();

    void push(T &item);
};

void testStack();

#endif //DATASTRUCTURESANDALGORITHMS_STACK_H
