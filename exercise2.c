#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
#include <sys/wait.h>


bool isPerfectSquare(int x)
{
    int s = sqrt(x);
    return (s * s == x);
}
 
// Returns true if n is a Fibonacci Number, else false
bool isFibonacci(int n)
{
    // n is Fibonacci if one of 5*n*n + 4 or 5*n*n - 4 or
    // both is a perfect square
    return isPerfectSquare(5 * n * n + 4)
           || isPerfectSquare(5 * n * n - 4);
}

int a=1;
int b=1;
bool Fib(int testedNumber){
    if (testedNumber==0||testedNumber==1)
    {
        return true;
    }
    int nextFib= a+b;
    if (nextFib>testedNumber)
    {
        return false;
    }
    else if (nextFib==testedNumber)
    {
        return true;
    }
    else
    {
        a = b;
        b = nextFib;
        Fib(testedNumber);
    }
}

void *Print_threadid(void *threadid){
    long tid;
    tid= (long)threadid;
    int vOut= (int)tid;
    bool result= isFibonacci(vOut);
    printf("%d",vOut);
    if (result){
    printf(" is Fibonacci\n");
    }else
    {
    printf(" is not Fibonacci\n");
    }
    pthread_exit(NULL);
}

// defining main with arguments
int main(int argc, char* argv[])
{
    printf("You have entered %d arguments:\n", argc-1);
    pthread_t threads[argc];
    int rc;

    for (long i = 1; i < argc; i++) {
        long testSubject=atoi(argv[i]);
        if (!testSubject)
        {
            printf("this is not a number\n");
            continue;
        }
        rc = pthread_create(&threads[i],NULL,&Print_threadid,(void*)testSubject);
        if (rc)
        {
            printf("ERROR: return code from pthread_create() is %d\n",rc);
            EXIT_FAILURE;
        }
    }
    isFibonacci(5);
    return 0;
}