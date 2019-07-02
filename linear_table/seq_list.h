//顺序表相关操作
// Created by xiekun on 2019/6/21.
//

#ifndef DATASTRUCTURESALGORITHMS_SEQ_LIST_H
#define DATASTRUCTURESALGORITHMS_SEQ_LIST_H

#define MAXSIZE 100

typedef struct seq_node {
    void *data[MAXSIZE];
    int length;
} SeqList, *PSeqList;

/**
 * 初始化顺序表
 * @return 0 初始化失败 非0成功
 */
PSeqList Init_SeqList_impl();

/**
 * 销毁顺序表
 * @param list 要销毁的list
 * @return 0失败 1成功
 */
int Destroy_SeqList_impl(PSeqList list);

/**
 * 获取顺序表
 * @param list 操作的顺序表
 * @return 顺序表长度
 */
int Length_SeqList_impl(PSeqList list);

/**
 * 定位元素
 * @param list 操作的顺序表
 * @param item 要查询的元素
 * @return 该元素在表中的第一次的索引 -1不存在
 */
int Locate_SeqList_impl(PSeqList list, void *item);

/**
 * 插入元素
 * @param list 操作的顺序表
 * @param index 插入的索引
 * @param item 插入的元素
 * @return 0失败 1成功
 */
int Insert_SeqList_impl(PSeqList list, int index, void *item);

/**
 * 插入元素
 * @param list 操作的顺序表
 * @param index 删除的索引
 * @return 0失败 1成功
 */
int Delete_SeqList_impl(PSeqList list, int index);

/**
 * 添加操作
 * @param list 操作的顺序表
 * @param item 添加的元素
 * @return 元素的索引 -1失败
 */
int Add_Seqlist_impl(PSeqList list, void *item);

void test_SeqList();

void test_SeqList1();

#endif //DATASTRUCTURESALGORITHMS_SEQ_LIST_H
