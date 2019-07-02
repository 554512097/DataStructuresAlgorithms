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
    PSeqList pl;
    pl = (PSeqList) malloc(sizeof(SeqList));
    if (pl)
        pl->length = 0;
    return pl;
}

int Length_SeqList(PSeqList pl) {
    return pl->length;
}

int Location_SeqList(PSeqList pl, DataType x) {
    int i = 0;
    while (i < pl->length && pl->data[i] != x)
        i++;
    if (i > pl->length)
        return 0;
    else
        return i + 1;
}

int Insert_SeqList(PSeqList pl, int i, DataType x) {
    if (!pl) {
        printf("表不存在");
        return -2;
    }
    if (pl->length >= MAX_SIZE) {
        printf("表溢出");
        return -1;
    }
    if (i < 1 || i > pl->length - 1) {
        printf("插入位置不合法");
    }
    for (int j = pl->length - 1; j > i - 1; j--) {
        pl->data[j + 1] = pl->data[j];
    }
    pl->data[i - 1] = x;
    pl->length++;
    return 1;
}

int Delete_SeqList(PSeqList pl, int i) {
    if (!pl) {
        printf("表不存在");
        return -2;
    }
    if (i < 1 || i > pl->length - 1) {
        printf("插入位置不合法");
    }
    for (int j = i; j < pl->length; j++) {
        pl->data[j - 1] = pl->data[j];
    }
    pl->length--;
    return 1;
}

//a与b的交集
void Inter_sec_SeqList(PSeqList a, PSeqList b) {
    int i = 0;
    while (i < a->length) {
        if (!Location_SeqList(b, a->data[i])) {
            Delete_SeqList(a, i + 1);
        } else {
            i++;
        }
    }
}

//a与b的并集
void Merge_sec_SeqList(PSeqList a, PSeqList b) {
    for (int i = 0; i < b->length; ++i) {
        if (!Location_SeqList(a, b->data[i])) {
            Insert_SeqList(a, a->length + 1, b->data[i]);
        }
    }
}