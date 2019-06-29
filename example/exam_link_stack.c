//
// Created by Administrator on 2019/6/29 0029.
//

#include <stdlib.h>
#include <stdio.h>

typedef void *DataType;

typedef struct node {
    DataType data;
    struct node *next;
} StackNode, *PStackNode;

typedef struct {
    PStackNode top;
} LinkStack, *PLinkStack;

PLinkStack Init_LinkStack() {
    PLinkStack s;
    s = malloc(sizeof(LinkStack));
    if (s) s->top = NULL;
    return s;
}

int Push_LinkStack(PLinkStack s, DataType x) {
    PStackNode p;
    p = malloc(sizeof(StackNode));
    if (!p) {
        printf("内存溢出");
        return 0;
    }
    p->data = x;
    p->next = s->top;
    s->top = p;
    return 1;
}

int Empty_LinkStack(PLinkStack s) {
    return s->top == NULL;
}

int Pop_LinkStack(PLinkStack s, DataType x) {
    PStackNode p;
    if (Empty_LinkStack(s)) {
        printf("栈空，不能出栈");
        return 0;
    }
    x = s->top->data;
    p = s->top;
    s->top = s->top->next;
    free(p);
    return 1;
}

int GetTop_LinkStack(PLinkStack s, DataType x) {
    if (Empty_LinkStack(s)) {
        printf("栈空，不能出栈");
        return 0;
    }
    x = s->top->data;
    return 1;
}

void Destory_LinkStack(PLinkStack s) {
    PStackNode p, q;
    if (s) {
        p = s->top;
        while (p) {
            q = p;
            p = p->next;
            free(q);
        }
        free(s);
    }
    s = NULL;
}