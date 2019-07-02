//
// Created by xiekun on 2019/6/25.
//

#include "link_queue.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

PLinkQueue PLinkQueue_init_impl() {
    PLinkQueue queue = malloc(sizeof(LinkQueue));
    if (queue) {
        queue->head = NULL;
        queue->tail = NULL;
        queue->length = 0;
    }
    return queue;
}

int PLinkQueue_add_impl(PLinkQueue queue, void *item) {
    if (queue && !PLinkQueue_isFull_impl(queue)) {
        PQNode add = malloc(sizeof(QNode));
        add->data = item;
        add->next = NULL;
        if (queue->tail) {
            queue->tail->next = add;
            queue->tail = add;
        } else {
            queue->tail = add;
            queue->head = add;
        }
        queue->length++;
        return 1;
    }
    return 0;
}

void *PLinkQueue_peek_impl(PLinkQueue queue) {
    if (queue && !PLinkQueue_isEmpty_impl(queue)) {
        PQNode peek = queue->head;
        if (peek) {
            if (queue->head->next) {
                queue->head = queue->head->next;
            } else {
                queue->head = NULL;
                queue->tail = NULL;
            }
            queue->length--;
            return peek->data;
        }
    }
    return NULL;
}

int PLinkQueue_destroy_impl(PLinkQueue queue) {
    if (queue) {
        PQNode next;
        while (queue->head) {
            next = queue->head->next;
            free(queue->head);
            queue->head = next;
        }
        free(queue);
        return 1;
    }
    return 0;
}

int PLinkQueue_isFull_impl(PLinkQueue queue) {
    if (queue->length >= MAX_SIZE) {
        return 1;
    }
    return 0;
}

int PLinkQueue_isEmpty_impl(PLinkQueue queue) {
    if (queue->length == 0) {
        return 1;
    }
    return 0;
}

void test_PLinkQueue() {
    PLinkQueue queue = PLinkQueue_init_impl();
    PLinkQueue_add_impl(queue, "1");
    PLinkQueue_add_impl(queue, "2");
    PLinkQueue_add_impl(queue, "3");
    PLinkQueue_add_impl(queue, "4");
    PLinkQueue_add_impl(queue, "5");
    PLinkQueue_add_impl(queue, "6");
    PLinkQueue_add_impl(queue, "7");
    PLinkQueue_add_impl(queue, "8");
    PLinkQueue_add_impl(queue, "9");
    PLinkQueue_add_impl(queue, "10");
    PLinkQueue_add_impl(queue, "11");
    PLinkQueue_add_impl(queue, "12");
    while (!PLinkQueue_isEmpty_impl(queue)) {
        printf("%s\n", (char *) PLinkQueue_peek_impl(queue));
    }
    PLinkQueue_destroy_impl(queue);
}