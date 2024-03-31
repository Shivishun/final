#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
sem_t mutex, wrt;
int readCount = 0, data = 0;

void *reader(void *arg) {
    int readerID = *((int *) arg);
    while (1) {
        sem_wait(&mutex);
        readCount++;
        if (readCount == 1) {
            sem_wait(&wrt);
        }
        sem_post(&mutex);

        printf("Reader %d is reading data: %d\n", readerID, data);

        sem_wait(&mutex);
        readCount--;
        if (readCount == 0) {
            sem_post(&wrt);
        }
        sem_post(&mutex);

        usleep(rand() % 1000000); 
    }
    pthread_exit(NULL);
}

void *writer(void *arg) {
    int writerID = *((int *) arg);
    while (1) {
        sem_wait(&wrt);
        data++;
        printf("Writer %d is writing data: %d\n", writerID, data);
        sem_post(&wrt);

        usleep(rand() % 1000000);
    }
    pthread_exit(NULL);
}

int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    int i;
    int readerIDs[NUM_READERS];
    int writerIDs[NUM_WRITERS];

    for (i = 0; i < NUM_READERS; i++) {
        readerIDs[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &readerIDs[i]);
    }

    for (i = 0; i < NUM_WRITERS; i++) {
        writerIDs[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writerIDs[i]);
    }

    for (i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    for (i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
