#include <stdio.h>
#include <stdbool.h>

#define NUM_FRAMES 3
#define NUM_PAGES 10

// Function to find optimal page for replacement
int findOptimalPage(int pages[], int frames[], int startIndex) {
    int idx = -1;
    int farthest = startIndex;
    for (int i = 0; i < NUM_FRAMES; i++) {
        int j;
        for (j = startIndex + 1; j < NUM_PAGES; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    idx = i;
                }
                break;
            }
        }
        // If the page is not referenced in the future, return its index
        if (j == NUM_PAGES)
            return i;
    }
    return (idx == -1) ? 0 : idx;
}

// Function to simulate optimal paging
void optimalPaging(int pages[]) {
    int frames[NUM_FRAMES];
    bool isInMemory[NUM_PAGES] = {false};
    int pageFaults = 0;

    for (int i = 0; i < NUM_FRAMES; i++)
        frames[i] = -1;

    for (int i = 0; i < NUM_PAGES; i++) {
        printf("Page reference: %d\n", pages[i]);
        if (!isInMemory[pages[i]]) {
            int pageIdx = findOptimalPage(pages, frames, i);
            if (frames[pageIdx] != -1)
                isInMemory[frames[pageIdx]] = false;
            frames[pageIdx] = pages[i];
            isInMemory[pages[i]] = true;
            pageFaults++;
            printf("Page %d loaded into frame %d\n", pages[i], pageIdx);
        } else {
            printf("Page %d is already in memory\n", pages[i]);
        }

        printf("Current Page Frames: ");
        for (int j = 0; j < NUM_FRAMES; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[NUM_PAGES] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3};

    optimalPaging(pages);

    return 0;
}
