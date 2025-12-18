#include <stdio.h>
#define MAX 100
#define INF 1000000

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[MAX], bt[MAX], rem[MAX], pr[MAX], ct[MAX], tat[MAX], wt[MAX];
    for(int i=0;i<n;i++){
        printf("Enter AT, BT, PR for P%d: ",i+1);
        scanf("%d %d %d",&at[i],&bt[i],&pr[i]);
        rem[i]=bt[i];
    }

    int t=0, done=0;
    while(done<n){
        int idx=-1, highest=INF;
        for(int i=0;i<n;i++)
            if(rem[i]>0 && at[i]<=t && pr[i]<highest) idx=i, highest=pr[i];

        if(idx==-1){ t++; continue; } // idle CPU
        rem[idx]--; t++;
        if(rem[idx]==0){ ct[idx]=t; done++; }
    }

    float avgTAT=0, avgWT=0;
    printf("\nPID  AT  BT  PR  CT  TAT  WT\n");
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i]; wt[i]=tat[i]-bt[i];
        avgTAT+=tat[i]; avgWT+=wt[i];
        printf("%d    %d   %d   %d   %d   %d   %d\n",i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAvg TAT = %.2f\nAvg WT = %.2f\n",avgTAT/n,avgWT/n);
    return 0;
}




