#include <stdio.h>
#include <stdlib.h>

/**
FLYINGMAN
mayunlong1988 at gmail dot com
it's the linked implemention of queue, actually i don't really 
understand the delete process currently. 2012.10.18
 */

typedef struct node{
  int data;
  struct node *link;
}node;

void insert(node **front, node **rear, int value){
  node *temp;
  temp = malloc(sizeof(node));
  if(temp == NULL){
    printf("no memory available error\n");
    exit(0);
  }
  temp->data = value;
  temp->link = NULL;
  if(*rear == NULL){
    *rear = temp;
    *front = *rear;
  } else{
    (*rear)->link = temp;
    *rear = temp;
  }
}

void delete(node **front, node **rear, int *value){
  node *temp;
  if((*front == *rear) && (*rear == NULL)){
    printf("the queue is empty!\n");
    exit(0);
  }
  *value = (*front)->data;
  temp = *front;
  *front = (*front)->link;
  /* i can't understand the *rear */
  if(*rear == temp){
    *rear = (*rear)->link;
  }
  free(temp);
}

void main(){
  node* front = NULL, *rear = NULL;
  int value, n;
  printf("input the value to be inserted: \n");

  while(scanf("%d", &value) != EOF){
    insert(&front, &rear, value);
    printf("input the value to be inserted: \n");
  }

  printf("delete queue, 0 for end!\n");
  while(scanf("%d", &n) != 0){
    delete(&front, &rear, &value);
    printf("delete value is: %d \n", value);
    printf("delete queue, 0 for end!\n");
  }
}
