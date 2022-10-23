// ***
// *** You MUST modify this file, only the ssort function
// ***


#include "sort.h"
#include <stdio.h>

// DO NOT MODIFY THIS FUNCTION
bool checkOrder(int * arr, int size)
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
  int ind;
  for (ind = 0; ind < (size - 1); ind ++)
    {
      if (arr[ind] > arr[ind + 1])
	{
	  return false;
	}
    }
  return true;
}


// YOU MUST MODIFY THIS FUNCTION
#ifdef TEST_SORT
void ssort(int * arr, int size)
{
  // This function has two levels of for
  // The first level specifies which element in the array
  // The second level finds the smallest element among the unsorted
  // elements

  // This is the syntax to read or write an array element:
  // int x = arr[4];
  // read the value of arr[4] and store it in x
  // arr[4] = 5;
  // stores 5 in the element arr[4]
  // Please remember that indexes start from 0.

  // After finding the smallest element among the unsorted elements,
  // swap it with the element of the index from the first level

  int x; // variable used to specify position in array
  int y; // variable used to find smallest element of array
  int min_loc; //holds the smallest location
  int place_holder; //place holder in array
  for (x = 0; x < size; x++)
  {
    min_loc = x;
    for (y = x + 1; y < size; y++)
    {
      if (arr[y] < arr[min_loc])
        {
          min_loc = y;
        } 
    }
    place_holder = arr[x];
    arr[x] = arr[min_loc];
    arr[min_loc] = place_holder;

  }
}
#endif
