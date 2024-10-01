/*
Doubly linked list
*/

#ifndef LIST_H
#define LIST_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int val;
  struct Node *prev;
  struct Node *next;
};
typedef struct Node Node;

struct List {
  struct Node *front;
  struct Node *back;
  size_t size;
};
typedef struct List List;

List *init_list();
void insert_front(List *l, int val);
void insert_back(List *l, int val);
int pop_front(List *l);
int pop_back(List *l);
void free_list(List *l);

#endif // LIST_H
