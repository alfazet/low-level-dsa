/*
Max beap (bi-parental heap)
*/

#ifndef BEAP_H
#define BEAP_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Beap {
  int *a;
  int cap;
  int sz; // points to the last element
};
typedef struct Beap Beap;

Beap *init_beap(int n);
void insert(Beap *b, int val);
int delete_max(Beap *b);
int get_max(Beap *b);
int search(Beap *b, int x);
void free_beap(Beap *b);

#endif // BEAP_H
