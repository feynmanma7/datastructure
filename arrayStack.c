#include <stdio.h>
#include <stdlib.h>

#define MAX 10 /* the maximum size of the stack */

/**
FLYINGMAN
mayunlong1988 at gmail dot com
it's an array implemention of stack
 */
void push(int stack[], int *top, int value){
  if(*top < MAX - 1){
    *top = *top + 1;
    stack[*top] = value;
  } else{
    printf("the stack is full!\n");
    exit(0);
  }
}

void pop(int stack[], int *top, int * value){
  if(*top >= 0){
    *value = stack[*top];
    *top = *top - 1;
  } else{
    printf("the stack is empty!\n");
    exit(0);
 
}
 
void main(){
  int stack[MAX];
  int top = -1;
  int n, value;
  printf("enter elment to be pushed: \n");
  while(scanf("%d", &value) != EOF){
     push(stack, &top, value);
     printf("enter elment to be pushed: \n");
  }

  printf("pop the stack, 0 for end:\n");
  while(scanf("%d", &n) != EOF){

    if(n == 0){
      break;
    }
    pop(stack, &top, &value);
    printf("%d\n", value);
    printf("pop the stack, 0 for end:\n");
  }
}
