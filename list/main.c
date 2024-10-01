#include "list.h"

int main() {
  List *l = init_list();

  insert_back(l, 1);
  insert_back(l, 2);
  insert_front(l, 3);
  insert_front(l, 4);

  printf("Back: %d\n", pop_back(l));
  printf("Front: %d\n", pop_front(l));

  insert_front(l, 5);
  insert_back(l, 6);
  printf("Back: %d\n", pop_back(l));
  printf("Front: %d\n", pop_front(l));

  free_list(l);

  return 0;
}
