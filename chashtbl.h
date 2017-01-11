//
// Created by jolyzhou on 2017/1/11.
//

#ifndef DATA_STRUCT_CHASHTBL_H
#define DATA_STRUCT_CHASHTBL_H

#include <stdlib.h>
#include "list.h"

// define a structure for chained hash tables
typedef struct CHTbl_
{
    int  buckets;

    int  (*h)(const void *key);
    int  (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);

    int  size;
    List *table;
} CHTbl;

// public interface
int chtbl_init(CHTbl *htbl, int buckets, int (*h)(const void *key), int (*match)(const void *key1, const void *key2), void (*destroy)(void **data));
void chtbl_destroy(CHTbl *htbl);
int chtbl_insert(CHTbl *htbl, const void *data);
int chtbl_remove(CHTbl *htbl, void **data);
int chtbl_lookup(const CHTbl *htbl, void **data);

#define chtbl_size(htbl) ((htbl)->size)
#endif //DATA_STRUCT_CHASHTBL_H
