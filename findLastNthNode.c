#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
FLYINGMAN
mayunlong1988 at gmail.com
This is the best way to solve the problem:
Find the nth to last elment of a singly linkded list.
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

node* findLastNode(node* head, int n){
  if(head == NULL){
    return NULL;
  }
  node* first = head;
  node* last = head;
  int i; 
  for(i = 1; i <= n; i++){
    if(first->next == NULL)
      return NULL;
    first = first->next;
  }
  while(first != NULL){
    first = first->next;
    last = last->next;
  }
  return last;
}

void main(){
  printf("input linkder list:\n");
  int data;
  node* head = NULL;
  while(scanf("%d", &data) != EOF){
    head = insertNode(head, data);
  }

  printList(head);

  printf("input the last n node: \n");
  int n;
  scanf("%d", &n);
  node* lastN = findLastNode(head, n);
  if(lastN == NULL)
    printf("no such last %d'th node.\n", n);
  else
    printf("last n'th node data is: %d\n", lastN->data);
}
