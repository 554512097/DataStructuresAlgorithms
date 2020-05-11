//
// Created by Administrator on 2020/5/2 0002.
//

#include "Stack.h"

template<class T>
T &Stack<T>::pop() {
    auto data = top->data;
    top = top->bottom;
    return *data;
}

template<class T>
void Stack<T>::push(T &item) {
    auto frame = new StackFrame<T>();
    frame->data = item;
    if (top == nullptr) {
        frame->bottom = nullptr;
        top = frame;
    } else {
        frame->bottom = top;
        top = frame;
    }
}

void testStack() {
    auto stack = new Stack<string>();
}
