#include <stdio.h>

int main(){
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int n = sizeof(processSize)/sizeof(processSize[0]);
    int allocation[n];
    for(int i=0;i<n;i++) allocation[i]=-1;

    for(int i=0;i<n;i++){
        int best=-1;
        for(int j=0;j<m;j++)
            if(blockSize[j]>=processSize[i])
                if(best==-1 || blockSize[j]<blockSize[best]) best=j;
        if(best!=-1){allocation[i]=best; blockSize[best]-=processSize[i];}
    }

    printf("Process\tSize\tBlock\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\n", i+1, processSize[i], (allocation[i]+1));
    return 0;
}
