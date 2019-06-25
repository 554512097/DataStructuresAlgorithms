//
// Created by xiekun on 2019/6/25.
//

#include "link_stack.h"
#include <stdlib.h>
#include <stdio.h>

PLinkStack PLinkStack_Init() {
    PLinkStack stack = malloc(sizeof(LinkStack));
    if (stack) {
        stack->length = 0;
        stack->top = NULL;
    }
    return stack;
}

int PLinkStack_Push(PLinkStack stack, void *item) {
    PSNode push = malloc(sizeof(SNode));
    push->data = item;
    push->bottom = NULL;
    if (stack) {
        PSNode top = stack->top;
        if (top) {
            push->bottom = top;
            stack->top = push;
        } else {
            stack->top = push;
        }
        stack->length++;
        return 1;
    }
    return 0;
}

void *PLinkStack_Pop(PLinkStack stack) {
    if (stack) {
        PSNode top = stack->top;
        if (top) {
            stack->top = top->bottom;
            stack->length--;
            return top->data;
        }
    }
    return NULL;
}

int PLinkStack_Destroy(PLinkStack stack) {
    if (stack) {
        PSNode next;
        while (stack->top) {
            next = stack->top->bottom;
            free(stack->top);
            stack->top = next;
        }
        free(stack);
        stack = NULL;
        return 1;
    }
    return 0;
}

void test_PLinkStack() {
    PLinkStack stack = PLinkStack_Init();
    PLinkStack_Push(stack, "1");
    PLinkStack_Push(stack, "2");
    PLinkStack_Push(stack, "3");
    PLinkStack_Push(stack, "4");
    PLinkStack_Push(stack, "5");
    PLinkStack_Push(stack, "6");
    void *item;
    while ((item = PLinkStack_Pop(stack))) {
        printf("%s\n", (char *) item);
    }
    PLinkStack_Destroy(stack);
}