#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hw17.h"
//Huffman is a combination of tree and link lists
//creates a new tree node in huffman branch
TreeNode * newTree(char val)
{
  TreeNode * tree = malloc(sizeof(TreeNode));
  tree->val = val;
  tree->right = NULL;
  tree->left = NULL;
  return tree;
}
//creates link list that generates the new node 
ListNode * newList(char val)
{
  ListNode * node = malloc(sizeof(ListNode));
  TreeNode * tree = newTree(val);
  // node -> root and makes next and prev null
  node->root = tree;
  node->next = NULL;
  node->prev = NULL;
  return node;
}
//updates the head and tail leaf node in list
void insertList(ListNode ** head, ListNode ** tail, char val)
{
  ListNode * node = newList(val);
  if(*head == NULL)
  {
    *head = node;
    *tail = node;
    return;
  }
  //Updates tail and node
  *tail->next = node;
  node -> prev = *tail
  *tail = node;
}
//combines the tree node to be called in the array parsing. updates tree nodes
TreeNode * combineTree(TreeNode * left, TreeNode * right)
{
  TreeNode * tree = malloc(sizeof(TreeNode));
  tree->left = left;
  tree->right = right;
  return tree;
}
//parses the array and creates left and right trees, then combines them into huffman 
int parse(ListNode ** head, ListNode ** tail, char array, int n)
{
  if(array[n] == '1')
  {
    insertList(head, tail, array[n+1]);
    n++;
  }
  if(array[n] == '0')
  {
      ListNode * rightList = *tail;
      ListNode * leftList = *tail->prev;
      TreeNode * rightTree = rightList->root;
      TreeNode * leftTree = leftList -> root;
      leftList->root = combineTree(leftTree, rightTree);
      leftList->next = NULL;
  }
  return n;
}