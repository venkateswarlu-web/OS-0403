#include <stdio.h>

int main() {
    int blockCount, processCount;
    
    // Input number of blocks and processes
    printf("Enter number of memory blocks: ");
    scanf("%d", &blockCount);
    int blockSize[blockCount], blockAllocated[blockCount];
    printf("Enter sizes of memory blocks:\n");
    for (int i = 0; i < blockCount; i++) {
        scanf("%d", &blockSize[i]);
        blockAllocated[i] = -1; // Initially no allocation
    }

    printf("Enter number of processes: ");
    scanf("%d", &processCount);
    int processSize[processCount], processAllocated[processCount];
    printf("Enter sizes of processes:\n");
    for (int i = 0; i < processCount; i++) {
        scanf("%d", &processSize[i]);
        processAllocated[i] = -1; // Initially not allocated
    }

    // Worst Fit Allocation
    for (int i = 0; i < processCount; i++) {
        int worstIndex = -1;
        for (int j = 0; j < blockCount; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIndex == -1 || blockSize[j] > blockSize[worstIndex]) {
                    worstIndex = j;
                }
            }
        }
        if (worstIndex != -1) {
            // Allocate
            processAllocated[i] = worstIndex;
            blockSize[worstIndex] -= processSize[i];
        }
    }

    // Output results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < processCount; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if (processAllocated[i] != -1)
            printf("%d\n", processAllocated[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
