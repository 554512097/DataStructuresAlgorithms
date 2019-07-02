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

PSeqQueue PSeqQueue_init_impl();

int PSeqQueue_add_impl(PSeqQueue, void *);

void *PSeqQueue_peek_impl(PSeqQueue);

int PSeqQueue_destroy_impl(PSeqQueue);

int PSeqQueue_isFull_impl(PSeqQueue queue);

int PSeqQueue_isEmpty_impl(PSeqQueue queue);

void test_PSeqQueue();

#endif //DATASTRUCTURESALGORITHMS_SEQ_QUEUE_H
