#include "quickselect.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_arr_int(int *a, int n) {
  for (int i = 0; i < n; i++)
    printf("%u ", a[i]);
  printf("\n");
}

int compare(const void *_lhs, const void *_rhs) {
  int lhs = *(int *)_lhs, rhs = *(int *)_rhs;
  if (lhs < rhs)
    return -1;
  else if (lhs == rhs)
    return 0;
  else
    return 1;
}

int main() {
  srand(time(NULL));
  const int N = (rand() % 20) + 1;
  int k = rand() % N;

  int *a = malloc(N * sizeof(int));
  for (int i = 0; i < N; i++)
    a[i] = (rand() % 90) + 10;
  qsort(a, N, sizeof(int), &compare);
  print_arr_int(a, N);
  printf("the %dth element is %d\n", k, quickselect(a, 0, N - 1, k));

  return EXIT_SUCCESS;
}
