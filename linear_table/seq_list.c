//
// Created by xiekun on 2019/6/21.
//

#include "seq_list.h"
#include <stdlib.h>
#include <stdio.h>

PSeqList Init_SeqList_impl() {
    PSeqList pSeqList = malloc(sizeof(SeqList));
    if (pSeqList) {
        pSeqList->length = 0;
        return pSeqList;
    }
    return NULL;
}

int Destroy_SeqList_impl(PSeqList list) {
    if (list) {
        free(list);
        return 1;
    }
    return 0;
}

int Length_SeqList_impl(PSeqList list) {
    if (list) {
        return list->length;
    }
    return 0;
}

int Locate_SeqList_impl(PSeqList list, void *item) {
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

int Insert_SeqList_impl(PSeqList list, int index, void *item) {
    if (list) {
        if (index > list->length) {
            return 0;
        }
        //将后面的元素往前后移，从最后一位开始
        for (int i = list->length; i >= index; --i) {
            list->data[i + 1] = list->data[i];
        }
        list->data[index] = item;
        list->length++;
        return 1;
    }
    return 0;
}

int Delete_SeqList_impl(PSeqList list, int index) {
    if (list) {
        if (index > list->length) {
            return 0;
        }
        //将后面的元素往前面移
        while (index < list->length) {
            void *next = list->data[index + 1];
            list->data[index] = next;
            index++;
        }
        list->length = list->length - 1;
        return 1;
    }
    return 0;
}

int Add_Seqlist_impl(PSeqList list, void *item) {
    if (list) {
        list->data[list->length++] = item;
        return list->length;
    }
    return -1;
}

void test_SeqList() {
    PSeqList list = Init_SeqList_impl();
    Add_Seqlist_impl(list, "1");
    Add_Seqlist_impl(list, "2");
    Add_Seqlist_impl(list, "3");
    Add_Seqlist_impl(list, "4");
    Add_Seqlist_impl(list, "5");
    Add_Seqlist_impl(list, "6");
    Add_Seqlist_impl(list, "7");
    Insert_SeqList_impl(list, 3, "8");
    Delete_SeqList_impl(list, 2);
    int index = Locate_SeqList_impl(list, "5");
    printf("index : %d\n", index);
    for (int i = 0; i < list->length; ++i) {
        printf("item of i : %s\n", (char *) list->data[i]);
    }
    int destroyResult = Destroy_SeqList_impl(list);
    printf("destroyResult : %d\n", destroyResult);
}

void test_SeqList1() {
    SeqList list;
    list.length = 0;
    list.data[0] = "1";
    list.length++;
    list.data[1] = "2";
    list.length++;
    list.data[2] = "3";
    list.length++;
    list.data[3] = "4";
    list.length++;
    list.data[4] = "5";
    list.length++;
    printf("length is : %d\n", list.length);
    for (int i = 0; i < list.length; ++i) {
        printf("item %d is : %s\n", i, (char *) list.data[i]);
    }
}