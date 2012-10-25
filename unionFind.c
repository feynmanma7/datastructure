#include <stdio.h>
#define N 10

/**
FLYINGMAN
mayunlong1988 at gmail dot com
union find
 */
void main(){
  int p, q, i, j, k;
  int id[N], size[N];
  for(i = 0; i < N; i++){
    id[i] = i;
    printf("%d ", id[i]);
    size[i] = 1;
  }
  printf("\n");

  while(scanf("%d %d", &p, &q) == 2){
    for(i = p; i != id[i]; i = id[i]){
      id[i] = id[id[i]];
    }
    for(j = q; j != id[j]; j = id[j]){
      id[j] = id[id[j]];
    }
    if(i == j){
      printf("%d and %d are in the same set.\n", p, q);
      for(k = 0; k < N; k++){
	printf("%d ", id[k]);
      }
      printf("\n");
      continue;
    } else {
      if(size[i] < size[j]){
	id[i] = j; 
	size[j] += size[i];
      } else{
	id[j] = i;
	size[i] += size[j];
      }
      printf("%d and %d are in the different set.\n", p, q);
      for(k = 0; k < N; k++){
	printf("%d ", id[k]);
      }
      printf("\n");
    }
  }
}
