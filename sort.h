//
// Created by jolyzhou on 2017/1/17.
//

#ifndef DATA_STRUCT_SORT_H
#define DATA_STRUCT_SORT_H

// insert sort
int ins_sort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));
// quick sort
int qksort(void *data,
           int size, int esize, int i, int k,
           int (*compare)(const void *key1, const void *key2));
// merge sort
int mgsort(void *data,
           int size, int esize, int i, int k,
           int (*compare)(const void *key1, const void *key2));
// count sort
int ctsort(int *data, int size, int k);
// radix sort
int rxsort(int *data, int size, int p, int k);
#endif //DATA_STRUCT_SORT_H
