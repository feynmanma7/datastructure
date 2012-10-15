#include <stdio.h> 

/*
mayunlong1988@gmail.com
the best way to check if there are all uniq chars of a char.
 */

int isUniqChars(char *ch){
  int checker = 0;
  while(*ch != '\0'){
    int val = *ch - '0';
    if((checker & (1 << val)) > 0){
      printf("false\n");
      return 0;
    }
    checker |= (1 << val);
    ch++;
  }

  printf("true\n");
  return 1;
}

void main(){
  char a[] = "hello,world!hello";
  char b[] = "abcde";
  isUniqChars(a);
  isUniqChars(b);
}
