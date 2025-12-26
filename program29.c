#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Size of the buffer

int buffer[SIZE];
int count = 0;  // Number of items in buffer

void producer(int item) {
    if (count == SIZE) {
        printf("Buffer is full! Producer has to wait.\n");
        return;
    }
    buffer[count] = item;
    count++;
    printf("Producer produced item %d\n", item);
}

void consumer() {
    if (count == 0) {
        printf("Buffer is empty! Consumer has to wait.\n");
        return;
    }
    int item = buffer[count - 1];
    count--;
    printf("Consumer consumed item %d\n", item);
}

int main() {
    int choice, item;
    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to produce: ");
                scanf("%d", &item);
                producer(item);
                break;
            case 2:
                consumer();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
