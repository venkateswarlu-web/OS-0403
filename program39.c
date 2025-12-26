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
    int request[50], n, head, disk_size, seek = 0, i, index;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the total disk size: ");
    scanf("%d", &disk_size);

    // Sort requests
    sort(request, n);

    // Find position where head fits
    for (i = 0; i < n; i++) {
        if (head < request[i]) {
            index = i;
            break;
        }
    }

    printf("\nHead Movement: %d", head);

    // Move towards higher end first
    for (i = index; i < n; i++) {
        seek += abs(request[i] - head);
        head = request[i];
        printf(" -> %d", head);
    }

    // Jump from end to start (circular move)
    seek += abs((disk_size - 1) - head);
    head = 0;
    seek += (disk_size - 1);
    printf(" -> %d", head);

    // Continue servicing the remaining requests (from beginning)
    for (i = 0; i < index; i++) {
        seek += abs(request[i] - head);
        head = request[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time = %d", seek);
    printf("\nAverage Seek Time = %.2f\n", (float)seek / n);

    return 0;
}
