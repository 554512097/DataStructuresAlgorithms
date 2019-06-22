// 无头结点单向链表实现
// Created by xiekun on 2019/6/21.
//

#include "link_list.h"
#include <stdlib.h>
#include <stdio.h>

PLinkList Init_LinkList() {
    PLinkList list = malloc(sizeof(LNode));
    if (list) {
        list->data = NULL;
        list->next = NULL;
        return list;
    }
    return NULL;
}

int Destroy_LinkList(PLinkList list) {
    while (list) {
        free(list);
        list = list->next;
    }
    return 1;
}

int Length_LinkList(PLinkList list) {
    PLinkList header = list;
    int length = 0;
    while (header) {
        length++;
        header = header->next;
    }
    return length;
}

int Locate_LinkList(PLinkList list, void *item) {
    PLinkList header = list;
    int index = 0;
    while (header) {
        index++;
        if (header->data == item) {
            return index;
        }
        header = header->next;
    }
    return -1;
}

int Insert_LinkList(PLinkList list, int index, void *item) {
    PLinkList header = list;
    int i = 0;
    PLinkList previous = NULL, posterior = NULL;
    while (header) {
        i++;
        if (i == index - 1) {
            previous = header;
        }
        if (i == index) {
            posterior = header;
            break;
        }
        header = header->next;
    }
    if (previous && posterior) {
        PLinkList insert = malloc(sizeof(LNode));
        insert->data = item;
        insert->next = posterior;
        previous->next = insert;
        return 1;
    }
    return 0;
}

int Delete_LinkList(PLinkList list, int index) {
    PLinkList header = list;
    int i = 0;
    PLinkList previous = NULL, posterior = NULL, deleted = NULL;
    while (header) {
        i++;
        if (i == index - 1) {
            previous = header;
        }
        if (i == index) {
            deleted = header;
        }
        if (i == index + 1) {
            posterior = header;
            break;
        }
        header = header->next;
    }
    if (previous && deleted && posterior) {
        previous->next = posterior;
        free(deleted);
        return 1;
    }
    return 0;
}

int Add_LinkList(PLinkList list, void *item) {
    if (list && list->data == NULL) {
        list->data = item;
        return 1;
    }
    PLinkList header = list;
    while (header) {
        if (header->next == NULL) {
            PLinkList node = malloc(sizeof(LNode));
            node->data = item;
            node->next = NULL;
            header->next = node;
            return 1;
        }
        header = header->next;
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
    while (list) {
        printf("item %d is : %s\n", i, (char *) list->data);
        list = list->next;
        i++;
    }
}