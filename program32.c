#include <stdio.h>

int main() {
    int n, frames, i, j, k, pageFault = 0, least, time = 0;
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter page reference sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    int frame[frames];
    int recent[frames]; // to keep track of last used time
    for(i = 0; i < frames; i++) {
        frame[i] = -1;
        recent[i] = 0;
    }

    for(i = 0; i < n; i++) {
        int found = 0;
        // Check if page is already in frame
        for(j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                recent[j] = time++;
                break;
            }
        }

        if(!found) {
            // Find LRU page
            least = 0;
            for(j = 1; j < frames; j++) {
                if(recent[j] < recent[least])
                    least = j;
            }
            frame[least] = pages[i];
            recent[least] = time++;
            pageFault++;
        }

        // Display current frame status
        printf("Frames after accessing page %d: ", pages[i]);
        for(j = 0; j < frames; j++) {
            if(frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFault);
    return 0;
}
