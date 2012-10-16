#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
FLYINGMAN
mayunlong1988 at gmail.com
This is the best way to solve the problem:
delete the middle node of the list.
i.e.:
input: a->b->c->d->e
output:a->b->d->e
*/

typedef struct node{
  int data;
  struct node* next;
}node;


void printList(node *head){
  if(head == NULL){
    printf("This is a null list.\n");
    return;
  }
  node* cur = head;
  printf("%d", cur->data);
  while(cur->next != NULL){
    cur = cur->next;
    printf(" --> %d", cur->data);
  }
  printf("\n");
}

/*
  insert node from the end
*/
node* insertNode(node* head, int data){
  if(head == NULL){
    head = malloc(sizeof(node));
    head->data = data;
    head->next = NULL;
    return head;
  }

  node* cur = head;  
  while(cur->next != NULL){
    cur = cur->next;
  }
  node* newNode = malloc(sizeof(node));
  newNode->data = data;
  newNode->next = NULL;
  cur->next = newNode;
  return head;
}

node* deleteMiddleNode(node* head){
  if(head == NULL){
    return NULL;
  }
  node* first = head;
  node* last =  head;
  node* pre;
  while(first->next != NULL){
    first = first->next;
    if(first->next == NULL){
      break;
    } else{
      first = first->next;
      pre = last;
      last = last->next;
    }
  }

  printf("middle node is %d: \n", last->data); 
  /* delete last */
  pre->next = last->next;
  free(last);

  return head;
}

void main(){
  printf("input linkder list:\n");
  int data;
  node* head = NULL;
  while(scanf("%d", &data) != EOF){
    head = insertNode(head, data);
  }

  printList(head);
  head = deleteMiddleNode(head);
  printList(head);
 }
