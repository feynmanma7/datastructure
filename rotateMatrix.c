#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

/*
FLYINGMAN
mayunlong1988 at gmail.com
the best way to rotate a matrix, can be used in rotate a image.
rotate in place.
*/

void printMatrix(int n, int** m){
  int i, j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}

/*
a, b, c, d are named by the beijing subway exits.
 */
void rotate(int n, int** m){
  int i, j, layer;
  for(layer = 0; layer < n / 2; ++layer){
    int from = layer;
    int to = n - 1 - layer;
    for(i = from; i < to; ++i){
      int offset = i - from;
      // a
      int a = m[from][i];

      // b --> a 
      m[from][i] = m[to-offset][from];

      // c --> b
      m[to-offset][from] = m[to][to-offset];

      // d --> c
      m[to][to-offset] = m[i][to];

      // a --> d
      m[i][to] = a;
    }  
  }  
}

/*
it's a wrong way, i just rotate the outer matrix, but it's needed to rotate all...
each time, move m[i][j] to m[n-1-j][i]
fromVal to toVal
*/
void rotateMatrix(int n, int** m){
  int i, j;
  int count = 0;
  int row = 0, col = 0;
  int temp = 0, fromVal, toVal;

  int visited[n];
  for(i = 0; i < n; i++){
    visited[i] = 0;
  }  

  int newRow = -1, newCol = -1, oldRow = 0, oldCol = 0;

  for(i = 0; i < n; i++){
    row = 0;
    col = i;
    if(visited[i] == 0){
      oldRow = row;
      oldCol = col;
      fromVal = m[row][col];
      while(!(newRow == oldRow && newCol == oldCol)){
	if(row == 0){
	  visited[col] = 1;
	}
	newRow = n - 1 - col;
	newCol = row;
	printf("(%d, %d) --> (%d, %d)\n", row, col, newRow, newCol);
	row = newRow;
	col = newCol;

	toVal = m[row][col];
	m[row][col] = fromVal;
	fromVal = toVal;
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
  rotate(n, matrix);
  printf("the rotateMatrix result is: \n");
  printMatrix(n, matrix);
}
