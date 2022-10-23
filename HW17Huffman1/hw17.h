#ifndef HW17_H
#define HW17_H

typedef struct tnode
{
  int val;
  struct tnode * left;
  struct tnode * right;
} TreeNode;

typedef struct trnode
{
  TreeNode * root;
} Tree;


int parseTool(ListNode ** head, ListNode ** tail, char array, int n)
#endif
