//
// Created by xiekun on 2019/6/24.
//
#include <stdlib.h>
#include "seq_stack.h"
#include <stdio.h>

PStack PStack_Init() {
    PStack stack = malloc(sizeof(Stack));
    if (stack) {

        stack->length = 0;
        return stack;
    }
    return NULL;
}

int PStack_Push(PStack stack, void *item) {
    if (stack) {
        if (stack->length >= MAX_SIZE) {
            return 0;
        }
        stack->data[stack->length] = item;
        stack->length++;
        return stack->length;
    }
    return 0;
}

void *PStack_Pop(PStack stack) {
    if (stack) {
        if (stack->length <= 0) {
            return NULL;
        }
        void *item = stack->data[stack->length - 1];
        stack->length--;
        return item;
    }
    return NULL;
}

int PStack_Destroy(PStack stack) {
    if (stack) {
        free(stack->data);
        free(stack);
        stack = NULL;
        return 1;
    }
    return 0;
}

void test_PStack() {
    PStack stack = PStack_Init();
    PStack_Push(stack, "1");
    PStack_Push(stack, "2");
    PStack_Push(stack, "3");
    PStack_Push(stack, "4");
    void *item;
    while ((item = PStack_Pop(stack))) {
        printf("%s\n", (char *) item);
    }
    PStack_Destroy(stack);
}