//
// Created by Administrator on 2019/6/28 0028.
//

#include <stdlib.h>

#define MAX_SIZE 100

typedef void *DataType;

typedef struct {
    DataType data[MAX_SIZE];
    int top;
} SeqStack, *PSeqStack;

PSeqStack Init_SeqStack() {
    PSeqStack s;
    s = malloc(sizeof(SeqStack));
    if (s) {
        s->top = -1;
    }
    return s;
}

int Empty_SeqStack(PSeqStack s) {
    if (s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int Push_SeqStack(PSeqStack s, DataType x) {
    if (s->top == MAX_SIZE - 1) {
        return 0;
    } else {
        s->top++;
        s->data[s->top] = x;
        return 1;
    }
}

int Pop_SeqStack(PSeqStack s, DataType x) {
    if (Empty_SeqStack(s)) {
        return 0;
    } else {
        x = s->data[s->top];
        s->top--;
        return 1;
    }
}

int GetTop_SeqStack(PSeqStack s, DataType x) {
    if (Empty_SeqStack(s)) {
        return 0;
    } else {
        x = s->data[s->top];
        return 1;
    }
}

void DeStroy_SeqStack(PSeqStack s) {
    if (s) {
        free(s);
    }
    s = NULL;
    return;
}