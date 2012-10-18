#include <stdio.h>
#include <stdlib.h>
#define MAX 10 /* The maximum size of the queue */
/**
FLYINGMAN
mayunlong1988 at gmail dot com
it's an array implemention of queue.
 */

void insert(int queue[], int *rear, int value){
  if(*rear < MAX - 1){
    *rear = *rear + 1;
    queue[*rear] = value;
  } else{
    printf("The queue is full error!\n");
    exit(0);
  }
}

void delete(int queue[], int *front, int rear, int *value){
  if(*front == rear){
    printf("The queue is empty!\n");
    exit(0);
  }
  *front = *front + 1;
  *value = queue[*front];
}

void main(){
  printf("input the value to be inserted: \n");
  int value, n;
  int queue[MAX];
  int front = -1;
  int rear = -1;
  while(scanf("%d", &value) != EOF){
    insert(queue, &rear, value);
    printf("input the value to be inserted: \n");
  }

  printf("delete the queue, 0 for end: \n");
  while(scanf("%d", &n) != 0){
    delete(queue, &front, rear, &value);
    printf("delete value is %d: \n", value);
    printf("delete the queue, 0 for end: \n");
  }
}
