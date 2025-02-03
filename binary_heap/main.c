#include "binary_heap.h"

int main() {
  Heap *h = init_heap(6);

  insert(h, 2);
  insert(h, 1);
  insert(h, 3);
  insert(h, 7);
  insert(h, 6);
  insert(h, 9);
  printf("Max: %d, not deleted\n", get_max(h));
  printf("Max: %d, deleted\n", delete_max(h));
  printf("Max: %d, deleted\n", delete_max(h));
  printf("Max: %d, deleted\n", delete_max(h));
  printf("Max: %d, deleted\n", delete_max(h));

  insert(h, 4);
  printf("Max: %d, not deleted\n", get_max(h));
  printf("Max: %d, deleted\n", delete_max(h));
  printf("Max: %d, not deleted\n", get_max(h));
  printf("Max: %d, deleted\n", delete_max(h));

  free_heap(h);

  return 0;
}
