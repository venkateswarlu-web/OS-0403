#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], pr[n], p[n], wt[n], tat[n];
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Burst Time & Priority for P%d: ", i + 1);
        scanf("%d %d", &bt[i], &pr[i]);
    }

    // Sort by priority (descending)
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (pr[i] < pr[j]) {
                int t = pr[i]; pr[i] = pr[j]; pr[j] = t;
                t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = p[i]; p[i] = p[j]; p[j] = t;
            }

    // Waiting & Turnaround Time
    wt[0] = 0;
    for (i = 1; i < n; i++) wt[i] = wt[i - 1] + bt[i - 1];
    for (i = 0; i < n; i++) tat[i] = wt[i] + bt[i];

    // Print Table
    printf("\nP\tBT\tPR\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);

    return 0;
}

