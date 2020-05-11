//
// Created by xiekun on 2019/6/24.
//

#ifndef DATASTRUCTURESALGORITHMS_LINK_STACK_H
#define DATASTRUCTURESALGORITHMS_LINK_STACK_H

typedef struct stack_node {
    void *data;
    struct stack_node *bottom;
} SNode, *PSNode;

typedef struct {
    int length;
    PSNode top;
} LinkStack, *PLinkStack;

PLinkStack PLinkStack_Init_impl();

int PLinkStack_Push_impl(PLinkStack, void *);

void *PLinkStack_Pop_impl(PLinkStack stack);

int PLinkStack_Destroy_impl(PLinkStack stack);

void test_PLinkStack();

#endif //DATASTRUCTURESALGORITHMS_LINK_STACK_H
