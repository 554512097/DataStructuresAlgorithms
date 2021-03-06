//链表表相关操作
// Created by xiekun on 2019/6/21.
//

#ifndef DATASTRUCTURESALGORITHMS_LINK_LIST_H
#define DATASTRUCTURESALGORITHMS_LINK_LIST_H

typedef struct node {
    void *data;
    struct node *next;
} LNode, *PLNode;

typedef struct link_list {
    PLNode header;
    int length;
} LinkList, *PLinkList;

PLinkList Init_LinkList_impl();

int Destroy_LinkList_impl(PLinkList list);

int Length_LinkList_impl(PLinkList list);

int Locate_LinkList_impl(PLinkList list, void *item);

int Insert_LinkList_impl(PLinkList list, int index, void *item);

int Delete_LinkList_impl(PLinkList list, int index);

int Add_LinkList_impl(PLinkList list, void *item);

void test_LinkList();

#endif //DATASTRUCTURESALGORITHMS_LINK_LIST_H
