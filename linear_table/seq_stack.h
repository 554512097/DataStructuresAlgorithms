//
// Created by xiekun on 2019/6/24.
//

#ifndef DATASTRUCTURESALGORITHMS_SEQ_STACK_H
#define DATASTRUCTURESALGORITHMS_SEQ_STACK_H

#define MAX_SIZE 100

typedef struct {
    void *data[MAX_SIZE];
    int length;
} Stack, *PStack;

PStack PStack_Init_impl();

int PStack_Push_impl(PStack stack, void *item);

void *PStack_Pop_impl(PStack stack);

int PStack_Destroy_impl(PStack);

void test_PStack();

#endif //DATASTRUCTURESALGORITHMS_SEQ_STACK_H
