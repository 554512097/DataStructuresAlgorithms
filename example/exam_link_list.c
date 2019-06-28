//
// Created by Administrator on 2019/6/28 0028.
//

#include <stdlib.h>
#include <stdio.h>

typedef void *DataType;

typedef struct node {
    DataType data;
    struct node *next;
} LNode, *LinkList;

LinkList Create_LinkList() {
    LinkList H;
    H = malloc(sizeof(LNode));
    if (H) {
        H->next = NULL;
    }
    return H;
}

void Destroy_LinkList(LinkList H) {
    LinkList p, q;
    p = H;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    H = NULL;
}

int Lenth_LinkList(LinkList H) {
    LinkList p = H;
    int count = 1;
    while (p) {
        p = p->next;
        count++;
    }
    return count;
}

LinkList Locate_LinkList_Pos(LinkList H, int i) {
    LinkList p;
    int j;
    p = H;
    j = 0;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (j != i || !p) {
        printf("参数i错误或单链表不存在");
        return NULL;
    }
    return p;
}

LinkList Locate_LinkList_Value(LinkList H, DataType x) {
    LinkList p = H->next;
    while (p && p->data != x) {
        p = p->next;
    }
    return p;
}

int Insert_LinkList(LinkList H, int i, DataType x) {
    LinkList p, q;
    p = Locate_LinkList_Pos(H, i - 1);
    if (!p) {
        printf("i有误");
        return 0;
    }
    q = malloc(sizeof(LNode));
    if (!q) {
        printf("申请空间失败");
        return 0;
    }
    q->data = x;
    q->next = p->next;
    p->next = q;
    return 1;
}

int Del_LinkList(LinkList H, int i) {
    LinkList p, q;
    if (H == NULL || H->next == NULL) {
        printf("链表不存在或空表不能删除");
        return 0;
    }
    p = Locate_LinkList_Pos(H, i - 1);
    if (p == NULL || p->next == NULL) {
        printf("参数i错误");
        return 0;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

void Reverse_LinkList(LinkList H) {
    LinkList p, q;
    p = H->next;
    H->next = NULL;
    while (p) {
        q = p;
        p = p->next;
        q->next = H->next;
        H->next = q;
    }
}

void Inter_sec(LinkList A, LinkList B) {
    DataType x;
    LinkList pre, p;
    pre = A;
    p = pre->next;
    while (p) {
        x = p->data;
        if (!Locate_LinkList_Value(B, x)) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}

void Merge_sec(LinkList A, LinkList B) {
    DataType x;
    LinkList p;
    p = B->next;
    while (p) {
        x = p->data;
        if (!Locate_LinkList_Value(A, x)) {
            Insert_LinkList(A, 1, x);
        }
        p = p->next;
    }
}