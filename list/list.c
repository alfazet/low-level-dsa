#include "list.h"

List *init_list() {
  List *l = malloc(sizeof(List));
  l->front = NULL;
  l->back = NULL;
  l->size = 0;

  return l;
}

void insert_front(List *l, int val) {
  Node *new_node = malloc(sizeof(Node));
  new_node->val = val;
  new_node->prev = l->front;
  new_node->next = NULL;
  if (l->front) {
    l->front->next = new_node;
  } else {
    l->back = new_node;
  }
  l->front = new_node;
  l->size++;
}

void insert_back(List *l, int val) {
  Node *new_node = malloc(sizeof(Node));
  new_node->val = val;
  new_node->prev = NULL;
  new_node->next = l->back;
  if (l->back) {
    l->back->prev = new_node;
  } else {
    l->front = new_node;
  }
  l->back = new_node;
  l->size++;
}

int pop_front(List *l) {
  if (l->size == 0) {
    return INT_MAX;
  }
  int ret_val = l->front->val;
  Node *temp = l->front;
  l->front = l->front->prev;
  l->size--;
  if (l->front) {
    l->front->next = NULL;
  }
  if (l->size == 0) {
    l->back = NULL;
  }
  free(temp);

  return ret_val;
}

int pop_back(List *l) {
  if (l->size == 0) {
    return INT_MAX;
  }
  int ret_val = l->back->val;
  Node *temp = l->back;
  l->back = l->back->next;
  l->size--;
  if (l->back) {
    l->back->prev = NULL;
  }
  if (l->size == 0) {
    l->front = NULL;
  }
  free(temp);

  return ret_val;
}

void free_list(List *l) {
  Node *n = l->back;
  while (n) {
    Node *temp = n;
    n = n->next;
    free(temp);
  }
  free(l);
}
