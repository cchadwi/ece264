// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  // count the number of integers in the file
  // Please notice that if a file contains
  // 124 378 -56
  // There are three integers: 124, 378, -56
  // DO NOT count individual character '1', '2', '4' ...
  //
  // If fopen fails, return -1
  FILE * file = fopen(filename,"r");
  if (file == NULL)
  {
    return -1;
  }
  int holder; //used as placeholder
  int count = 0;
  // Works to count every integer
  while (fscanf(file, "%d", &holder) == 1)
  {
    count++;
  }
  // remember to fclose if fopen succeeds
   fclose(file);
   return count;
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // read integers from the file.
  FILE * file = fopen(filename,"r");
  if (file == NULL)
  {
    return false;
  }
  int holder; 
  int count = 0;

  while (fscanf(file, "%d", &holder) == 1)
  {
    intArr[count] = holder;
    count++;
  }
  // if the number of integers is different from size (too
  // few or too many) return false
  if (count != size)
  {
    return false;
  }
  // if everything is fine, fclose and return true
  fclose(file);
  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  // needed by qsort
  //
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.
  //using code from hw7 viddeo
  const int * ptr1 = (const int *)p1;
  const int * ptr2 = (const int *)p2;
  int val1 = *ptr1;
  int val2 = *ptr2;
  if (val1 < val2) {return -1;}
  if (val1 == val2){return 0;}
  return 1;
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  FILE * file = fopen(filename, "w"); // w since write
  if (file == NULL)
  {
    return false;
  }
  // write integers to the file.
  // one integer per line
  int count;
  for(count = 0; count < size; count ++)
  {
    fprintf(file, "%d\n", intArr[count]);
  }

  // fclose and return true
  fclose(file);
  return true;

}
#endif
