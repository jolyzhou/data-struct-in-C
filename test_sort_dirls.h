//
// Created by jolyzhou on 2017/1/17.
//

#ifndef DATA_STRUCT_TEST_SORT_DIRLS_H
#define DATA_STRUCT_TEST_SORT_DIRLS_H

#include <dirent.h>

// define a structure for directory entries
typedef struct Directory_
{
    char name[MAXNAMLEN + 1];
} Directory;

// public interface
int directory(const char *path, Directory **dir);

#endif //DATA_STRUCT_TEST_SORT_DIRLS_H
