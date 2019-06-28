//
// Created by Administrator on 2019/6/28 0028.
//

#define MAX_SIZE 100

typedef void *DataType;

typedef struct {
    DataType data[MAX_SIZE];
    int top;
} SeqStack, *PSeqStack;