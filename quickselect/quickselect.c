#include "quickselect.h"

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int *a, int l, int r) {
  int pivot = a[l], i = l + 1, j = r;
  while (i <= j) {
    // find an element that's greater than the pivot on the left
    while (i <= j && a[i] <= pivot)
      i++;
    // find an element that's less than the pivot on the right
    while (i <= j && a[j] >= pivot)
      j--;
    // and swap them
    if (i < j)
      swap(&a[i], &a[j]);
  }
  // move the pivot into its proper position, inbetween the partitions
  swap(&a[l], &a[j]);
  return j;
}

int quickselect(int *a, int l, int r, int k) {
  if (l == r)
    return a[l];
  int pivot_index = partition(a, l, r);
  // pivot_index - l + 1 is the number of values less than the pivot
  if (k == pivot_index - l + 1)
    return a[pivot_index];
  else if (k < pivot_index - l + 1)
    return quickselect(a, l, pivot_index - 1, k);
  else
    return quickselect(a, pivot_index + 1, r, k - (pivot_index - l + 1));
}
