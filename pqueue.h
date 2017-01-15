//
// Created by jolyzhou on 2017/1/15.
//
#ifndef DATA_STRUCT_PQUEUE_H
#define DATA_STRUCT_PQUEUE_H

#include "heap.h"

// implement priority queues as heaps
typedef Heap PQueue;

// public interface
#define pqueue_init heap_init
#define pqueue_destroy heap_destroy
#define pqueue_insert heap_insert
#define pqueue_extract heap_extract
#define pqueue_peek(pqueue) ((pqueue)->tree == NULL ? NULL : (pqueue)->tree[0])
#define pqueue_size heap_size


#endif //DATA_STRUCT_PQUEUE_H
