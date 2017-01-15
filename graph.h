//
// Created by jolyzhou on 2017/1/15.
//

#ifndef DATA_STRUCT_GRAPH_H
#define DATA_STRUCT_GRAPH_H

#include <stdlib.h>
#include "list.h"
#include "set.h"

// define a structure for adjacency lists
typedef struct AdjList_
{
    void *vertex;
    Set adjacent;
} AdjList;

// define a structure for graphs
typedef struct Graph_
{
    int vcount;
    int ecount;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    List adjlists;
} Graph;

// define colors for vertices in graphs
typedef enum VertexColor_
{
    white,
    gray,
    black
} VertexColor;

// public interface
void graph_init(Graph *graph,
                int (*match)(const void *key1, const void *key2),
                void (*destroy)(void *data));
void graph_destroy(Graph *graph);
int graph_ins_vertex(Graph *graph, const void *data);
int graph_ins_edge(Graph *graph, const void *data1, const void *data2);
int graph_rem_vertex(Graph *graph, void **data);
int graph_rem_edge(Graph *graph, void *data1, void **data2);
int graph_adjlist(const Graph *graph, const void *data, AdjList **adjlist);
int graph_is_adjacent(const Graph *graph, const void *data1, const void *data2);

#define graph_adjlists(graph) ((graph)->adjlists)
#define graph_vcount(graph) ((graph)->vcount)
#define graph_ecount(graph) ((graph)->ecount)

#endif //DATA_STRUCT_GRAPH_H
