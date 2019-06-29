//
// Created by Administrator on 2019/6/29 0029.
//

#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

typedef void *DataType;

typedef struct {
    DataType data[MAX_SIZE];
    int front, rear;
} SeqQueue, *PSeqQueue;

PSeqQueue Init_SeqQueue() {
    PSeqQueue q;
    q = malloc(sizeof(SeqQueue));
    if (q) {
        q->front = 0;
        q->rear = 0;
    }
    return q;
}

int Empty_SeqQueue(PSeqQueue q) {
    if (q && q->front == q->rear)
        return 1;
    else
        return 0;
}

int In_SeqQueue(PSeqQueue q, DataType x) {
    if ((q->rear + 1) % MAX_SIZE == q->front) {
        printf("队满");
        return -1;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->data[q->rear] = x;
        return 1;
    }
}

int Out_SeqQueue(PSeqQueue q, DataType x) {
    if (Empty_SeqQueue(q)) {
        printf("队空");
        return -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
        x = q->data[q->front];
        return 1;
    }
}

int Front_SeqQueue(PSeqQueue q, DataType x) {
    if (q->front == q->rear) {
        printf("队空");
        return -1;
    } else {
        x = q->data[(q->front + 1) & MAX_SIZE];
        return 1;
    }
}

void Destroy_SeqQueue(PSeqQueue q) {
    if (q)
        free(q);
    q = NULL;
}