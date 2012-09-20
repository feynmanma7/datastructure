/*  binary search algorithm, the input array must be sorted*/
#include <stdio.h>

/* 
   x : the key to be found
   array : the sorted array 
   n : the length of array
 */
int binarySearch(int x, int *array, int n){
  int low, high, mid;
  low = 0;
  high = n - 1;
  while(low < high){
    mid = (low >> 1) + (high >> 1);
    if (x < array[mid]){
      high = mid - 1;
    } else if(x > array[mid]){
      low = mid + 1;
    } else{
      return mid;
    }
  }
  return -2;
}

void main(int argc, int *argv){
  int x = 6;
  int result = 100;
  int array[] = {1, 3, 4, 5, 6, 8};
  result = binarySearch(x, array, 6);
  printf("The position of %d is: %d\n", x, result);
}
