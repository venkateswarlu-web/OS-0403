#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter no. of processes: ");
    scanf("%d", &n);

    int bt[n], p[n], wt[n], tat[n];
    float avg_wt = 0, avg_tat = 0;

    for (i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }

    // Sort by burst time
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (bt[j] > bt[j+1]) {
                int t = bt[j]; bt[j] = bt[j+1]; bt[j+1] = t;
                t = p[j]; p[j] = p[j+1]; p[j+1] = t;
            }

    wt[0] = 0;
    for (i = 1; i < n; i++) wt[i] = wt[i-1] + bt[i-1];
    for (i = 0; i < n; i++) { tat[i] = wt[i] + bt[i]; avg_wt += wt[i]; avg_tat += tat[i]; }

    printf("\nP\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    printf("\nAvg WT: %.2f\nAvg TAT: %.2f\n", avg_wt/n, avg_tat/n);
    return 0;
}

