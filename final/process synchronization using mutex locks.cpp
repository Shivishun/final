#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_ITERATIONS 5

pthread_mutex_t mutex;

void *threadFunction(void *arg) {
    int threadID = *((int *) arg);
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        pthread_mutex_lock(&mutex);
        printf("Thread %d: Inside critical section - Iteration %d\n", threadID, i + 1);
        pthread_mutex_unlock(&mutex);
        usleep(100000);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; ++i) {
        threadIDs[i] = i + 1;
        if (pthread_create(&threads[i], NULL, threadFunction, &threadIDs[i])) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
