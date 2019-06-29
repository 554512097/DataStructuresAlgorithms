//
// Created by Administrator on 2019/6/29 0029.
//

#include <stdlib.h>
#include <stdio.h>

typedef void *DataType;

typedef struct node {
    DataType data;
    struct node *next;
} QNode, *PQNode;

typedef struct {
    PQNode front, rear;
} LinkQueue, *PLinkQueue;

PLinkQueue Init_LinkQueue() {
    PLinkQueue q;
    q = malloc(sizeof(LinkQueue));
    if (q) {
        q->front = NULL;
        q->rear = NULL;
    }
    return q;
}

int Empty_LinkQueue(PLinkQueue q) {
    if (q && q->front == NULL && q->rear == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int In_LinkQueue(PLinkQueue q, DataType x) {
    PQNode p;
    p = malloc(sizeof(QNode));
    if (!p) {
        printf("内存溢出");
        return 0;
    }
    p->data = x;
    p->next = NULL;
    if (Empty_LinkQueue(q)) { q->rear = q->front = p; }
    else {
        q->rear->next = p;
        q->rear = p;
    }
    return 1;
}

int Out_LinkQueue(PLinkQueue q, DataType x) {
    PQNode p;
    if (Empty_LinkQueue(q)) {
        printf("队空");
        return 0;
    }
    x = q->front->data;
    p = q->front;
    q->front = q->front->next;
    free(p);
    if (!q->front)
        q->rear = NULL;
    return 1;
}

int Front_LinkQueue(PLinkQueue q, DataType x) {
    if (Empty_LinkQueue(q)) {
        printf("队空");
        return 0;
    }
    x = q->front->data;
    return 1;
}

void Destroy_LinkQueue(PLinkQueue q) {
    PQNode p, s;
    if (q) {
        while (q->front) {
            p = q->front;
            q->front = q->front->next;
            free(p);
        }
        free(q);
    }
    q = NULL;
}