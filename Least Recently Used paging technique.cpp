#include <stdio.h>
#include <stdlib.h>

#define NUM_FRAMES 3 

typedef struct {
    int page_num;
    int last_used; 
} Page;

void initMemory(Page memory[], int num_frames) {
    for (int i = 0; i < num_frames; ++i) {
        memory[i].page_num = -1; 
        memory[i].last_used = 0;
    }
}

void displayMemory(Page memory[], int num_frames) {
    printf("Physical Memory:\n");
    for (int i = 0; i < num_frames; ++i) {
        if (memory[i].page_num != -1)
            printf("| %d ", memory[i].page_num);
        else
            printf("|   ");
    }
    printf("|\n");
}

int findLRU(Page memory[], int num_frames) {
    int min_index = 0;
    int min_time = memory[0].last_used;

    for (int i = 1; i < num_frames; ++i) {
        if (memory[i].last_used < min_time) {
            min_time = memory[i].last_used;
            min_index = i;
        }
    }

    return min_index;
}

void LRU(Page pages[], int num_pages, Page memory[], int num_frames) {
    int page_faults = 0;

    for (int i = 0; i < num_pages; ++i) {
        int page_num = pages[i].page_num;
        int page_found = 0;

        for (int j = 0; j < num_frames; ++j) {
            if (memory[j].page_num == page_num) {
                memory[j].last_used = i; 
                page_found = 1;
                break;
            }
        }

        if (!page_found) {
            int lru_index = findLRU(memory, num_frames);
            memory[lru_index].page_num = page_num;
            memory[lru_index].last_used = i; 
            page_faults++;
        }

        displayMemory(memory, num_frames);
    }

    printf("Total Page Faults: %d\n", page_faults);
}

int main() {
    Page pages[] = {{1}, {3}, {2}, {4}, {2}, {3}, {1}, {5}, {4}, {3}};
    int num_pages = sizeof(pages) / sizeof(pages[0]);

    Page memory[NUM_FRAMES];
    initMemory(memory, NUM_FRAMES);

    LRU(pages, num_pages, memory, NUM_FRAMES);

    return 0;
}
