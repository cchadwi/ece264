// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
Tree * newTree(void)
{
  Tree * t = malloc(sizeof(Tree));
  t -> root = NULL;
  return t;
}

void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}


// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE
int search(int arr[], int strt, int end, int value) 
{ 
    int i; 
    for (i = strt; i <= end; i++) 
    { 
        if (arr[i] == value) 
        {
          break;
        }
    } 
    return i; 
} 

TreeNode * buildNew(int inArray[], int postArray[], int inStrt, int inEnd, int * pIndex) 
{ 
    if (inStrt > inEnd) 
    {
      return NULL; 
    }

    TreeNode * node = malloc(sizeof(TreeNode));
    node -> value = postArray[*pIndex];
    node -> left = NULL;
    node -> right = NULL;
    (*pIndex)--;
    
    if (inStrt == inEnd)
    {
       return node; 
    } 
       
    int iIndex = search(inArray, inStrt, inEnd, node->value); 
    node->right = buildNew(inArray, postArray, iIndex + 1, inEnd, pIndex); 
    node->left = buildNew(inArray, postArray, inStrt, iIndex - 1, pIndex); 
    return node; 
} 

Tree * buildTree(int * inArray, int * postArray, int size)
{
  Tree * tree = malloc(sizeof(Tree));
  int pIndex = size - 1; 
  tree->root = buildNew(inArray, postArray, 0, size - 1, &pIndex); 
  return tree;
}
#endif

#ifdef TEST_PRINTPATH
bool printPathHelper(TreeNode * trn, int val)
{
  if(trn == NULL)
    {
      return 0;
    }

  if(trn -> value == val)
    {
      printf("%d\n", trn -> value);
      return 1;
    }

  if(printPathHelper(trn -> left, val) || printPathHelper(trn -> right, val))
    {
      printf("%d\n", trn -> value);
      return 1;
    }

  return 0;
}

void printPath(Tree * tr, int val)
{
  printPathHelper(tr -> root, val);
}
#endif
