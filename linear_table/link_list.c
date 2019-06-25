// 单向链表实现
// Created by xiekun on 2019/6/21.
//

#include "link_list.h"
#include <stdlib.h>
#include <stdio.h>

PLinkList Init_LinkList() {
    PLinkList list = malloc(sizeof(LinkList));
    if (list) {
        list->header = NULL;
        list->length = 0;
        return list;
    }
    return NULL;
}

int Destroy_LinkList(PLinkList list) {
    PLNode item = list->header;
    while (item) {
        PLNode next = item->next;
        free(item);
        item = next;
    }
    free(list);
    return 1;
}

int Length_LinkList(PLinkList list) {
    if (list) {
        return list->length;
    }
    return -1;
}

int Locate_LinkList(PLinkList list, void *item) {
    PLNode iter = list->header;
    int index = 0;
    while (iter) {
        index++;
        if (iter->data == item) {
            return index;
        }
        iter = iter->next;
    }
    return -1;
}

int Insert_LinkList(PLinkList list, int index, void *item) {
    PLNode iter = list->header;
    if (index < 0 || index > list->length) {
        return 0;
    }

    if (index == 0) {
        PLNode insert = malloc(sizeof(LNode));
        insert->data = item;
        insert->next = iter;
        list->header = insert;
        return 1;
    }

    int i = 0;
    PLNode previous = NULL, posterior = NULL;
    while (iter) {
        if (i == index - 1) {
            previous = iter;
        }
        if (i == index) {
            posterior = iter;
            break;
        }
        iter = iter->next;
        i++;
    }
    if (previous && posterior) {
        PLNode insert = malloc(sizeof(LNode));
        insert->data = item;
        insert->next = posterior;
        previous->next = insert;
        return 1;
    }
    return 0;
}

int Delete_LinkList(PLinkList list, int index) {
    PLNode iter = list->header;
    int i = 0;
    PLNode previous = NULL, posterior = NULL, deleted = NULL;
    while (iter) {
        i++;
        if (i == index - 1) {
            previous = iter;
        }
        if (i == index) {
            deleted = iter;
        }
        if (i == index + 1) {
            posterior = iter;
            break;
        }
        iter = iter->next;
    }
    if (previous && deleted && posterior) {
        previous->next = posterior;
        free(deleted);
        return 1;
    }
    return 0;
}

int Add_LinkList(PLinkList list, void *item) {
    if (list) {
        PLNode header = list->header;
        PLNode node = malloc(sizeof(LNode));
        node->data = item;
        node->next = NULL;
        if (header == NULL) {
            list->header = node;
            list->length++;
            return 1;
        }
        while (header) {
            if (header->next == NULL) {
                header->next = node;
                list->length++;
                return 1;
            }
            header = header->next;
        }
    }
    return 0;
}

void test_LinkList() {
    PLinkList list = Init_LinkList();
    Add_LinkList(list, "1");
    Add_LinkList(list, "2");
    Add_LinkList(list, "3");
    Add_LinkList(list, "4");
    Add_LinkList(list, "5");
    Add_LinkList(list, "6");
    Insert_LinkList(list, 3, "7");
    Delete_LinkList(list, 4);
    int i = 0;
    PLNode item = list->header;
    while (item) {
        printf("item %d is : %s\n", i, (char *) item->data);
        item = item->next;
        i++;
    }
    Destroy_LinkList(list);
}