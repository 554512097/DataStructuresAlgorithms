//链表表相关操作
// Created by xiekun on 2019/6/21.
//

#ifndef DATASTRUCTURESALGORITHMS_LINK_LIST_H
#define DATASTRUCTURESALGORITHMS_LINK_LIST_H

typedef struct link_node {
    void *data;
    struct link_node *next;
} LNode, *PLinkList;

PLinkList Init_LinkList();

int Destroy_LinkList(PLinkList list);

int Length_LinkList(PLinkList list);

int Locate_LinkList(PLinkList list, void *item);

int Insert_LinkList(PLinkList list, int index, void *item);

int Delete_LinkList(PLinkList list, int index);

int Add_LinkList(PLinkList list, void *item);

void test_LinkList();

#endif //DATASTRUCTURESALGORITHMS_LINK_LIST_H
