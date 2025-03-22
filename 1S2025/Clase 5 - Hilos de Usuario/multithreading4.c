#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>  
#include <sys/wait.h>

void* myFunction(void *arg)
{
    int n = *(int*)arg;  // Thread number for humans to differentiate

    static int x = 10;  // Static value shared between threads

    int y = x;  // Automatic local variable--each thread has its own

    // We just assigned x from foo, so they'd better be equal here.
    // (In all my test runs, they were, but even this isn't guaranteed!)

    printf("Thread %d: x = %d, y = %d\n", n, x, y);

    // And they should be equal here, but they're not always!
    // (Sometimes they were, sometimes they weren't!)

    // What happens is another thread gets in and increments foo
    // right now, but this thread's x remains what it was before!

    if (x != y) {
        printf("Thread %d: Error! x != y! %d != %d\n", n, x, y);
    }

    x++;  // Increment shared value

    return 0;
}

#define THREAD_COUNT 5

int main(void)
{
    pthread_t thread[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++) {
        int *n = malloc(sizeof *n);  // Holds a thread serial number
        *n = i;
        pthread_create(&thread[i], NULL, myFunction, (void *) n);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(thread[i], NULL);
    }
}