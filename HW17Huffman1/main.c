#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hw17.h"

static bool readArray(const char * filename, int * * array, int * size)
{
  FILE * fptr = fopen(filename, "r");
  if (fptr == NULL)
    {
      return false;
    }
  int numint = 0;
  int value;
  while (fscanf(fptr, "%d", & value) == 1)
    {
      numint ++;
    }
  if (numint == 0)
    {
      // no integer to read
      return false;
    }
  * size = numint;
  int * arr = malloc(sizeof(int) * numint);
  fseek (fptr, 0, SEEK_SET);
  int ind = 0;
  while (ind < numint)
    {
      if (fscanf(fptr, "%d", & arr[ind]) != 1)
	{
	  fprintf(stderr, "SOMETHING WRONG\n");
	  free (arr);
	  * size = 0;
	  return false;
	}
      ind ++;
    }
  fclose (fptr);
  * array = arr;
  return true;
}

int main(int argc, char * * argv)
{
  char * arr;
  int size;
  bool rtv;

  // Read input
  rtv = readArray(argv[1], & arr, & size);
  if (rtv == false)
    {
      return EXIT_FAILURE;
    }

  List * newList = parseTool(arr, size - 1);
 
  return EXIT_SUCCESS;

}