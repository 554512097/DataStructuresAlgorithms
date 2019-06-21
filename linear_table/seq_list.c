//
// Created by xiekun on 2019/6/21.
//

#include "seq_list.h"
#include <stdlib.h>

PSeqList Init_SeqList() {
    PSeqList pSeqList = malloc(sizeof(SeqList));
    if (pSeqList) {
        pSeqList->length = 0;
        return pSeqList;
    }
    return NULL;
}

int Destroy_SeqList(PSeqList list) {
    if (list) {
        free(list->data);
        free(list);
        return 1;
    }
    return 0;
}

int Length_SeqList(PSeqList list) {
    if (list) {
        return list->length;
    }
    return 0;
}

int Locate_SeqList(PSeqList list, int item) {
    if (list) {
        int i = 0;
        int length = list->length;
        while (i < length - 1) {
            if (list->data[i] == item) {
                return i;
            }
            i++;
        }
    }
    return -1;
}

int Insert_SeqList(PSeqList list, int index, int item) {
    if (list) {
        int length = list->length;
        int tmpLen = index - length;
        int tmp[tmpLen];
        for (int i = index; i < length - 1; ++i) {
            tmp[i - index] = list->data[i];
        }
        list->data[index] = item;
        index++;
        for (int j = 0; j < tmpLen; ++j) {
            list->data[index + j] = tmp[j];
        }
        list->length = length + 1;
    }
    return 0;
}

int Delete_SeqList(PSeqList list, int index) {
    if (list) {
        while (index < list->length) {
            int next = list->data[index + 1];
            list->data[index] = next;
            index++;
        }
        list->length = list->length - 1;
    }
    return 0;
}

void test_SeqList() {

}