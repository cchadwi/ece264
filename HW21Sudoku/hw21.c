#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hw21.h"

int gridCheck(int sudoku[9][9], int row, int col, int count)
{

  int x;
  int y;
  
  for (int index = 0; index <= 8; index ++)
  {
    if (sudoku[row][index] == count)
    {
      return 0;
    }
  }
  for (int index = 0; index <= 8; index ++)
  {
    if (sudoku[index][col] == count)
    {
      return 0;
    }
  }
  int rowStart = row - (row % 3);
  int colStart = col - (col % 3);
  
  for (x = 0; x < 3; x ++)
  {
    for (y = 0; y < 3; y ++)
    {
      if (sudoku[x + rowStart][y + colStart] == count)
      {
        return 0;
      }
    }
  }
  return 1;
}

void printArray(int sudoku[9][9])
{
  int x;
  int y;
  for (x = 0; x < 9; x++)
  {
    for (y = 0; y < 9; y++)
    {
       printf("%d",sudoku[x][y]);
    }       
    printf("\n");
  }
}

int solveSudoku(int sudoku[9][9], int x, int y)
{
  int count;

  if (x == 8 && y == 9)
  {
    return 1;
  }
  if (y == 9)
  {
    x ++;
    y = 0;
  }
  if (sudoku[x][y] > 0)
  {
    return solveSudoku(sudoku, x, y + 1);
  }
  for (count = 1; count <= 9; count ++)
  {
    if (gridCheck(sudoku, x, y, count) == 1)
    {
      sudoku[x][y] = count;
      if (solveSudoku(sudoku, x, y + 1) == 1)
      {
        return 1;
      }
    }
    sudoku[x][y] = 0;
  }
  return 0;
}

