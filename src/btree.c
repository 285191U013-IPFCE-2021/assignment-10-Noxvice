#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


struct tree_node * Insert (int x, struct tree_node *t)
{
if (Empty(t) == 1){
  struct tree_node *leaf = malloc(sizeof(struct tree_node));
  leaf->item = x;
  leaf->left = NULL;
  leaf->right = NULL;
  t->left = leaf;
  t->right = leaf;
  }
if (Empty(t) == 0){
  bool isinsert = 0;
  struct tree_node* current = t->left;
  while (isinsert == 0)
  {
  if (current->item > x){
    if (current->left !=NULL)
    {
      current = current->left;
    }
      else{
        struct tree_node *leaf = malloc(sizeof(struct tree_node));
        current->left = leaf;
        leaf->item = x;
        leaf->left = leaf->right = NULL;
        isinsert = 1;        
      }
  }
    if (current->item < x){
    if (current->right !=NULL)
    {
      current = current->right;
    }
      else{
        struct tree_node *leaf = malloc(sizeof(struct tree_node));
        current->right = leaf;
        leaf->item = x;
        leaf->left = leaf->right = NULL;
        isinsert = 1;        
      }
  }
  
    
  }

}

  return NULL;
}

struct tree_node * Remove (int x, struct tree_node *t)
{
 // Remove one item from the tree t
  if (Empty(1))
  return 0;
  
  if (x == t->item)
  {
    if (t->left == NULL && t->right == NULL)
    {
    free (t);
    return 0;
    }

    else if (t->right && t->left)
    {
      struct tree_node *lefttemp = t->left;
      struct tree_node *righttemp = t->right;

      t->item = lefttemp->item;
      t->left = lefttemp->left;
      t->right = lefttemp->right;

      struct tree_node *c = t;
      while (c->right)
      {
        c = c->right; 
        c->right = righttemp;
        free(lefttemp);
      }
    }
    else
    {
      struct tree_node *child;
      (t->left) ? (child = t->left) : (child = t->right);
    
      t->item = child->item;
      t->left = child->left;
      t->right = child->right;

      free (child);    
  }
    if (x < t->item)
    {
      t->left = Remove(x,t->left);
    }
    if (x > t->item)
    {
      t->right = Remove(x,t->right);
    }
  return t;
}


int Contains (int x, struct tree_node *t)
{
   while (1)
  {
    if (t==NULL)
    {
      return false;
    }

    if (t->item==x)
    {
      return 1;
    }
    

    if (t->item>x)
    {
      t=t->left;
    }
    
    if (t->item<x)
    {
      t=t->right;
    }
  }
return 0;
}
  // Return true if the tree t contains item x. Return false otherwise.



struct tree_node * Initialize (struct tree_node *t)
{
  t->left = NULL;
  t->right = NULL;
  // Create an empty tree
  return NULL;
}

int Empty (struct tree_node *t)
{
  // Test if empty
  if (t->left == NULL && t->right == NULL)
  return 1;
  else
  return 0;
  
}

// int Full (struct tree_node *t)
// {
//     // Test if full
//     return 0;
// } The tree can never be full
