#include <stdio.h>
#include <stdlib.h>

#define RADIX_BIN 2
#define RADIX_ALPHA 26
#define MAX_LEN 32

int bit_int(unsigned x, int i);
int bit_string(char *s, int i);

void radix_sort_int(unsigned *a, int n);
void radix_sort_string(char **a, int n);
