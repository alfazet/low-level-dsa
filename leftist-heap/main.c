#include "leftist-heap.h"

int main() {
  Node* a = NULL;

  insert(&a, 1);
  insert(&a, 111);
  insert(&a, 11);
  printf("Max: %d, not deleted\n", get_max(a));
  printf("Max: %d, deleted\n", delete_max(&a));
  printf("Max: %d, not deleted\n", get_max(a));

  insert(&a, 10);
  printf("Max: %d, deleted\n", delete_max(&a));
  printf("Max: %d, not deleted\n", get_max(a));

  free_heap(&a);

  return 0;
}
