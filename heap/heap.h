/*
Max heap
*/

#ifndef HEAP_H
#define HEAP_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Heap {
  int *a;
  int cap;
  int sz; // points to the first empty space
};
typedef struct Heap Heap;

Heap *init_heap(int n);
void insert(Heap *h, int val);
int pop(Heap *h);
int peek(Heap *h);
void free_heap(Heap *h);

#endif // HEAP_H
