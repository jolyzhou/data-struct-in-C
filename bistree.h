//
// Created by jolyzhou on 2017/1/14.
//

#ifndef DATA_STRUCT_BISTREE_H
#define DATA_STRUCT_BISTREE_H

#include "bitree.h"

// define balance factors for AVL trees
#define AVL_LFT_HEAVY  1
#define AVL_BALANCED   0
#define AVL_RGT_HEAVY -1

// define a structure for nodes in AVL trees
typedef struct AvlNode_
{
    void *data;
    int hidden;
    int factor;
} AvlNode;

// implement binary search trees as binary tree
typedef BiTree BisTree;

// public interface
void bistree_init(BisTree *tree,
                  int (*compare)(const void *key1, const void *key2),
                  void (*destroy)(void *data));
void bistree_destroy(BisTree *tree);
int bistree_insert(BisTree *tree, const void *data);
int bistree_remove(BisTree *tree, const void *data);
int bistree_lookup(BisTree *tree, void **data);
#define bistree_size(tree) ((tree)->size)
#endif //DATA_STRUCT_BISTREE_H
