// 双向链表实现
// Created by xiekun on 2019/6/22.
//

#include "double_link_list.h"
#include <stdlib.h>
#include <stdio.h>

PDLinkList PDLinkList_Init() {
    PDLinkList list = malloc(sizeof(DLinkList));
    if (list) {
        list->head = NULL;
        list->length = 0;
        return list;
    }
    return NULL;
}

int Destroy_PDLinkList(PDLinkList list) {
    PDNode iter = list->head;
    while (iter) {
        PDNode next = iter->next;
        iter->last = NULL;
        free(iter->data);
        free(iter);
        iter = next;
    }
    free(list);
    list = NULL;
    return 0;
}

int Length_PDLinkList(PDLinkList list) {
    if (list) {
        return list->length;
    }
    return -1;
}

int Locate_PDLinkList(PDLinkList list, void *item) {
    PDNode iter = list->head;
    int index = 0;
    while (iter) {
        if (iter->data == item) {
            return index;
        }
        iter = iter->next;
        index++;
    }
    return -1;
}

int Insert_PDLinkList(PDLinkList list, int index, void *item) {
    if (index < 0 || index > list->length) {
        return 0;
    }
    PDNode iter = list->head;
    if (index == 0) {
        PDNode insert = malloc(sizeof(PDNode));
        insert->next = iter;
        insert->data = item;
        insert->last = NULL;
        return 1;
    }
    PDNode previous = NULL;
    int i = 0;
    while (iter) {
        if (i == index - 1) {
            previous = iter;
        }
        if (i == index) {
            PDNode insert = malloc(sizeof(PDNode));
            insert->next = iter;
            insert->data = item;
            insert->last = previous;
            previous->next = insert;
            list->length++;
            return 1;
        }
        iter = iter->next;
        i++;
    }
    return 0;
}

int Delete_PDLinkList(PDLinkList list, int index) {
    if (index < 0 || index > list->length) {
        return 0;
    }
    PDNode iter = list->head;
    if (index == 0) {
        list->head = list->head->next;
        free(iter);
        return 1;
    }
    int i = 0;
    PDNode previous = NULL;
    while (iter) {
        if (i == index - 1) {
            previous = iter;
        }
        if (i == index) {
            previous->next = iter->next;
            free(iter);
            list->length--;
            return 1;
        }
        iter = iter->next;
        i++;
    }
    return 0;
}

int Add_PDLinkList(PDLinkList list, void *item) {
    PDNode add = malloc(sizeof(PDNode));
    add->next = NULL;
    add->data = item;
    add->last = NULL;

    PDNode iter = list->head;
    if (!iter) {
        list->head = add;
        list->length++;
        return 1;
    }
    while (iter) {
        if (!iter->next) {
            iter->next = add;
            add->last = iter;
            list->length++;
            return 1;
        }
        iter = iter->next;
    }
    return 0;
}

void test_PDLinkList() {
    PDLinkList list = PDLinkList_Init();
    Add_PDLinkList(list, "1");
    Add_PDLinkList(list, "2");
    Add_PDLinkList(list, "3");
    Add_PDLinkList(list, "4");
    Add_PDLinkList(list, "5");
    Add_PDLinkList(list, "6");
    Add_PDLinkList(list, "7");
    Insert_PDLinkList(list, 2, "8");
    Delete_PDLinkList(list, 5);
    int index = Locate_PDLinkList(list, "4");
    printf("4 index is : %d\n", index);
    PDNode iter = list->head;
    while (iter) {
        printf("%s\n", (char *) iter->data);
        iter = iter->next;
    }
}