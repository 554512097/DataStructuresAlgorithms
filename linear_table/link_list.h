//
// Created by xiekun on 2019/6/21.
//

#ifndef DATASTRUCTURESALGORITHMS_LINK_LIST_H
#define DATASTRUCTURESALGORITHMS_LINK_LIST_H

typedef struct node {
    int data;
    struct node *next;
} LNode, *LinkList;

LinkList Init_LinkList();

int Destroy_LinkList(LinkList list);

int Length_LinkList(LinkList list);

int Locate_LinkList(LinkList list, int item);

int Insert_LinkList(LinkList list, int index, int item);

int Delete_LinkList(LinkList list, int index);

#endif //DATASTRUCTURESALGORITHMS_LINK_LIST_H
