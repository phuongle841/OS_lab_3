#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

void* thread_f(void* n);

int main()
{ int error;
  pthread_t thread_1;
  pthread_t thread_2;
  pthread_create (&thread_1,NULL,thread_f,NULL);
 
  error = pthread_join(thread_2, NULL);
  if (error!=0){

    switch (error){
    case  ESRCH:
            printf("The identifier is not associated with any thread\n");
            break;
    case  EINVAL:
            printf("Thread not joinable or another thread is already waiting\n");
            break;
    case  EDEADLK:
            printf("A crash was detected.\n");
            break;
}}
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