#include <stdio.h>

int main() {
    int i, j, k, n, frames, pageFault = 0, nextUse, replaceIndex;
    
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    
    int pages[50]; // limit for safety
    printf("Enter the page reference sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    
    int frame[10]; // limit for safety
    for (i = 0; i < frames; i++)
        frame[i] = -1;  // Initialize frames as empty
    
    for (i = 0; i < n; i++) {
        int pageFound = 0;
        
        // Check if the page already exists in any frame
        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                pageFound = 1;
                break;
            }
        }
        
        // If page not found -> Page Fault occurs
        if (!pageFound) {
            pageFault++;
            int emptyIndex = -1;
            
            // Check for an empty frame first
            for (j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    emptyIndex = j;
                    break;
                }
            }
            
            if (emptyIndex != -1) {
                frame[emptyIndex] = pages[i];
            } else {
                // Find the page to replace using OPTIMAL logic
                int farthest = -1;
                replaceIndex = -1;
                
                for (j = 0; j < frames; j++) {
                    nextUse = -1;
                    
                    // Find next use of current frame page
                    for (k = i + 1; k < n; k++) {
                        if (frame[j] == pages[k]) {
                            nextUse = k;
                            break;
                        }
                    }
                    
                    // If a page is not used again, replace it immediately
                    if (nextUse == -1) {
                        replaceIndex = j;
                        break;
                    }
                    
                    // Track the page used farthest in future
                    if (nextUse > farthest) {
                        farthest = nextUse;
                        replaceIndex = j;
                    }
                }
                
                frame[replaceIndex] = pages[i];
            }
        }

        // Print current frame status
        printf("\nAfter accessing page %d: ", pages[i]);
        for (j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
    }
    
    printf("\n\nTotal Page Faults = %d\n", pageFault);
    return 0;
}

