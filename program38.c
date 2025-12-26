#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int request[50], n, head, i, j, seek = 0, direction, disk_size;
    int index, temp;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the total disk size: ");
    scanf("%d", &disk_size);

    printf("Enter the head movement direction (1 = high, 0 = low): ");
    scanf("%d", &direction);

    // Sort the request queue
    sort(request, n);

    // Find head position in sorted list
    for (i = 0; i < n; i++) {
        if (head < request[i]) {
            index = i;
            break;
        }
    }

    printf("\nHead Movement: %d", head);

    // SCAN movement
    if (direction == 1) { // Move towards higher end first
        for (i = index; i < n; i++) {
            seek += abs(request[i] - head);
            head = request[i];
            printf(" -> %d", head);
        }

        // Reach end
        seek += abs((disk_size - 1) - head);
        head = disk_size - 1;
        printf(" -> %d", head);

        // Reverse direction
        for (i = index - 1; i >= 0; i--) {
            seek += abs(request[i] - head);
            head = request[i];
            printf(" -> %d", head);
        }
    } else { // Move towards lower end first
        for (i = index - 1; i >= 0; i--) {
            seek += abs(request[i] - head);
            head = request[i];
            printf(" -> %d", head);
        }

        // Reach beginning
        seek += abs(head - 0);
        head = 0;
        printf(" -> %d", head);

        // Reverse direction
        for (i = index; i < n; i++) {
            seek += abs(request[i] - head);
            head = request[i];
            printf(" -> %d", head);
        }
    }

    printf("\n\nTotal Seek Time = %d", seek);
    printf("\nAverage Seek Time = %.2f\n", (float)seek / n);

    return 0;
}
