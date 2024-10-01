#include "heap.h"

Heap *init_heap(int n) {
  Heap *h = malloc(sizeof(Heap));
  h->a = malloc(sizeof(int) * (n + 1));
  h->cap = n;
  h->ptr = 1;

  return h;
}

// restore the heap after inserting (from the bottom up)
void fix_up(Heap *h, int i) {
  while (i > 0 && h->a[i / 2] > h->a[i]) {
    int temp = h->a[i / 2];
    h->a[i / 2] = h->a[i];
    h->a[i] = temp;
    i /= 2;
  }
}

void insert(Heap *h, int val) {
  if (h->ptr == h->cap + 1) {
    return;
  }
  h->a[h->ptr] = val;
  fix_up(h, h->ptr);
  h->ptr++;
}

// restore the heap after popping (from the top down)
void fix_down(Heap *h, int i) {
  int l = 2 * i, r = 2 * i + 1;
  int min_i = i; // index with the smallest value
  if (l <= h->ptr && h->a[l] < h->a[min_i]) {
    min_i = l;
  }
  if (r <= h->ptr && h->a[r] < h->a[min_i]) {
    min_i = r;
  }
  if (min_i != i) {
    int temp = h->a[i];
    h->a[i] = h->a[min_i];
    h->a[min_i] = temp;
    fix_down(h, min_i);
  }
}

int pop(Heap *h) {
  if (h->ptr == 1) {
    return INT_MAX; // empty heap
  }
  int ret_val = h->a[1];
  h->a[1] = h->a[h->ptr - 1];
  h->ptr--;
  fix_down(h, 1);

  return ret_val;
}

int peek(Heap *h) { return (h->ptr == 1 ? INT_MAX : h->a[1]); }

void free_heap(Heap *h) {
  free(h->a);
  free(h);
}
