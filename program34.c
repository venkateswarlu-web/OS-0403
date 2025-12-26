#include <stdio.h>

struct File {
    char name[20];
    int start;
    int length;
};

int main() {
    struct File files[20];
    int memory[50] = {0}; // Disk blocks: 0 = free, 1 = allocated
    int n, i, j, k, start, len, flag;

    printf("Enter the number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter the name of file %d: ", i + 1);
        scanf("%s", files[i].name);
        printf("Enter the starting block of the file: ");
        scanf("%d", &start);
        printf("Enter the length (number of blocks): ");
        scanf("%d", &len);

        // Check if blocks are free
        flag = 0;
        for (j = start; j < (start + len); j++) {
            if (memory[j] == 1) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            for (j = start; j < (start + len); j++)
                memory[j] = 1;
            files[i].start = start;
            files[i].length = len;
            printf("File %s allocated from block %d to %d.\n",
                   files[i].name, start, start + len - 1);
        } else {
            printf("File %s cannot be allocated (blocks already occupied).\n", files[i].name);
            i--; // retry for same file
        }
    }

    printf("\nFile Allocation Table:\n");
    printf("--------------------------------------\n");
    printf("File Name\tStart Block\tLength\n");
    printf("--------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\n", files[i].name, files[i].start, files[i].length);
    }
    printf("--------------------------------------\n");

    // Accessing records sequentially
    printf("\nEnter file name to access sequentially: ");
    char fname[20];
    scanf("%s", fname);

    flag = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(fname, files[i].name) == 0) {
            flag = 1;
            printf("Reading file %s sequentially:\n", files[i].name);
            for (j = files[i].start; j < files[i].start + files[i].length; j++) {
                printf("Reading block %d\n", j);
            }
            break;
        }
    }

    if (!flag)
        printf("File not found!\n");

    return 0;
}
