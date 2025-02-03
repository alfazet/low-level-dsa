#include "radix_sort.h"

int bit_int(unsigned x, int i) {
  return ((x & ((unsigned)1 << i)) == 0 ? 0 : 1);
}
int bit_char(char *s, int i) { return (int)(s[i] - 'a'); }

void radix_sort_int(unsigned *a, int n) {
  unsigned *tmp = malloc((n + 1) * sizeof(unsigned));
  for (int b = 0; b < MAX_LEN; b++) {
    int count[RADIX_BIN];
    for (int i = 0; i < RADIX_BIN; i++)
      count[i] = 0;
    for (int i = 1; i <= n; i++)
      count[bit_int(a[i], b)]++;
    int pref[RADIX_BIN];
    pref[0] = count[0];
    for (int i = 1; i < RADIX_BIN; i++)
      pref[i] = pref[i - 1] + count[i];

    for (int i = n; i >= 1; i--) {
      int where = pref[bit_int(a[i], b)];
      tmp[where] = a[i];
      pref[bit_int(a[i], b)]--;
    }
    for (int i = 1; i <= n; i++)
      a[i] = tmp[i];
  }
  free(tmp);
}

void radix_sort_string(char **a, int n) {
  char **tmp = malloc((n + 1) * sizeof(char *));
  for (int i = 1; i <= n; i++) {
    tmp[i] = malloc((MAX_LEN + 1) * sizeof(char));
    tmp[i][MAX_LEN] = '\0';
  }
  for (int b = MAX_LEN - 1; b >= 0; b--) {
    int count[RADIX_ALPHA];
    for (int i = 0; i < RADIX_ALPHA; i++)
      count[i] = 0;
    for (int i = 1; i <= n; i++)
      count[bit_char(a[i], b)]++;
    int pref[RADIX_BIN];
    pref[0] = count[0];
    for (int i = 1; i < RADIX_ALPHA; i++)
      pref[i] = pref[i - 1] + count[i];

    for (int i = n; i >= 1; i--) {
      int where = pref[bit_char(a[i], b)];
      for (int j = 0; j < MAX_LEN; j++)
        tmp[where][j] = a[i][j];
      pref[bit_char(a[i], b)]--;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < MAX_LEN; j++)
        a[i][j] = tmp[i][j];
    }
  }
  for (int i = 1; i <= n; i++)
    free(tmp[i]);
  free(tmp);
}
