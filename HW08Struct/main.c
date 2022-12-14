// ***
// *** You must modify this file
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw08.h"

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
  // argv[1]: name of input file (binary)
  // argv[2]: name of output file (binary)

  // check whether there are three arguments.
  // If not, return EXIT_FAILURE. DO NOT print anything
  if (argc != 3)
  {
    return EXIT_FAILURE;
  }
  // use argv[1] as the input to countVector, save the result
  int numElem = 0;
  numElem = countVector(argv[1]);
  // if the number of vector is 0 or negative, return EXIT_FAILURE
  if (numElem <= 0) // fopen fails
    {
      return EXIT_FAILURE;
    }
  // otherwise, allocate memory for an array of vectors
  Vector * vecArr;
  
  vecArr = malloc(sizeof(Vector) * numElem);
  
  if (vecArr == NULL)
  {
    return EXIT_FAILURE;
  }
  // read the vectors from the file whose name is argv[1]. save the
  // results in the allocated array
  // if reading fails, release memory and return EXIT_FAILURE
  bool rtv = readVector(argv[1], vecArr, numElem);

  if (rtv == false) //if read fails, return EXIT_FAILURE 
    { 
      free (vecArr);
      return EXIT_FAILURE;  
    }
  

#ifdef DEBUG
  printVector(vecArr, numElem);
#endif  

qsort(&vecArr[0], numElem, sizeof(Vector), compareVector);

#ifdef DEBUG
  printf("\n");
  printVector(vecArr, numElem);
#endif  

  // write the sorted array to the file whose name is argv[2]
  // if writing fails, release memory and return EXIT_FAILURE
  
  rtv = writeVector(argv[2], vecArr, numElem);
  if (rtv == false) // read fail
    {
      // release memory
      free(vecArr);
      return EXIT_FAILURE;
    }

  // release memory, return EXIT_SUCCESS
  return EXIT_SUCCESS;
}
#endif
