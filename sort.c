//
// Created by jolyzhou on 2017/1/17.
//

#include <stdlib.h>
#include <string.h>

#include "sort.h"


// ---------------INSERT SORT start-----------------
// insert sort
int ins_sort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2))
{
    char *a = data;
    void *key;
    int i, j;
    if ((key = (char *)malloc(esize)) == NULL)
        return -1;
    for (j = 1; j < size; j++) {
        memcpy(key, &a[j*esize], esize);
        i = j - 1;
        while (i >= 0 && compare(&a[i*esize], key) > 0) {
            memcpy(&a[(i+1)*esize], &a[i*esize], esize);
            i--;
        }
        memcpy(&a[(i+1)*esize], key, esize);
    }
    free(key);
    return 0;
}
// ---------------INSERT SORT end-----------------

// ---------------QUICK SORT start-----------------
// quick sort
static int compare_int(const void *int1, const void *int2)
{
    if (*(const int *)int1 > *(const int *)int2)
        return 1;
    else if (*(const int *)int1 < *(const int *)int2)
        return -1;
    else
        return 0;
}

static int partition(void *data, int esize, int i, int k, int (*compare)(const void *key1, const void *key2))
{
    char *a = data;
    void *pval, *temp;
    int r[3];
    if ((pval = malloc(esize)) == NULL)
        return -1;
    if ((temp = malloc(esize)) == NULL) {
        free(pval);
        return -1;
    }
    // use the median-of-three method to find the partition value
    r[0] = (rand() % (k - i + 1)) + i;
    r[1] = (rand() % (k - i + 1)) + i;
    r[2] = (rand() % (k - i + 1)) + i;
    ins_sort(r, 3, sizeof(int), compare_int);
    memcpy(pval, &a[r[1]*esize], esize);
    i--;
    k++;
    while (1) {
        do {
            k--;
        } while (compare(&a[k*esize], pval) > 0);
        do {
            i++;
        } while (compare(&a[i*esize], pval) < 0);
        if (i >= k)
            break;
        else {
            memcpy(temp, &a[i*esize], esize);
            memcpy(&a[i*esize], &a[k*esize], esize);
            memcpy(&a[k*esize], temp, esize);
        }
    }
    free(pval);
    free(temp);
    return k;
}

int qksort(void *data,
           int size, int esize,
           int i, int k,
           int (*compare)(const void *key1, const void *key2))
{
    int j;
    while (i < k) {
        if ((j = partition(data, esize, i, k, compare)) < 0)
            return -1;
        if (qksort(data, size, esize, i, j, compare) < 0)
            return -1;
        i = j + 1;
    }
    return 0;
}
// ---------------QUICK SORT end-----------------

// ---------------MERGE SORT start-----------------
// merge
static int merge(void *data, int esize, int i, int j, int k,
                 int (*compare)(const void *key1, const void *key2))
{
    char *a = data, *m;
    int ipos, jpos, mpos;
    // initialize the counters used in merging
    ipos = i;
    jpos = j + 1;
    mpos = 0;
    if ((m = (char *)malloc(esize*((k - i) + 1))) == NULL)
        return -1;
    while (ipos <= j || jpos <= k) {
        if (ipos > j) {
            // the left division has no more elements to merge
            while (jpos <= k) {
                memcpy(&m[mpos*esize], &a[jpos*esize], esize);
                jpos++;
                mpos++;
            }
            continue;
        } else if (jpos > k) {
            // the right division has no more elements to merge
            while (ipos <= j) {
                memcpy(&m[mpos*esize], &a[ipos*esize], esize);
                ipos++;
                mpos++;
            }
            continue;
        }
        if (compare(&a[ipos*esize], &a[jpos*esize]) < 0) {
            memcpy(&m[mpos*esize], &a[ipos*esize], esize);
            ipos++;
            mpos++;
        } else {
            memcpy(&m[mpos*esize], &a[jpos*esize], esize);
            jpos++;
            mpos++;
        }
    }
//    ======second loop for merge array======
//    while (ipos <= j && jpos <= k) {
//        if (compare(&a[ipos*esize], &a[jpos*esize]) < 0) {
//            memcpy(&m[mpos*esize], &a[ipos*esize], esize);
//            ipos++;
//            mpos++;
//        } else {
//            memcpy(&m[mpos*esize], &a[jpos*esize], esize);
//            jpos++;
//            mpos++;
//        }
//    }
//    while (ipos <= j) {
//        memcpy(&m[mpos*esize], &a[ipos*esize], esize);
//        ipos++;
//        mpos++;
//    }
//    while (jpos <= k) {
//        memcpy(&m[mpos*esize], &a[jpos*esize], esize);
//        jpos++;
//        mpos++;
//    }
    memcpy(&a[i*esize], m, esize*((k-i)+1));
    free(m);
    return 0;
}

