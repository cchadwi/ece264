// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw08.h"


#ifdef TEST_COUNTVECTOR
int countVector(char * filename)
{
  // count the number of vectors in the file and return the number
  // The input is a binary file. You must use fread.
  // You must not use fscanf(, "%d", ) 
  //
  // If fopen fails, return -1
  //
  //
  // For the mode of fopen, you may use "r" without b
  //
  
  
  FILE * file = fopen(filename,"r");
  if (file == NULL)
  {
    return -1;
  }
  Vector * vector = malloc(sizeof(Vector));
  int count = 0;
  // Works to count every vector

  while (fread(vector, sizeof(Vector), 1, file))
  {
    count++;
  }
  free(vector);
  fclose(file);
  return count;
}
#endif

#ifdef TEST_READVECTOR
bool readVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  // read Vectors from the file.
  // 
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  // if everything is fine, fclose and return true
  FILE * file = fopen(filename, "r");
  if(file == NULL)
  {
    return false;
  }
  int count = 0;
  count = fread(&vecArr[0],sizeof(Vector), size, file);

  if(count < size || count > size)
  {
    fclose(file);
    return false;
  }
  fclose(file);
  return true;

}
#endif

#ifdef TEST_COMPAREVECTOR
int compareVector(const void *p1, const void *p2)
{
  // compare the x attribute first
  // If the first vector's x is less than the second vector's x
  // return -1
  // If the first vector's x is greater than the second vector's x
  // return 1
  // If the two vectors' x is the same, compare the y attribute
  //
  // If the first vector's y is less than the second vector's y
  // return -1
  // If the first vector's y is greater than the second vector's y
  // return 1
  // If the two vectors' y is the same, compare the z attribute
  //
  // If the first vector's z is less than the second vector's z
  // return -1
  // If the first vector's z is greater than the second vector's z
  // return 1
  // If the two vectors' x, y, z are the same (pairwise), return 0
  if (((Vector*)p1) -> x < ((Vector*)p2) -> x)
  {
    return -1;
  }
  if (((Vector*)p1) -> x > ((Vector*)p2) -> x)
  {
    return 1;
  }
  if (((Vector*)p1) -> y < ((Vector*)p2) -> y)
  {
    return -1;
  }
  if (((Vector*)p1) -> y > ((Vector*)p2) -> y)
  {
    return 1;
  }
  if (((Vector*)p1) -> z < ((Vector*)p2) -> z)
  {
    return -1;
  }
  if (((Vector*)p1) -> z > ((Vector*)p2) -> z)
  {
    return 1;
  }
    return 0;
 
}
#endif

#ifdef TEST_WRITEVECTOR
bool writeVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  // write the array to file using fwrite
  // need to check how many have been written
  // if not all are written, fclose and return false
  // 
  // fclose and return true
  FILE * file = fopen(filename, "w");
  if(file == NULL)
  {
    return false;
  }
  int count = 0;
  count = fwrite(&vecArr[0], sizeof(Vector),size, file);
  if (count != size)
  {
    fclose(file);
    return false;
  }
  fclose(file);
  return true;
}
#endif

// This function is provided to you. No need to change
void printVector(Vector * vecArr, int size)
{
  int ind = 0;
  for (ind = 0; ind < size; ind ++)
    {
      printf("%6d %6d %6d\n",
	     vecArr[ind].x, vecArr[ind].y, vecArr[ind].z);
    }
}
