#include <stdio.h>
#include <string.h>

/*
currently i don't know why, it's wrong now.
*/

char* mystrcat(char* s, char* append){
  size_t i;
  size_t len1 = strlen(s); 
  size_t len2 = strlen(append);
  for(i = 0; i < len2 && append[i] != '\0'; i++){
    s[i + len1] = append[i];
    printf("s = %s\n", s);
  }
  s[i + strlen(s)] = '\0';
  return s;
}

int main(){
  char s1[] = "hello";
  char s2[] = "world";

  char *c = mystrcat(s1, s2);
  printf("c = %s\n", c);
  return 0;
}
