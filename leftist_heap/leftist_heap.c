#include "leftist_heap.h"

Node *meld(Node *a, Node *b) {
  if (a == NULL)
    return b;
  if (b == NULL)
    return a;
  if (a->key < b->key) { // we want a to have the root with the bigger value
    Node *temp = b;
    b = a;
    a = temp;
  }
  a->right = meld(a->right, b);

  if (a->left == NULL ||
      (a->left->npl < a->right->npl)) { // swap to keep the npl property
    Node *temp = a->left;
    a->left = a->right;
    a->right = temp;
  }
  if (a->right == NULL) { // update the root's npl
    a->npl = 0;
  } else {
    a->npl = a->right->npl + 1;
  }

  return a;
}

void insert(Node **a, int key) {
  Node *p = malloc(sizeof(Node));
  p->left = NULL;
  p->right = NULL;
  p->key = key;
  p->npl = 0;
  *a = meld(*a, p);
}

int delete_max(Node **a) {
  int ret_val = (*a)->key;
  Node *l = (*a)->left, *r = (*a)->right;
  free(*a);
  *a = meld(l, r);
  return ret_val;
}

int get_max(Node *a) { return (a == NULL ? INT_MIN : a->key); }

void free_heap(Node **a) {
  if (a == NULL || *a == NULL) {
    return;
  }
  Node *temp = *a;
  free_heap(&(*a)->left);
  free_heap(&(*a)->right);
  free(temp);
}
