#include <stdio.h>

int *countArray(char *a){
  int *r;
  r= (int*)calloc(26, sizeof(int));

  for (int i = 0; i < 26; ++i)
  { 
    r[i]=0;
  }
  int i = 0;
  while( a[i] != NULL){
    int j = a[i] - 65;
    if( a[i] < 123 && a[i] > 96){j = a[i] - 97;}
    if( j < 26 && j >= 0){
      r[j]++;
    }
    i ++;
  }
  r[26] = i;
  return r;
}

int main(){
  char *a;
  gets(a);
  int *r;
  r=countArray(a);
  printf("(%d characters)\n",r[26]);

  printf("characters\t|\t");
  for (int i = 0; i < 13; ++i)
  {
    printf("%c \t",i+65);
  }

  printf("\nfrequency\t|\t");
  for (int i = 0; i < 13; ++i)
  {
    printf("%d\t",r[i]);
  }
  printf("\n");

  for (int i = 0; i < 128; ++i)
  {
    printf("-");
  }

  printf("\ncharacters\t|\t");
  for (int i = 13; i < 26; ++i)
  {
    printf("%c \t",i+65);
  }
  printf("\nfrequency\t|\t");
  for (int i = 13; i < 26; ++i)
  {
    printf("%d\t",r[i]);
  }
  printf("\n");




  return 0;
}