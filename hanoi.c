#include <stdio.h>

/*
FLYINGMAN
hanoi problem, recursion method
 */
/* Move the plates number to pillar */
void move(int number, char from, char to){
  printf("%d, %c --> %c\n", number, from, to);
}

/* move n plates from a to c through b */
void hanoi(char a, char b, char c, int n){
  if(n == 1){
    move(1, a, c);
  } else{
    hanoi(a, c, b, n-1);
    move(n, a, c);
    hanoi(b, a, c, n-1);
  }
}

void main(){
  int n;
  printf("input the number of plates: \n");
  scanf("%d", &n);
  char a = 'a', b = 'b', c = 'c';
  hanoi(a, b, c, n);
}
