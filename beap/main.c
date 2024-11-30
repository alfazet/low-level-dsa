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

  printf("Max: %d, not popped\n", peek(b));
  printf("Max: %d, popped\n", pop(b));
  printf("9 found at index %d\n", search(b, 9)); 
  printf("Max: %d, popped\n", pop(b));
  printf("Max: %d, popped\n", pop(b));
  printf("Max: %d, popped\n", pop(b));

  insert(b, 4);
  printf("Max: %d, not popped\n", peek(b));
  printf("4 found at index %d\n", search(b, 4)); 
  printf("2 found at index %d\n", search(b, 2)); 
  printf("Max: %d, popped\n", pop(b));
  printf("Max: %d, not popped\n", peek(b));
  printf("Max: %d, popped\n", pop(b));

  free_beap(b);

  return 0;
}
