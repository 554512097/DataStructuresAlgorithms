//
// Created by xiekun on 2019/6/24.
//
#include <stdlib.h>
#include "seq_stack.h"
#include <stdio.h>

PStack PStack_Init_impl() {
    PStack stack = malloc(sizeof(Stack));
    if (stack) {

        stack->length = 0;
        return stack;
    }
    return NULL;
}

int PStack_Push_impl(PStack stack, void *item) {
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

void *PStack_Pop_impl(PStack stack) {
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

int PStack_Destroy_impl(PStack stack) {
    if (stack) {
        free(stack->data);
        free(stack);
        stack = NULL;
        return 1;
    }
    return 0;
}

void test_PStack() {
    PStack stack = PStack_Init_impl();
    PStack_Push_impl(stack, "1");
    PStack_Push_impl(stack, "2");
    PStack_Push_impl(stack, "3");
    PStack_Push_impl(stack, "4");
    void *item;
    while ((item = PStack_Pop_impl(stack))) {
        printf("%s\n", (char *) item);
    }
    PStack_Destroy_impl(stack);
}