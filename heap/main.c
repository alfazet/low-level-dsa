#include "heap.h"

int main() {
  Heap *h = init_heap(6);

  insert(h, 2);
  insert(h, 1);
  insert(h, 3);
  insert(h, 7);
  insert(h, 6);
  insert(h, 9);
  printf("Max: %d, not popped\n", peek(h));
  printf("Max: %d, popped\n", pop(h));
  printf("Max: %d, popped\n", pop(h));
  printf("Max: %d, popped\n", pop(h));
  printf("Max: %d, popped\n", pop(h));

  insert(h, 4);
  printf("Max: %d, not popped\n", peek(h));
  printf("Max: %d, popped\n", pop(h));
  printf("Max: %d, not popped\n", peek(h));
  printf("Max: %d, popped\n", pop(h));

  free_heap(h);

  return 0;
}
