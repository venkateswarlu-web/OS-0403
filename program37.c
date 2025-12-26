#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head, seek = 0, diff;
    int request[50];

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nDisk head movement:\n%d", head);

    // Process each request in order
    for (i = 0; i < n; i++) {
        diff = abs(request[i] - head); // distance between head and next request
        seek += diff;
        head = request[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time = %d\n", seek);
    printf("Average Seek Time = %.2f\n", (float)seek / n);

    return 0;
}
