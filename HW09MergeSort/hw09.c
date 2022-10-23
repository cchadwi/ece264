// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw09.h"

// DO NOT MODIFY --->>>> From Here
// Do not modify this function. It is used for grading.
void printInput(char * msg, int * arr, int l, int m, int r)
{
  printf("%s(%6d, %6d, %6d)", msg, l, m, r);
  int ind;
  for (ind = l; ind <= r; ind ++)
    {
      printf("%d\n", arr[ind]);
    }
}
// DO NOT MODIFY <<<<--- Until Here

#ifdef TEST_READDATA
// the input file is binary, storing integers
//
// arr stores the address of a pointer for storing the
// address of the allocated memory
//
// size stores the address keeping the size of the array
bool readData(char * filename, int * * arr, int * size)
{
  // use fopen to open the file for read
  // return false if fopen fails
  FILE * file = fopen(filename, "r");
  if (file == NULL)
  {
    return false;
  }

  // use fseek to go to the end of the file
  // check whether fseek fails
  // if fseek fails, fclose and return false
  long old_file = ftell(file);
  fseek(file, 0L, SEEK_END); 
  if (old_file == ftell(file))
  {
    fclose(file);
    return false;
  }

  // use ftell to determine the size of the file
  int file_size = ftell(file)/sizeof(int);
  
  // use fseek to go back to the beginning of the file
  // check whether fseek fails
  // if fseek fails, fclose and return false
  old_file = ftell(file);
  fseek(file, 0, SEEK_SET); 
  if (old_file == ftell(file))
  {
    fclose(file);
    return false;
  }

  // allocate memory for the array
  int * aloc_arr;
  aloc_arr = malloc(sizeof(int) * file_size); 

  // if malloc fails, fclose and return false
  if (aloc_arr == NULL)
  {
    fclose(file);
    return false;
  }

  // use fread to read the number of integers in the file
  int num_check = fread(& aloc_arr[0], sizeof(int), file_size, file); 

  // if fread does not read the correct number
  // release allocated memory
  // fclose
  // return false
  if (num_check != file_size)
  {
    free(aloc_arr);
    fclose(file);
    return false;
  }

  // if fread succeeds
  // close the file
    fclose(file);
  
  // update the argument for the array address
  * arr = aloc_arr; 

  // update the size of the array
  * size = file_size; 
  
  return true;
}
#endif

#ifdef TEST_WRITEDATA
// the output file is binary, storing sorted integers
// write the array of integers to a file
// must use fwrite. must not use fprintf
bool writeData(char * filename, const int * arr, int size)
{
  // fopen for write
  FILE * file = fopen(filename, "w");

  // if fopen fails, return false
  if (file == NULL)
  {
    return false;
  }
   
  // use fwrite to write the entire array to a file
  int count;
  count = fwrite(&arr[0], sizeof(int), size, file);

  // check whether all elements of the array have been written
   // if not all elements have been written, return false
  if (count != size)
  // fclose
  {
    fclose(file);
    return false;
  }

  // if all elements have been written, return true
  fclose(file);
  return true;

}
#endif


#ifdef TEST_MERGE
// input: arr is an array and its two parts arr[l..m] and arr[m+1..r]
// are already sorted
//
// output: arr is an array and all elements in arr[l..r] are sorted
//
// l, m, r mean left, middle, and right respectively
//
// You can assume that l <= m <= r.
//
// Do not worry about the elements in arr[0..l-1] or arr[r+1..]

static void merge(int * arr, int l, int m, int r)
// a static function can be called within this file only
// a static function is invisible to other files
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge in", arr, l, m, r);
#endif

  // if one or both of the arrays are empty, do nothing
  if (l == m || r == m)
  {
    return;
  }

  // Hint: you may consider to allocate memory here.
  // Allocating additiional memory makes this function easier to write
  int * left = malloc(sizeof(int) * (m - l + 1));
  int * right = malloc(sizeof(int) * (r - m));

  int left_count;
  int right_count;

  for(left_count = 0; left_count < m - l + 1; left_count ++)
  {
    left[left_count] = arr[l + left_count];
  }
  for(right_count = 0; right_count < r - m; right_count ++)
  {
    right[right_count] = arr[m + 1 + right_count];
  }

  // merge the two parts (each part is already sorted) of the array
  // into one sorted array
 left_count = 0;
 right_count = 0;

 int merge_center = l;

 while(left_count < m - l + 1 && right_count < r - m)
 {
   if(left[left_count] <= right[right_count])
   {
     arr[merge_center] = left[left_count];
     left_count++;
   }
   else
   {
     arr[merge_center] = right[right_count];
     right_count++;
   }
   merge_center++;
 }

 while(left_count < m - l + 1)
 {
   arr[merge_center] = left[left_count];
   merge_center++;
   left_count++;
 }

 while(right_count < r - m)
 {
   arr[merge_center] = right[right_count];
   merge_center++;
   right_count++;
 }
 free(left);
 free(right);

  // the following should be at the bottom of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge out", arr, l, m, r);
#endif
}
#endif

// merge sort has the following steps:

// 1. if the input array has one or no element, it is already sorted
// 2. break the input array into two arrays. Their sizes are the same,
//    or differ by one
// 3. send each array to the mergeSort function until the input array
//    is small enough (one or no element)
// 4. sort the two arrays 
#ifdef TEST_MERGESSORT
void mergeSort(int arr[], int l, int r) 
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("mergeSort", arr, l, r, -1);
#endif

  // if the array has no or one element, do nothing
  if (l > r) 
  {
    return;
  }
  if (l == r)
  {
    return;
  }

  // divide the array into two arrays
  // call mergeSort with each array
  // merge the two arrays into one
  int m =(l + r) / 2;
  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);
  merge(arr, l, m, r);

  return;
} 
#endif
