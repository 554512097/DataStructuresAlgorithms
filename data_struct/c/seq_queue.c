//
// Created by xiekun on 2019/6/25.
//

#include "seq_queue.h"
#include <stdlib.h>
#include <stdio.h>

PSeqQueue PSeqQueue_init_impl() {
    PSeqQueue queue = malloc(sizeof(SeqQueue));
    queue->head = 0;
    queue->tail = 0;
}

int PSeqQueue_add_impl(PSeqQueue queue, void *item) {
    if (queue && !PSeqQueue_isFull_impl(queue)) {
        queue->data[queue->tail++] = item;
        return 1;
    }
    return 0;
}

void *PSeqQueue_peek_impl(PSeqQueue queue) {
    if (queue && !PSeqQueue_isEmpty_impl(queue)) {
        return queue->data[queue->head++];
    }
    return NULL;
}

int PSeqQueue_destroy_impl(PSeqQueue queue) {
    if (queue) {
        free(queue);
        queue = NULL;
        return 1;
    }
    return 0;
}

int PSeqQueue_isFull_impl(PSeqQueue queue) {
    if (queue) {
        if ((queue->tail - queue->head) >= 10) {
            return 1;
        }
    }
    return 0;
}

int PSeqQueue_isEmpty_impl(PSeqQueue queue) {
    if (queue) {
        if (queue->tail == queue->head) {
            return 1;
        }
    }
    return 0;
}

void test_PSeqQueue() {
    PSeqQueue queue = PSeqQueue_init_impl();
    PSeqQueue_add_impl(queue, "1");
    PSeqQueue_add_impl(queue, "2");
    PSeqQueue_add_impl(queue, "6");
    PSeqQueue_add_impl(queue, "3");
    PSeqQueue_add_impl(queue, "11");
    PSeqQueue_add_impl(queue, "5");
    PSeqQueue_add_impl(queue, "4");
    PSeqQueue_add_impl(queue, "9");
    PSeqQueue_add_impl(queue, "8");
    PSeqQueue_add_impl(queue, "7");
    PSeqQueue_add_impl(queue, "10");
    while (!PSeqQueue_isEmpty_impl(queue)) {
        printf("%s\n", (char *) PSeqQueue_peek_impl(queue));
    }
    PSeqQueue_destroy_impl(queue);
}