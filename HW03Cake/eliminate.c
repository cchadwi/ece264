// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements
  int eliminate = 0; // use to specify eliminated value
  int elim_counter = 0; // variable used to count the eliminated values
  int index; // index for the for loop

  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked
  while (eliminate < n) // while loop for when the elimated numbers are less than the array
  {
    for (index = 0; index < n; index++)
    {
      // count to k and mark the element
      if (arr[index] < k)
      {
        arr[index] = elim_counter % k+1;
        elim_counter ++;
      }
      // print out the index of the element
      if (arr[index] == k)
      {
        printf("%d\n", index);
        arr[index]++;
        eliminate++;
      }
    }
  }

  // print the last one
  for (index = 0; index < n; index++)
  {
    if (arr[index] < k)
    {
      printf("%d\n", index);
    }
  }

  // release the memory of the array
  free (arr);
}
#endif
