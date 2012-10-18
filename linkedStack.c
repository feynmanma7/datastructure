#include <stdio.h>
#include <stdlib.h>

/**
FLYINGMAN
mayunlong1988 at gmail dot com
it's a linked list implemention of stack
 */
struct node{
  int data;
  struct node *link;
}node;

struct node* push(struct node *p, int value){
  struct node* temp;
  temp = malloc(sizeof(node));
  /* creates new node using data value passed as parameter */
  if(temp == NULL){
    printf("No memory available Error!\n");
    exit(0);
  }

  temp->data = value;
  temp->link = p;
  p = temp;
  return p;
}

struct node *pop(struct node *p, int *value){
  struct node *temp;
  if(p == NULL){
    printf("the stack is empty!\n");
    exit(0);
  }
  *value = p->data;
  temp = p;
  p = p->link;
  free(temp);
  return (p);
}

void main(){
  struct node *top = NULL;
  int n, value;
  printf("input value to be pushed:\n");

  while(scanf("%d", &value) != EOF){
    top = push(top, value);
    printf("input value to be pushed:\n");
  }

  printf("pop value, 0 for end:\n");			     

  while(scanf("%d", &n) != EOF){
    top =  pop(top, &value);
    printf("pop value is: %d\n", value);
    printf("input value to be pushed:\n");
  }
}
			    
			    
