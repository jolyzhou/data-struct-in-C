//
// Created by jolyzhou on 2017/1/10.
//

#include "clist.h"

typedef struct Page_
{
    int number;
    int reference;
}Page;

int repalce_page(CListElmt **current)
{
    // Circle through the list of pages until
    // one is found to replace
    while (((Page *)(*current)->data)->reference != 0) {
        ((Page *)(*current)->data)->reference = 0;
        *current = clist_next(*current);
    }
    return ((Page *)(*current)->data)->number;
}