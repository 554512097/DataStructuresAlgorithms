//
// Created by xiekun on 2019/6/21.
//

#ifndef DATASTRUCTURESALGORITHMS_SEQ_LIST_H
#define DATASTRUCTURESALGORITHMS_SEQ_LIST_H

#define MAXSIZE 100

typedef struct node {
    int data[MAXSIZE];
    int length;
} SeqList, *PSeqList;

PSeqList Init_SeqList();

int Destroy_SeqList(PSeqList list);

int Length_SeqList(PSeqList list);

int Locate_SeqList(PSeqList list, int item);

int Insert_SeqList(PSeqList list, int index, int item);

int Delete_SeqList(PSeqList list, int index);

void test_SeqList();

#endif //DATASTRUCTURESALGORITHMS_SEQ_LIST_H
