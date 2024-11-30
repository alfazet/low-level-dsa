#include "beap.h"

Beap *init_beap(int n) {
  Beap *b = malloc(sizeof(Beap));
  b->a = malloc(sizeof(int) * (n + 1));
  b->a[0] = INT_MAX;
  b->cap = n;
  b->sz = 0;

  return b;
}

// restore the beap after inserting (from the bottom up)
void up_beap(Beap *b, int k) {
  int child_val = b->a[k];
  int child_k = k;
  int i = (int)ceil(0.5 * (-1 + sqrt(1.0 + 8 * k)));
  int j = (int)(k - 0.5 * i * (i - 1));
  while (i > 1) {
    if (j == 1) { // we can only go up to the right parent
      k = k - i + 1;
    } else if (j == i) { // we can only go up to the left parent
      k = k - i;
      j = j - 1;
    } else { // we can choose the smaller parent
      k = k - i;
      j = j - 1;
      if (b->a[k + 1] < b->a[k]) {
        k = k + 1;
        j = j + 1;
      }
    }

    // at this moment, k is the parent's k
    if (b->a[k] < child_val) { // need to swap values
      b->a[child_k] = b->a[k];
      b->a[k] = child_val;
    } else {
      break;
    }
    child_k = k;
    child_val = b->a[k];
    i = i - 1;
  }
}

void insert(Beap *b, int val) {
  if (b->sz == b->cap) {
    return;
  }
  b->sz++;
  b->a[b->sz] = val;
  up_beap(b, b->sz);
}

// restore the beap after popping (from the top down)
void down_beap(Beap *b, int k) {
  int child_val = b->a[k];
  int child_k = k;
  int i = (int)ceil(0.5 * (-1 + sqrt(1.0 + 8 * k)));
  k = k + i;
  i = i + 1;
  while (k <= b->sz) {
    if (k + 1 <= b->sz &&
        (b->a[k + 1] > b->a[k])) { // go to the larger child if possible
      k = k + 1;
    }
    if (b->a[k] > child_val) {
      b->a[child_k] = b->a[k];
      b->a[k] = child_val;
      k = k + i;
      i = i + 1;
    } else {
      break;
    }
  }
}

int delete_max(Beap *b) {
  if (b->sz == 0) {
    return INT_MIN; // empty beap
  }
  int ret_val = b->a[1];
  b->a[1] = b->a[b->sz];
  b->sz--;
  down_beap(b, 1);

  return ret_val;
}

int get_max(Beap *b) { return (b->sz == 0 ? INT_MIN : b->a[1]); }

int search(Beap *b, int x) {
  int h = 0;
  while (h * (h + 1) / 2 + h + 1 <= b->sz) { // go as deep as we can
    h++;
  }
  if (h == 0) {
    return -1;
  }
  int i = h, j = h; // start from the bottom right corner
  int k = (i - 1) * i / 2 + j;

  while (j > 0 && b->a[k] != x) {
    if (b->a[k] < x) { // go up and left if we're smaller than x
      k = k - i;
      j = j - 1;
      i = i - 1;
    } else if (b->sz >= k + i) { // if not, go down and left (if possible)
      k = k + i;
      i = i - 1;
    } else { // last resort, go sideways to the left
      k = k - 1;
      j = j - 1;
    }
  }
  return (j == 0 ? -1 : k);
}

void free_beap(Beap *b) {
  free(b->a);
  free(b);
}
