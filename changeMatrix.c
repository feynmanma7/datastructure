#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/*
FLYINGMAN
mayunlong1988 at gmail.com
the best way to solve the problem:
if an element in an M*N matrix is 0, its entire row and column is set to 0
*/

void printMatrix(int n, int** m){
  int i, j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%2d ", m[i][j]);
    }
    printf("\n");
  }
}


void changeMatrix(int n, int** m){
  int i, j;
  int row[n], col[n];
  for(i = 0; i < n; i++){
    row[i] = 0;
    col[n] = 0;
  }

  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++){
      if(m[i][j] == 0){
	row[i] = 1;
	col[j] = 1;
      }
    }

  for(i = 0; i < n; i++){
    if(row[i] == 1){
      for(j = 0; j < n; ++j){
	m[i][j] = 0;
      }
    }
    if(col[i] == 1){
      for(j = 0; j < n; ++j){
	m[j][i] = 0;
      }
    }
  }
}

		  
void main(){
  int n;
  printf("input n: \n");
  scanf("%d", &n);

  printf("input the matrix: \n");
  int** matrix;
  matrix = malloc(sizeof(int) * n);  
  int i, j;
  for(i = 0; i < n; i++){
    matrix[i] = malloc(sizeof(*matrix[i]) * n);
  }

  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++){
      scanf("%d", &matrix[i][j]);
    }

  printMatrix(n, matrix);
  changeMatrix(n, matrix);
  printf("the change result is : \n");
  printMatrix(n, matrix);
}
