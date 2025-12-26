#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n){
    int allocation[n]; for(int i=0;i<n;i++) allocation[i]=-1;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(blockSize[j]>=processSize[i]){
                allocation[i]=j;
                blockSize[j]-=processSize[i];
                break;
            }

    printf("Process\tSize\tBlock\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\n", i+1, processSize[i], (allocation[i]+1));
}

int main(){
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int n = sizeof(processSize)/sizeof(processSize[0]);

    printf("First Fit Allocation:\n");
    firstFit(blockSize, m, processSize, n);
    return 0;
}
