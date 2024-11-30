/*
Max leftist heap
*/

#ifndef LEFTISTHEAP_H
#define LEFTISTHEAP_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int key, npl;
  struct Node *left;
  struct Node *right;
};
typedef struct Node Node;

Node *meld(Node *a, Node *b);
void insert(Node **a, int key);
int delete_max(Node **a);
int get_max(Node *a);
void free_heap(Node **a);

#endif // LEFTISTHEAP_H
