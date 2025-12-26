#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 50

int main() {
    int f[MAX_BLOCKS];    // 0 = free, 1 = allocated
    int i, j, start, len, k, next;

    // Initialize all blocks as free
    for (i = 0; i < MAX_BLOCKS; i++)
        f[i] = 0;

    printf("Enter the starting block of the file (0–%d): ", MAX_BLOCKS - 1);
    scanf("%d", &start);

    if (start < 0 || start >= MAX_BLOCKS) {
        printf("Invalid starting block number!\n");
        return 0;
    }

    if (f[start] == 1) {
        printf("Starting block already allocated!\n");
        return 0;
    }

    printf("Enter the length of the file (number of blocks): ");
    scanf("%d", &len);

    // Allocate starting block
    f[start] = 1;
    printf("\nFile allocated starting at block %d\n", start);
    printf("Blocks allocated:\n%d", start);

    k = 1;
    i = start;

    while (k < len) {
        next = rand() % MAX_BLOCKS;  // Randomly pick next block

        if (f[next] == 0) {
            f[next] = 1;
            printf(" -> %d", next);
            k++;
        }
    }

    printf("\n\nFile allocation successful using Linked Allocation.\n");
    printf("Starting block: %d\n", start);
    printf("Last block: %d\n", next);

    return 0;
}
