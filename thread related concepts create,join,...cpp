#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3

void *thread_function(void *arg) {
    int thread_num = *(int *)arg;
    printf("Thread %d created\n", thread_num);
    
    sleep(2);
    
    printf("Thread %d is exiting\n", thread_num);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i, result;

    for (i = 0; i < NUM_THREADS; ++i) {
        thread_args[i] = i + 1;
        result = pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
        if (result != 0) {
            perror("Thread creation failed");
            return 1;
        }
    }

    for (i = 0; i < NUM_THREADS; ++i) {
        result = pthread_join(threads[i], NULL);
        if (result != 0) {
            perror("Thread join failed");
            return 1;
        }
    }

    if (pthread_equal(threads[0], threads[1]))
        printf("Thread 1 and Thread 2 are equal\n");
    else
        printf("Thread 1 and Thread 2 are not equal\n");

    printf("Main thread exiting\n");
    pthread_exit(NULL);

    return 0;
}
