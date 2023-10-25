#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define NUM_THREADS 10
static const char *progname="mtsample";
void *Print_threadid(void *threadid){
    long tid;
    tid= (long)threadid;
    fprintf(stderr,"\t %s: thread #%ld!\n",progname,tid);
    pthread_exit(NULL);
}
int main (int argc,char* argv[]){
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for ( t = 0; t < NUM_THREADS; t++)
    {
        printf("In main: creating thread %ld\n",t);
        rc = pthread_create(&threads[t],NULL,&Print_threadid,(void*)t);
        if (rc)
        {
            printf("ERROR: return code from pthread_create() is %d\n",rc);
            EXIT_FAILURE;
        }
        
    }
    for ( t = 0; t < NUM_THREADS; t++)
    {
        int status = pthread_join(threads[t],NULL);
        if (status!=0)
        {
            printf("%s: pthread_join() failed: %d\n",progname,status);
            return EXIT_FAILURE;
        }   
    }
    return EXIT_SUCCESS;
}