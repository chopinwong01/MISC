#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 3

int terminalSignal=0;

int collatzFuction(unsigned long long int n){
  int length=2;
    while (n > 2){
      if (n%2){
        n*=3;
        n++;
      } else{
        n/=2;
      }  
      length++;
    }
  return length;
}

void *task(void *x){
  int tid;
  tid = *((int *) x);
  printf("Thread %d\n", tid);
  unsigned long long int i=3+tid;
  int n=collatzFuction(i);
  while((n!=1234)&&(terminalSignal==0)){
    i+=NTHREADS;
    n=collatzFuction(i);
    if(((terminalSignal==1)||(n<0))){return NULL;}
  }
  printf("number=%llu\n",i);
  terminalSignal=1;
  return NULL;
}

int main(){
  pthread_t threads[NTHREADS];
  int thread_args[NTHREADS];
  int rc, i;

  /* spawn the threads */
  for (i=0; i<NTHREADS; ++i)
    {
      thread_args[i] = i;
      printf("spawning thread %d\n", i);
      rc = pthread_create(&threads[i], NULL, task, (void *) &thread_args[i]);
    }

  /* wait for threads to finish */
  for (i=0; i<NTHREADS; ++i) {
    rc = pthread_join(threads[i], NULL);
  }
  return 0;
}

