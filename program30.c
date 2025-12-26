#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to be executed by the thread
void* threadFunction(void* arg) {
    char* message = (char*)arg;
    printf("Thread says: %s\n", message);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int rc;

    // Create first thread
    rc = pthread_create(&thread1, NULL, threadFunction, "Hello from Thread 1");
    if (rc) {
        printf("Error: Unable to create thread 1, %d\n", rc);
        exit(-1);
    }

    // Create second thread
    rc = pthread_create(&thread2, NULL, threadFunction, "Hello from Thread 2");
    if (rc) {
        printf("Error: Unable to create thread 2, %d\n", rc);
        exit(-1);
    }

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main thread exiting.\n");
    return 0;
}
