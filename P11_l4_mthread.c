#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* thread_f_1(void* n);
void* thread_f_2(void* n);

int main()
{
  pthread_t thread_1;
  pthread_t thread_2;
  pthread_create (&thread_1,NULL,thread_f_1,NULL);
  pthread_create (&thread_2,NULL,thread_f_2,NULL);
 
  pthread_join(thread_1, NULL);
  pthread_join(thread_2, NULL);
  return 0;
}

void* thread_f_1(void* n)
{
  for (int a=5;a!=0; a--)
    {
    printf("Seconds to end of thread 1: %i\n",a);
    sleep(1);
    }
  printf("End of thread 1\n");
  pthread_exit(n);
}

void* thread_f_2(void* n)
{
  for (int a=10;a!=0; a--)
    {
    printf("Seconds to end of thread 2: %i\n",a);
    sleep(1);
    }
  printf("End of thread 2\n");
  pthread_exit(n);
}