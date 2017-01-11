//
// Created by jolyzhou on 2017/1/11.
//

#ifndef DATA_STRUCT_SET_H
#define DATA_STRUCT_SET_H

#include <stdlib.h>
#include "list.h"

typedef List Set;

// public interface
#define set_destroy list_destroy
#define set_size(set) ((set)->size)

void set_init(Set *set, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data));
int set_insert(Set *set, const void *data);
int set_remove(Set *set, void **data);
int set_union(Set *setu, const Set *set1, const Set *set2);
int set_intersection(Set *seti, const Set *set1, const Set *set2);
int set_difference(Set *setd, const Set *set1, const Set *set2);
int set_is_member(const Set *set, const void *data);
int set_is_subset(const Set *set1, const Set *set2);
int set_is_equal(const Set *set1, const Set *set2);

#endif //DATA_STRUCT_SET_H
