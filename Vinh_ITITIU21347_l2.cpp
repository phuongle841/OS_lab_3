#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to check if a number is part of the Fibonacci sequence
int isFibonacci(int n) {
    if (n <= 1) return 1;
    
    int a = 1, b = 1, c;
    while (c < n) {
        c = a + b;
        if (c == n) return 1;
        a = b;
        b = c;
    }
    
    return 0;
}

// Function for each thread to verify a number
void* verifyFibonacci(void* arg) {
    int number = *((int*)arg);
    
    if (isFibonacci(number))
        printf("%d is a Fibonacci member\n", number);
    else
        printf("%d is not a Fibonacci member\n", number);
    
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [numbers]\n", argv[0]);
        return 1;
    }
    
    pthread_t threads[argc - 1];
    
    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        if (number <= 0) {
            printf("Invalid input: %s is not a positive integer.\n", argv[i]);
            continue;
        }
        
        int* arg = (int*)malloc(sizeof(int));
        *arg = number;
        pthread_create(&threads[i - 1], NULL, verifyFibonacci, arg);
    }
    
    for (int i = 0; i < argc - 1; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}
