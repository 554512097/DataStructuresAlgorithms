//
// Created by xiekun on 2019/6/25.
//

#ifndef DATASTRUCTURESALGORITHMS_LINK_QUEUE_H
#define DATASTRUCTURESALGORITHMS_LINK_QUEUE_H

typedef struct queue_node {
    void *data;
    struct queue_node *next;
} QNode, *PQNode;

typedef struct {
    PQNode head;
    PQNode tail;
    int length;
} LinkQueue, *PLinkQueue;

PLinkQueue PLinkQueue_init_impl();

int PLinkQueue_add_impl(PLinkQueue queue, void *item);

void *PLinkQueue_peek_impl(PLinkQueue queue);

int PLinkQueue_destroy_impl(PLinkQueue queue);

int PLinkQueue_isFull_impl(PLinkQueue queue);

int PLinkQueue_isEmpty_impl(PLinkQueue queue);

void test_PLinkQueue();

#endif //DATASTRUCTURESALGORITHMS_LINK_QUEUE_H
