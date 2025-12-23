#include <stdio.h>

int main() {
    int n, i, j, t = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], done[n];
    for(i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        done[i] = 0;
    }

    int completed = 0;
    while(completed < n) {
        int idx = -1, min_bt = 100000;
        for(i = 0; i < n; i++)
            if(!done[i] && at[i] <= t && bt[i] < min_bt) {
                min_bt = bt[i]; idx = i;
            }

        if(idx == -1) { t++; continue; }

        t += bt[idx];
        ct[idx] = t;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        done[idx] = 1;
        completed++;
    }

    printf("\nPID  AT  BT  CT  TAT  WT\n");
    float avgTAT=0, avgWT=0;
    for(i=0;i<n;i++){
        printf("%d    %d   %d   %d   %d   %d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
        avgTAT += tat[i]; avgWT += wt[i];
    }
    printf("\nAvg TAT = %.2f\nAvg WT = %.2f\n", avgTAT/n, avgWT/n);
    return 0;
}

