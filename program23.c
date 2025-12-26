#include <stdio.h>
int main(){
    int block[]={100,500,200,300,600},process[]={212,417,112,426};
    int m=5,n=4,alloc[4]; for(int i=0;i<n;i++) alloc[i]=-1;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        if(block[j]>=process[i]){alloc[i]=j; block[j]-=process[i]; break;}
    printf("Process\tSize\tBlock\n");
    for(int i=0;i<n;i++) printf("%d\t%d\t%d\n",i+1,process[i],(alloc[i]+1));
}
