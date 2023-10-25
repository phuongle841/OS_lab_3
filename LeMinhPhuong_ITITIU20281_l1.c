#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
// defining main with arguments
int main(int argc, char* argv[])
{
    printf("You have entered %d arguments:\n", argc-1);
 
    for (int i = 1; i < argc; i++) {
        int testSubject=atoi(argv[i]);
        if (!testSubject)
        {
            printf("this is not a number\n");
            continue;
        }
        
        // printf("%s\n", argv[i]);
        printf("%d",testSubject);
        if (Fib(testSubject)){
        printf(" is Fibonacci\n");
        }else
        {
        printf(" is not Fibonacci\n");
        }
    }
    return 0;
}
