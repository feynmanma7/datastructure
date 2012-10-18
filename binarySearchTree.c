#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 100

/*
FLYINGMAN
mayunlong1988 at gmail dot com
pre, in and post order of a binary search tree, with both recursive and non-recursive method (using stack).
*/

typedef struct tnode{
  int data;
  struct tnode *lchild, *rchild;
}tnode;

tnode *insert(tnode *p, int value){
  tnode *temp1, *temp2;
  if(p == NULL){
    p = malloc(sizeof(tnode));
    p->data = value;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
  }
  temp1 = p;
  while(temp1 != NULL){
    temp2 = temp1;
    if(temp1->data > value){
      temp1 = temp1->lchild;
    } else {
      temp1 = temp1->rchild;
    } 
  }
  if(temp2->data > value){
    temp2->lchild = malloc(sizeof(tnode));
    temp2 = temp2->lchild;
    if(temp2 == NULL){
      printf("malloc error!\n");
      exit(0);
    }
  } else {
    temp2->rchild = malloc(sizeof(tnode));
    temp2 = temp2->rchild;
    if(temp2 == NULL){
      printf("malloc error!\n");
      exit(0);
    }
  }
  temp2->data = value;
  temp2->lchild = temp2->rchild = NULL;

  return p;
}

void inorder(tnode *p){
  if(p != NULL){
    inorder(p->lchild);
    printf("%d ", p->data);
    inorder(p->rchild);
  }
}

/*
we find the last left child, and print the cur node itself, and put the right child into the stack, recursive the process until the stack is empty.
*/
void inorderStack(tnode *p){
  tnode *stack[STACKSIZE];
  int top = -1;
  if(p == NULL)
    return;
  top++;
  stack[top] = p;
  p = p->lchild;
  while(top >= 0){
    while(p != NULL){
      top++;
      stack[top] = p;
      p = p->lchild;
    }
    p = stack[top];
    top--;
    printf("%d ", p->data);
    p = p->rchild;
    if(p != NULL){
      top++;
      stack[top] = p;
      p = p->lchild;
    }
  }
}

void postorder(tnode *p){
  if(p == NULL){
    return;
  }
  postorder(p->lchild);
  postorder(p->rchild);
  printf("%d ", p->data);
}

/*
use a prev variable to keep track of the previously-traversed node. cur is the current node that's on top of the stack. when prev is cur's parent, we're traversing down the tree. in this case, we try to traverse to cur's left child if available. if it is not available, we look at cur's right child. if both left and right child do not exist, we print cur's value and pop it off the stack.
*/
void postorderStack(tnode *p){
  if(p == NULL){
    return;
  }
  tnode *stack[STACKSIZE];
  int top = -1;
  stack[++top] = p;
  /* previously traversed node */
  tnode *prev = NULL;
  while(top >= 0){
    /* currently traversed*/
    tnode *cur = stack[top];
    // we are traversing down the tree
    if(!prev || prev->lchild == cur || prev->rchild == cur){
      if(cur->lchild){
	stack[++top] = cur->lchild;
      } else if(cur->rchild){
	stack[++top] = cur->rchild;
      } else {
	printf("%d ", cur->data);
	top--;
      }
    }
    // we are traversing from the left
    else if(cur->lchild == prev){
      if(cur->rchild){
	stack[++top] = cur->rchild;
      } else {
	printf("%d ", cur->data);
	top--;
      }
    }
    // we are traversing from the right
    else if(cur->rchild == prev){
	printf("%d ", cur->data);
	top--;
    }      
    prev = cur;
  }// while
}

void preorder(tnode *p){
  if(p == NULL){
    return;
  }
  printf("%d ", p->data);
  preorder(p->lchild);
  preorder(p->rchild);
}

/*
  we print the current node, and put the p->rchild into the stack(if exists), and then let p be p->lchild, until the stack is empty
*/
void preorderStack(tnode *root){
  if(root == NULL){
    return;
  }
  tnode *stack[STACKSIZE];
  int top = -1;
  tnode *p = root;
  stack[++top] = p;
  while(top >= 0){
    while(p != NULL){
      printf("%d ", p->data);
      if(p->rchild){
	stack[++top] = p->rchild;
      }
      p = p->lchild;
    }
    p = stack[top--];
  }
}

void main(){
  printf("input numbers to be inserted: \n");
  int value; 
  tnode *p = NULL;
  while(scanf("%d", &value) != EOF){
    p = insert(p, value);
  }

  /* inorder */
  printf("inorder result: \n");
  inorder(p);
  printf("\ninorder with stack result: \n");
  inorderStack(p);
  printf("\n");

  /* postorder */
  printf("postorder result: \n");
  postorder(p);
  printf("\n");
  printf("postorder with stack result: \n");
  postorderStack(p);
  printf("\n");

  /* preorder */
  printf("preorder result: \n");
  preorder(p);
  printf("\n");
  printf("preorder with stack result: \n");
  preorderStack(p);
  printf("\n");
}
