#ifndef LENGTH
#define LENGTH 50
#endif

#ifndef LINE
#define LINE 256
#endif

#include <stdio.h>
#include <stdlib.h>
#include "isort.h"

/*
 * Function:  shift_element
 * --------------------
 *	function reveieves a pointer to an array (not neccesserily to it's start) and a number.
 *  the function then moves the i numbers one cell right.
 *  function assumes that there is memory to at least i+1 cells after the array's pointer
 *  arr: pointer to an array
 *  i: number of cells to be moved
 *
 */
void shift_element (int* arr, int i){
  if (i<0){
    printf("integer in i must be positive\n");
    exit(0);
  }
  int j=i;
  int temp= *(arr+i);
  while (j>0){
    *(arr+j) = *(arr+j-1);
    j--;
  }
  *arr= temp;
}

/*
 * Function:  insertion_sort
 * --------------------
 *	function reveieves a pointer to an array and it's size len.
 *  the function then sorts array using insertion sort algorithm.
 *  further reading:  https://en.wikipedia.org/wiki/Insertion_sort
 *  arr: pointer to an array
 *  len: length of array
 *
 */
void insertion_sort (int* arr, int len){
  int count=0;
  int i, j ,key;
  for (i = 1; i < len; i++) {
    key= *(arr+i);
    j=i-1;
    while (j>=0 && *(arr+j) > key){
      //shift_element(arr+j, i-j)
      count++;
      j--;
    }
    shift_element(arr+j+1, count);
    count=0;

  }

}

int main(){
  int arr[LENGTH];
  int i=0;
  printf("enter %d integers to sort\n", LENGTH);

  for (size_t i = 0; i < LENGTH; i++) {
    scanf("%d", arr+i);
    }
    insertion_sort(arr, LENGTH);

    while (i<LENGTH-1){
      printf("%d,", *(arr+i));
      i++;
    }
    printf("%d\n", *(arr+i));
}
