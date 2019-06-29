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
    LinkList h;
    h = malloc(sizeof(LNode));
    if (h) {
        h->next = NULL;
    }
    return h;
}

void Destroy_LinkList(LinkList h) {
    LinkList p, q;
    p = h;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    h = NULL;
}

int Lenth_LinkList(LinkList h) {
    LinkList p = h;
    int count = 1;
    while (p) {
        p = p->next;
        count++;
    }
    return count;
}

LinkList Locate_LinkList_Pos(LinkList h, int i) {
    LinkList p;
    int j;
    p = h;
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

LinkList Locate_LinkList_Value(LinkList h, DataType x) {
    LinkList p = h->next;
    while (p && p->data != x) {
        p = p->next;
    }
    return p;
}

int Insert_LinkList(LinkList h, int i, DataType x) {
    LinkList p, q;
    p = Locate_LinkList_Pos(h, i - 1);
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

int Del_LinkList(LinkList h, int i) {
    LinkList p, q;
    if (h == NULL || h->next == NULL) {
        printf("链表不存在或空表不能删除");
        return 0;
    }
    p = Locate_LinkList_Pos(h, i - 1);
    if (p == NULL || p->next == NULL) {
        printf("参数i错误");
        return 0;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

void Reverse_LinkList(LinkList h) {
    LinkList p, q;
    p = h->next;
    h->next = NULL;
    while (p) {
        q = p;
        p = p->next;
        q->next = h->next;
        h->next = q;
    }
}

void Inter_sec(LinkList a, LinkList b) {
    DataType x;
    LinkList pre, p;
    pre = a;
    p = pre->next;
    while (p) {
        x = p->data;
        if (!Locate_LinkList_Value(b, x)) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}

void Merge_sec(LinkList a, LinkList b) {
    DataType x;
    LinkList p;
    p = b->next;
    while (p) {
        x = p->data;
        if (!Locate_LinkList_Value(a, x)) {
            Insert_LinkList(a, 1, x);
        }
        p = p->next;
    }
}