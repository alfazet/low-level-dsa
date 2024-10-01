#include "heap.h"

int main() {
  Heap *h = init_heap(6);

  insert(h, 2);
  insert(h, 1);
  insert(h, 3);
  insert(h, 7);
  insert(h, 6);
  insert(h, 9);

  printf("Min: %d\n", pop(h));
  printf("Min: %d\n", pop(h));
  printf("Min: %d\n", pop(h));
  printf("Min: %d\n", pop(h));
  printf("Min (wasn't removed): %d\n", peek(h));
  printf("Min (wasn't removed): %d\n", peek(h));

  free_heap(h);

  return 0;
}