// mgsort
int mgsort(void *data, int size, int esize, int i, int k,
           int (*compare)(const void *key1, const void *key2))
{
    int j;
    // stop the recursion when no more divisions can be made
    if (i < k) {
        // determine where to divide the elements
        j = (int)(((i + k - 1)) / 2);
        // recursively sort the two divisions
        if (mgsort(data, size, esize, i, j, compare) < 0)
            return -1;
        if (mgsort(data, size, esize, j+1, k, compare) < 0)
            return -1;
        // merge the two sorted divisions into a single sorted set
        if (merge(data, esize, i, j, k, compare) < 0)
            return -1;
    }
    return 0;
}
// ---------------MERGE SORT end-----------------

// ---------------COUNT SORT start-----------------
int ctsort(int *data, int size, int k)
{
    int *count, *temp;
    int i, j;
    if ((count = (int *)malloc(k * sizeof(int))) == NULL)
        return -1;
    if ((temp = (int *)malloc(k * sizeof(int))) == NULL)
        return -1;
    for (i = 0; i < k; i++)
        count[i] = 0;
    for (j = 0; j < size; j++)
        count[data[j]]++;
    for (i = 1; i < k; i++)
        count[i] = count[i] + count[i-1];
    for (j = size - 1; j >= 0; j--) {
        temp[count[data[j]] - 1] = data[j];
        count[data[j]]--;
    }
    memcpy(data, temp, size * sizeof(int));
    free(count);
    free(temp);
    return 0;
}
// ---------------COUNT SORT end-----------------


// ---------------RADIX SORT start-----------------
#define BASE 10
// get element max bit
static int max_bit(int *data, int size)
{
    int max_data = data[0];
    int d = 1, p = 10;
    for (int i = 1; i < size; i++) {
        if (max_data < data[i])
            max_data = data[i];
    }
    while (max_data >= p) {
        max_data /= 10;
        d++;
    }
    return d;
}
// radix sort
int rxsort(int *data, int size)
{
    int d = max_bit(data, size);
    int *counts, *temp;
    int i, j, k;
    int radix = 1;
    if ((counts = (int *)malloc(k* sizeof(int))) == NULL)
        return -1;
    if ((temp = (int *)malloc(size* sizeof(int))) == NULL)
        return -1;
    // sort from the least significant position to the most significant
    for (i = 1; i <= d; i++) {
        for (j = 0; j < BASE; j++)
            counts[j] = 0;
        for (j = 0; j < size; j++) {
            k = (int)(data[j] / radix) % BASE;
            counts[k]++;
        }
        for (j = 1; j < BASE; j++)
            counts[j] = counts[j] + counts[j - 1];
        for (j = size - 1; j >= 0; j--) {
            k = (int)(data[j] / radix) % BASE;
            temp[counts[k] - 1] = data[j];
            counts[k]--;
        }
        radix *= BASE;
    }
    memcpy(data, temp, size * sizeof(int));
    free(counts);
    free(temp);
    return 0;
}
// ---------------RADIX SORT end-----------------

// bisearch
int bisearch(void *sorted,
             const void *target,
             int size, int esize,
             int (*compare)(const void *key1, const void *key2))
{
    int left, middle, right;
    // continue searching until the left and right indices cross
    left = 0;
    right = size - 1;
    while (left <= right) {
        middle = (left + right) / 2;
        switch (compare(((char *)sorted + (esize * middle)), target)) {
            case -1:
                left = middle + 1;
                break;
            case 1:
                right = middle - 1;
                break;
            case 0:
                return middle;
        }
    }
    return -1;
}

// example for bisearch ===> word spell search
#define SPELL_SIZE 31

// compare string
static int compare_str(const void *str1, const void *str2)
{
    int retval;
    if ((retval = strcmp((const char *)str1, (const char *)str2)) > 0) {
        return 1;
    } else if (retval < 0)
        return -1;
    else
        return 0;
}

// spell
int spell(char (*dictionary)[SPELL_SIZE], int size, const char *word)
{
    if (bisearch(dictionary, word, size, SPELL_SIZE, compare_str) >= 0)
        return 1;
    else
        return 0;
}