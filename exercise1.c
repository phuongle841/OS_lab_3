#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
#include <sys/wait.h>
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
bool Prime(int n){
    int i, flag = 1;
    
    if (n == 0 || n == 1){
        flag = 0;
    }

    for (i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
        flag = 0;
        break;
        }
    }
    return flag;
}


int main(int argc, char*argv[]){
    if (argc<2)
    {
        printf("usage: %s number1 number2 number3 ..\n", argv[0]);
    }
    for (int  i = 0; i < argc; i++)
    {
        long num = atoi(argv[i]);
        if (num<= 1)
        {
            printf("illegal number: %ld <= 1\n",num);
        }else
        {
            __pid_t pid = fork();
            if (pid<0)
            {       
                perror("fork");
                exit(1);
            }else if (pid==0)
            {
                if (Prime(num)==true)
                {
                    fprintf(stdout,"%ld is a prime\n",num);
                    printf("%30s : %d\n"," this child process id",(int)getpid());
                }
                else
                {
                    /* code */
                    fprintf(stdout,"%ld is not a prime\n",num);
                    printf("%30s : %d\n"," this child process id",(int)getpid());
                }

                exit(0);
            }else
            {
                waitpid(pid,NULL,0);
                printf("%30s : %d\n", "this parent process id", (int)getppid());
            }
        }
    }
    return 0;
}