//
// Created by xiekun on 2019/6/25.
//

#include "link_queue.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

PLinkQueue PLinkQueue_init() {
    PLinkQueue queue = malloc(sizeof(LinkQueue));
    if (queue) {
        queue->head = NULL;
        queue->tail = NULL;
        queue->length = 0;
    }
    return queue;
}

int PLinkQueue_add(PLinkQueue queue, void *item) {
    if (queue && !PLinkQueue_isFull(queue)) {
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

void *PLinkQueue_peek(PLinkQueue queue) {
    if (queue && !PLinkQueue_isEmpty(queue)) {
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

int PLinkQueue_destroy(PLinkQueue queue) {
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

int PLinkQueue_isFull(PLinkQueue queue) {
    if (queue->length >= MAX_SIZE) {
        return 1;
    }
    return 0;
}

int PLinkQueue_isEmpty(PLinkQueue queue) {
    if (queue->length == 0) {
        return 1;
    }
    return 0;
}

void test_PLinkQueue() {
    PLinkQueue queue = PLinkQueue_init();
    PLinkQueue_add(queue, "1");
    PLinkQueue_add(queue, "2");
    PLinkQueue_add(queue, "3");
    PLinkQueue_add(queue, "4");
    PLinkQueue_add(queue, "5");
    PLinkQueue_add(queue, "6");
    PLinkQueue_add(queue, "7");
    PLinkQueue_add(queue, "8");
    PLinkQueue_add(queue, "9");
    PLinkQueue_add(queue, "10");
    PLinkQueue_add(queue, "11");
    PLinkQueue_add(queue, "12");
    while (!PLinkQueue_isEmpty(queue)) {
        printf("%s\n", (char *) PLinkQueue_peek(queue));
    }
    PLinkQueue_destroy(queue);
}