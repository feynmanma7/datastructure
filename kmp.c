/* kmp algorithm */
#include <stdio.h>

/*
  p: pattern
  len: length of p
  next: next
 */
void kmpGetNext(char *p, int len, int *next){
  /*
    next[q] = max{k: k < q && pk is suffix of pq}
   */
  int i = 0, j = -1;
  next[i] = j;
  // i = j + 1
  while(i < len){
    while(j >= 0 && p[i] != p[j]) j = next[j];
    i++;
    j++;
    next[i] = j;
  }

  for(i = 0; i < len; i++){
    printf("%d ", next[i]);
  }
  printf("\n");
}

/*
  t : text
  p : pattern
 */
void kmpSearch(char *t, char *p, int tLen, int pLen, int *next){
  int i = 0, j = 0;
  while(i < tLen){
    while(j >= 0 && t[i] != p[j]) j = next[j];
    i++;
    j++;
    if(j == pLen){
      printf("Pattern occurs with shift %d\n", i - pLen);
      int k = 0;
      for(k = 0; k < tLen; k++){
	printf("%c ", t[k]);
      }
      printf("\n");
      for(k = 0; k < i - pLen; k++){
	printf("  ");// two spaces
      }
      for(k = 0; k < pLen; k++){
	printf("%c ", p[k]);
      }
      printf("\n");
      j = next[j];
    }
  }
}

void main(){
  char text[] = "bacbababacabcbababacababacad";
  char pattern[] = "ababaca";
  int tLen = 0, pLen = 0;
  while(text[tLen] != '\0')
    tLen++;
  while(pattern[pLen] != '\0')
    pLen++;
  printf("tLen = %d, pLen = %d\n", tLen, pLen);

  int next[pLen];
  kmpGetNext(pattern, pLen, next);

  kmpSearch(text, pattern, tLen, pLen, next);
}
