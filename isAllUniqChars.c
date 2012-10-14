#include <stdio.h> 

/*
mayunlong1988@gmail.com
the best way to check if there are all uniq chars of a char.
 */

int isUniqChars(char *ch){
  int checker = 0;
  while(*ch++){
    checker ^= (*ch - '0');
    if(checker == 0){
      printf("false\n");
      return 0;
    }
  }
  printf("true\n");
  return 1;
}

void main(){
  char a[] = "abcdea";
  char b[] = "adcde";
  isUniqChars(a);
  isUniqChars(b);
}
