#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 50

int main() {
    int f[MAX_BLOCKS];  // Array representing blocks: 0=free, 1=allocated
    int i, indexBlock, n, blocks[10];

    // Initialize all blocks as free
    for (i = 0; i < MAX_BLOCKS; i++)
        f[i] = 0;

    printf("Enter the index block number (0–%d): ", MAX_BLOCKS - 1);
    scanf("%d", &indexBlock);

    if (indexBlock < 0 || indexBlock >= MAX_BLOCKS) {
        printf("Invalid index block number!\n");
        return 0;
    }

    if (f[indexBlock] == 1) {
        printf("Block already allocated.\n");
        return 0;
    }

    f[indexBlock] = 1; // Allocate index block

    printf("Enter the number of blocks allocated for the file: ");
    scanf("%d", &n);

    printf("Enter the block numbers for the file (space separated): ");
    for (i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    // Check allocation availability
    for (i = 0; i < n; i++) {
        if (blocks[i] < 0 || blocks[i] >= MAX_BLOCKS || f[blocks[i]] == 1) {
            printf("Block %d cannot be allocated (already used or invalid).\n", blocks[i]);
            return 0;
        }
    }

    // Allocate blocks
    for (i = 0; i < n; i++)
        f[blocks[i]] = 1;

    // Display allocation
    printf("\nFile allocated successfully!\n");
    printf("Index Block: %d\n", indexBlock);
    printf("Blocks allocated to file:\n");
    for (i = 0; i < n; i++)
        printf("  %d --> %d\n", indexBlock, blocks[i]);

    return 0;
}
