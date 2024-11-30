#include "beap.h"

int main() {
  Beap *b = init_beap(6);

  insert(b, 2);
  insert(b, 1);
  insert(b, 3);
  insert(b, 7);
  insert(b, 6);
  insert(b, 9);
  printf("3 found at index %d\n", search(b, 3)); 
  printf("6 found at index %d\n", search(b, 6)); 
  printf("17 found at index %d\n", search(b, 17)); 
  printf("9 found at index %d\n", search(b, 9)); 

  printf("Max: %d, not deleted\n", get_max(b));
  printf("Max: %d, deleted\n", delete_max(b));
  printf("9 found at index %d\n", search(b, 9)); 
  printf("Max: %d, deleted\n", delete_max(b));
  printf("Max: %d, deleted\n", delete_max(b));
  printf("Max: %d, deleted\n", delete_max(b));

  insert(b, 4);
  printf("Max: %d, not deleted\n", get_max(b));
  printf("4 found at index %d\n", search(b, 4)); 
  printf("2 found at index %d\n", search(b, 2)); 
  printf("Max: %d, deleted\n", delete_max(b));
  printf("Max: %d, not deleted\n", get_max(b));
  printf("Max: %d, deleted\n", delete_max(b));

  free_beap(b);

  return 0;
}
