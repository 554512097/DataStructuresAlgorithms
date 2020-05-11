//
// Created by Administrator on 2020/5/2 0002.
//

//数组线性表

#ifndef DATASTRUCTURESANDALGORITHMS_DYNAMICARRAY_H
#define DATASTRUCTURESANDALGORITHMS_DYNAMICARRAY_H

// ArrayList.h
#pragma once

#include <iostream>
#include <cassert>

using namespace std;

// 数组类模板定义
template<class T>
class ArrayList            // 数组类
{
private:
    T *list;        // T 类型指针，用于存放动态分配的数组内存首地址
    int capacity;        // 数组大小
    int size;       //元素的个数

    // 修改数组的大小
    void resize(int capacity);

public:
    ArrayList(int capacity = 16);            // 构造函数
    ArrayList(const ArrayList<T> &arr);    // 拷贝构造函数
    ~ArrayList();                    // 析构函数

    // 重载 = 运算符
    ArrayList<T> &operator=(const ArrayList<T> &arr);

    // 重载 == 运算符
    bool operator==(const ArrayList<T> &arr);

    // 重载 != 运算符
    bool operator!=(const ArrayList<T> &arr);

    // 重载 [] 运算符
    T &operator[](int i);

    // [] 运算符对 const 的重载
    const T &operator[](int i) const;

    void add(T &item);

    // 取数组的大小
    int getSize() const;

    void foreachIndex(void (*action)(int, const T&));
};

void testArrayList();

#endif //DATASTRUCTURESANDALGORITHMS_DYNAMICARRAY_H
