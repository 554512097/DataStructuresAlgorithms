//
// Created by xiekun on 2019/6/25.
//

#include "seq_queue.h"
#include <stdlib.h>
#include <stdio.h>

PSeqQueue PSeqQueue_init() {
    PSeqQueue queue = malloc(sizeof(SeqQueue));
    queue->head = 0;
    queue->tail = 0;
}

int PSeqQueue_add(PSeqQueue queue, void *item) {
    if (queue && !PSeqQueue_isFull(queue)) {
        queue->data[queue->tail++] = item;
        return 1;
    }
    return 0;
}

void *PSeqQueue_peek(PSeqQueue queue) {
    if (queue && !PSeqQueue_isEmpty(queue)) {
        return queue->data[queue->head++];
    }
    return NULL;
}

int PSeqQueue_destroy(PSeqQueue queue) {
    if (queue) {
        free(queue);
        queue = NULL;
        return 1;
    }
    return 0;
}

int PSeqQueue_isFull(PSeqQueue queue) {
    if (queue) {
        if ((queue->tail - queue->head) >= 10) {
            return 1;
        }
    }
    return 0;
}

int PSeqQueue_isEmpty(PSeqQueue queue) {
    if (queue) {
        if (queue->tail == queue->head) {
            return 1;
        }
    }
    return 0;
}

void test_PSeqQueue() {
    PSeqQueue queue = PSeqQueue_init();
    PSeqQueue_add(queue, "1");
    PSeqQueue_add(queue, "2");
    PSeqQueue_add(queue, "6");
    PSeqQueue_add(queue, "3");
    PSeqQueue_add(queue, "11");
    PSeqQueue_add(queue, "5");
    PSeqQueue_add(queue, "4");
    PSeqQueue_add(queue, "9");
    PSeqQueue_add(queue, "8");
    PSeqQueue_add(queue, "7");
    PSeqQueue_add(queue, "10");
    while (!PSeqQueue_isEmpty(queue)) {
        printf("%s\n", (char *) PSeqQueue_peek(queue));
    }
    PSeqQueue_destroy(queue);
}