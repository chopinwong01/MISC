#include <stdio.h>

int countArray(char *a){
  int i=0;
  while(a[i]!=NULL) i++;
  return i;
}

int main(){
  char *a;
  gets(a);
  printf("(%d characters)\n",countArray(a));
  return 0;
}