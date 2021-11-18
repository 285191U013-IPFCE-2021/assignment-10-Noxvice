#include "linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */

/* functions to create lists */
node *make_node (int v, node * q)
{
  node *p = malloc (sizeof (node));
  p->value = v;

  if (q == NULL)
    p->next = NULL;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list (node * p)
{
  node *q = p;
  while (q != NULL)
    {
      node *t = q->next;
      free (q);
      q = t;
    }
}


/* print list to console */
void print_list (node * p)
{
    if (p->next != NULL){
      printf("%d", p->value);
      print_list (p->next);
    }
    else
      printf("%d", p->value);
}

int sum_squares (node * p)
{
    int sum;
    sum = square(p->value);
    if (p->next  != NULL)
      sum += sum_squares(p->next);
    return sum;
    // You can find the tests in tests.cpp
}

node *map (node * p, int (*f) (int))
{
    int (*sf)(int);
    sf = square;
    int x;
    x =sf(p->value);
    node* sq_list =make_node(x, NULL);
      if (p->next !=NULL){
        sq_list->next = map(p->next,square);
        return sq_list;
      } else{
        return sq_list;
      }
}


int square (int x)
{
  return x * x;
}
