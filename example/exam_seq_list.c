//
// Created by Administrator on 2019/6/28 0028.
//

#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100
typedef void *DataType;

typedef struct node {
    DataType data[MAX_SIZE];
    int length;
} SeqList, *PSeqList;

PSeqList Init_SeqList() {
    PSeqList PL;
    PL = (PSeqList) malloc(sizeof(SeqList));
    if (PL)
        PL->length = 0;
    return PL;
}

int Length_SeqList(PSeqList PL) {
    return PL->length;
}

int Location_SeqList(PSeqList PL, DataType x) {
    int i = 0;
    while (i < PL->length && PL->data[i] != x)
        i++;
    if (i > PL->length)
        return 0;
    else
        return i + 1;
}

int Insert_SeqList(PSeqList PL, int i, DataType x) {
    if (!PL) {
        printf("表不存在");
        return -2;
    }
    if (PL->length >= MAX_SIZE) {
        printf("表溢出");
        return -1;
    }
    if (i < 1 || i > PL->length - 1) {
        printf("插入位置不合法");
    }
    for (int j = PL->length - 1; j > i - 1; j--) {
        PL->data[j + 1] = PL->data[j];
    }
    PL->data[i - 1] = x;
    PL->length++;
    return 1;
}

int Delete_SeqList(PSeqList PL, int i) {
    if (!PL) {
        printf("表不存在");
        return -2;
    }
    if (i < 1 || i > PL->length - 1) {
        printf("插入位置不合法");
    }
    for (int j = i; j < PL->length; j++) {
        PL->data[j - 1] = PL->data[j];
    }
    PL->length--;
    return 1;
}

//a与b的交集
void Inter_sec(PSeqList A, PSeqList B) {
    int i = 0;
    while (i < A->length) {
        if (!Location_SeqList(B, A->data[i])) {
            Delete_SeqList(A, i + 1);
        } else {
            i++;
        }
    }
}

//a与b的并集
void Merge_sec(PSeqList A, PSeqList B) {
    for (int i = 0; i < B->length; ++i) {
        if (!Location_SeqList(A, B->data[i])) {
            Insert_SeqList(A, A->length + 1, B->data[i]);
        }
    }
}