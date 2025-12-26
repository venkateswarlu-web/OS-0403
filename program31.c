#include <stdio.h>

int main() {
    int n, frames, i, j, k, flag, page_faults = 0;
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    int pages[n];
    printf("Enter the page reference sequence:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    
    int memory[frames];
    for(i = 0; i < frames; i++)
        memory[i] = -1; // initialize frames as empty
    
    int next_to_replace = 0;
    
    printf("\nPage Reference Sequence | Memory Frames\n");
    printf("----------------------------------------\n");
    
    for(i = 0; i < n; i++) {
        flag = 0;
        // Check if page is already in memory
        for(j = 0; j < frames; j++) {
            if(memory[j] == pages[i]) {
                flag = 1; // Page hit
                break;
            }
        }
        
        if(flag == 0) { // Page fault
            memory[next_to_replace] = pages[i];
            next_to_replace = (next_to_replace + 1) % frames;
            page_faults++;
        }
        
        // Display current memory frames
        printf("Page %d: ", pages[i]);
        for(k = 0; k < frames; k++) {
            if(memory[k] != -1)
                printf("%d ", memory[k]);
            else
                printf("- ");
        }
        printf("\n");
    }
    
    printf("\nTotal Page Faults: %d\n", page_faults);
    return 0;
}
