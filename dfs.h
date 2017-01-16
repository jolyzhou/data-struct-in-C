//
// Created by jolyzhou on 2017/1/16.
//

#ifndef DATA_STRUCT_DFS_H
#define DATA_STRUCT_DFS_H

#include "graph.h"
#include "list.h"

// define a structure for vertices in a depth-first search
typedef struct DfsVertex_
{
    void *data;
    VertexColor color;
} DfsVertex;

// public interface
int dfs(Graph *graph, List *ordered);

#endif //DATA_STRUCT_DFS_H
