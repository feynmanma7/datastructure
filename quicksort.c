#include <stdio.h>

void quicksort(int* arr, int left, int right){
  int i = left, j = right;
  int pivot = arr[(left + right) / 2];
  printf("pivot=%d\n", pivot);
  int temp;
  while(i <= j){
    while(arr[i] < pivot){
      i++;
    }
    while(arr[j] > pivot){
      j--;
    }

    if(i <= j){
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  }

  if(left < j){
    quicksort(arr, left, j);
  }
  if(i < right){
    quicksort(arr, i, right);
  }
}

void main(){
  int a[7] = {4, 5, 6, 7, 8, 1, -1};
  quicksort(a, 0, 6);

  int k = 0;
  for(k = 0; k <= 6; k++){
    printf("%d ", a[k]);
  }
  printf("\n");
}
