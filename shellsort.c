/* shell sort*/
#include <stdio.h>

/*
array : the array to be sorted, increment sort
n: the length of array
 */
void shellsort(int *array, int n){
  int gap, i, j, temp, k;
  for(gap = n / 2; gap > 0; gap /= 2){
    for(i = gap; i < n; i++){
      for(j = i - gap; j >= 0 && array[j] > array[j+gap]; j -= gap){
	temp = array[j];
	array[j] = array[j+gap];
	array[j+gap] = temp;
      }
    }
   for(k = 0; k < n; k++){
     printf("%d ", array[k]);
   }
   printf("\n");
  }
}


void main(){
  int array[] = {3, 5, 7, 1, 2, 4, 6};
  int len = 7;
  shellsort(array, len);
}
