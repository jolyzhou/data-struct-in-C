//
// Created by jolyzhou on 2017/1/10.
//

#ifndef DATA_STRUCT_QUEUE_H
#define DATA_STRUCT_QUEUE_H

#include <stdlib.h>
#include "list.h"

typedef List Queue;

#define queue_init list_init
#define queue_destroy list_destroy
#define queue_peek(queue) ((queue)->head == NULL ? NULL : (queue)->head->data)
#define queue_size list_size

int queue_enqueue(Queue *queue, const void *data);
int queue_dequeue(Queue *queue, void **data);

#endif //DATA_STRUCT_QUEUE_H
