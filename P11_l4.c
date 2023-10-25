#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* thread_f(void* n);

int main()
{
  pthread_t thread_1;
  pthread_create (&thread_1,NULL,thread_f,NULL);
 
  pthread_join(thread_1, NULL);

  return 0;
}

void* thread_f(void* n)
{
  for (int a=5;a!=0; a--)
    {
    printf("Seconds to end of thread: %i\n",a);
    sleep(1);
    }
  printf("End of thread \n");
  pthread_exit(n);
}