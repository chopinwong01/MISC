#include <stdio.h>
#include <stdlib.h>

int *countArray(char* filename){
  FILE *fp;
  char *a;
  int c=0;
  fp = fopen(filename,"r");
  fseek(fp,0,SEEK_END);
  int pos = ftell(fp);
  fclose(fp);
  fp = fopen(filename,"r");
  a=(char*)calloc(pos,sizeof(int));
  while(1)
  {
    a[c] = fgetc(fp);
    if(feof(fp)){break;}
    c++;
  }
  fclose(fp);

  int *r;
  r= (int*)calloc(26, sizeof(int));
  for (int i = 0; i < 26; ++i)
  { 
    r[i]=0;
  }
  int i = 0;
  while( a[i] != (char)NULL){
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

int main(int argc, char* argv[]){
  int *r;
  r=(char*)calloc(100,sizeof(int));
  r=countArray(argv[1]);
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