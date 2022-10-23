// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "hw21.h"


bool readArray(char * filename, int sudoku[9][9])
{
  
  FILE * fptr = fopen(filename, "r");
  if (fptr == NULL)
    {
      return false;
    }
  int i;
  int j;

  for (i = 0; i < 9; i++)
  {
    for (j = 0; j < 9; j++)
    { 
      char c;
      if (fscanf(fptr, " %c", &c) != 1)
        {
           return false;
        }
      else if (isdigit((unsigned char)c))
        {
          sudoku[i][j] = c - '0';
        }
      else
        {
          sudoku[i][j] = 0;
        }
    }
  }
  fclose(fptr);
  return true;
}

int main(int argc, char * * argv)
{
  // argv[1]: input file
  int row = 0; 
  int col = 0;
  if (argc < 2)
    {
      return EXIT_FAILURE;
    }
    int sudoku[9][9];
  if (readArray(argv[1], sudoku) == false)
    {
      return EXIT_FAILURE;
    }
    
  if (solveSudoku(sudoku, row, col)== true)
  {
    printArray(sudoku);
    return EXIT_SUCCESS;
  }
  
  return EXIT_FAILURE;
}
