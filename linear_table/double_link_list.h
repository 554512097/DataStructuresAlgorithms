//
// Created by xiekun on 2019/6/22.
//

#ifndef DATASTRUCTURESALGORITHMS_DOUBLE_LINK_LIST_H
#define DATASTRUCTURESALGORITHMS_DOUBLE_LINK_LIST_H

typedef struct node {
    void *data;
    struct node *last;
    struct node *next;
} DNode, *PDNode;

typedef struct d_link_list {
    PDNode head;
    int length;
} DLinkList, *PDLinkList;

PDLinkList PDLinkList_Init_impl();

int Destroy_PDLinkList_impl(PDLinkList list);

int Length_PDLinkList_impl(PDLinkList list);

int Locate_PDLinkList_impl(PDLinkList list, void *item);

int Insert_PDLinkList_impl(PDLinkList list, int index, void *item);

int Delete_PDLinkList_impl(PDLinkList list, int index);

int Add_PDLinkList_impl(PDLinkList list, void *item);

void test_PDLinkList();

#endif //DATASTRUCTURESALGORITHMS_DOUBLE_LINK_LIST_H
