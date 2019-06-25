//
// Created by xiekun on 2019/6/25.
//

#ifndef DATASTRUCTURESALGORITHMS_SEQ_QUEUE_H
#define DATASTRUCTURESALGORITHMS_SEQ_QUEUE_H

#define MAX_SIZE 10

typedef struct queue {
    void *data[MAX_SIZE];
    int head;
    int tail;
} SeqQueue, *PSeqQueue;

PSeqQueue PSeqQueue_init();

int PSeqQueue_add(PSeqQueue, void *);

void *PSeqQueue_peek(PSeqQueue);

int PSeqQueue_destroy(PSeqQueue);

int PSeqQueue_isFull(PSeqQueue queue);

int PSeqQueue_isEmpty(PSeqQueue queue);

void test_PSeqQueue();

#endif //DATASTRUCTURESALGORITHMS_SEQ_QUEUE_H
