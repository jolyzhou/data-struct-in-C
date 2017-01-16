//
// Created by jolyzhou on 2017/1/16.
//

#ifndef DATA_STRUCT_BFS_H
#define DATA_STRUCT_BFS_H

#include "graph.h"
#include "list.h"

// define a structure for vertices in a breadth-first search
typedef struct BfsVertex_
{
    void *data;
    VertexColor color;
    int hops;
} BfsVertex;

// public interface
int bfs(Graph *graph, BfsVertex *start, List *hops);

#endif //DATA_STRUCT_BFS_H
