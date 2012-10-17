#include <stdio.h>
#include <stdlib.h>
#define MAX 3 /* maximum size of  a substack */
#define MAXSUB 3 /* maximum number of substacks */

/*
FLYINGMAN
mayunlong1988 at gmail dot com
setofStacks is composed of several stacks, will create a new 
stack once the previous one exceeds capacity.
 */

void push(int stack[][MAX], int *top, int value, int *nowSub){
  if(*nowSub >= MAXSUB){
    printf("sub stack full error!\n");
    exit(0);
  } 

  if(*top < MAX - 1){
    *top = *top + 1;
  } else {
    *nowSub = *nowSub + 1;
    if(*nowSub >= MAXSUB ){
      printf("sub stack full error!\n");
      exit(0);
    } 
    *top = 0;
  }
 stack[*nowSub][*top] = value;
}

void pop(int stack[][MAX], int *value, int *nowSub, int *top){
  if(*nowSub < 0){
    printf("stack empty!\n");
    exit(0);
  }
  if(*top >= 0){
    *value = stack[*nowSub][*top];
    *top = *top - 1;
    if(*top < 0){
      *nowSub = *nowSub - 1;
      if(*nowSub < 0){
	printf("stack empty!\n");
	exit(0);
      }
      *top = MAX - 1;
    }
  }
}



void main(){
  int top = -1, nowSub = 0;
  int stack[MAXSUB][MAX];
  int n, value;
  printf("input value to be pushed: \n");

  while(scanf("%d", &value) != EOF){
    push(stack, &top, value, &nowSub);
    printf("input value to be pushed: \n");
  }

  printf("pop the stack, 0 for end: \n");
  while(scanf("%d", &n) != EOF){
    pop(stack, &value, &nowSub, &top);
    printf("pop value is: %d\n", value);
    printf("pop the stack, 0 for end: \n");
  }
}
