/*
Max binary heap
*/

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Heap {
  int *a;
  int cap;
  int sz; // points to the last element
};
typedef struct Heap Heap;

Heap *init_heap(int n);
void insert(Heap *h, int val);
int delete_max(Heap *h);
int get_max(Heap *h);
void free_heap(Heap *h);

#endif // BINARYHEAP_H
