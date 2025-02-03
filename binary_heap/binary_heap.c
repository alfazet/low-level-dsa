#include "binary_heap.h"

Heap *init_heap(int n) {
  Heap *h = malloc(sizeof(Heap));
  h->a = malloc(sizeof(int) * (n + 1));
  h->a[0] = INT_MAX;
  h->cap = n;
  h->sz = 0;

  return h;
}

// restore the heap after inserting (from the bottom up)
void up_heap(Heap *h, int i) {
  while (i > 0 && h->a[i / 2] < h->a[i]) {
    int temp = h->a[i / 2];
    h->a[i / 2] = h->a[i];
    h->a[i] = temp;
    i /= 2;
  }
}

void insert(Heap *h, int val) {
  if (h->sz == h->cap) {
    return;
  }
  h->sz++;
  h->a[h->sz] = val;
  up_heap(h, h->sz);
}

// restore the heap after popping (from the top down)
void down_heap(Heap *h, int i) {
  int l = 2 * i, r = 2 * i + 1;
  if ((l > h->sz || r > h->sz) || (h->a[l] <= h->a[i] && h->a[r] <= h->a[i])) {
    return;
  }
  int max_i = (h->a[l] > h->a[r] ? l : r);
  int temp = h->a[i];
  h->a[i] = h->a[max_i];
  h->a[max_i] = temp;
  down_heap(h, max_i);
}

int delete_max(Heap *h) {
  if (h->sz == 0) {
    return INT_MIN; // empty heap
  }
  int ret_val = h->a[1];
  h->a[1] = h->a[h->sz];
  h->sz--;
  down_heap(h, 1);

  return ret_val;
}

int get_max(Heap *h) { return (h->sz == 0 ? INT_MIN : h->a[1]); }

void free_heap(Heap *h) {
  free(h->a);
  free(h);
}
