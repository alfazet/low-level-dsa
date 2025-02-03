#include "radix_sort.h"
#include <time.h>

void print_arr_int(unsigned *a, int n) {
  for (int i = 1; i <= n; i++)
    printf("%u ", a[i]);
  printf("\n");
}

void print_arr_string(char **a, int n) {
  for (int i = 1; i <= n; i++)
    printf("%s ", a[i]);
  printf("\n");
}

int main() {
  srand(time(NULL));
  const int N = 10;

  char **a = malloc((N + 1) * sizeof(char *));
  for (int i = 1; i <= N; i++) {
    a[i] = malloc((MAX_LEN + 1) * sizeof(char));
    for (int j = 0; j < MAX_LEN; j++)
      a[i][j] = (char)(rand() % 26) + 'a';
    a[i][MAX_LEN] = '\0';
  }
  print_arr_string(a, N);
  radix_sort_string(a, N);
  print_arr_string(a, N);
  for (int i = 1; i <= N; i++)
    free(a[i]);
  free(a);

  unsigned *b = malloc((N + 1) * sizeof(int));
  for (int i = 1; i <= N; i++)
    b[i] = rand();
  print_arr_int(b, N);
  radix_sort_int(b, N);
  print_arr_int(b, N);

  return EXIT_SUCCESS;
}
