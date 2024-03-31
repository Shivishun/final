#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

int main() {
    int reference_string[MAX_PAGES] = {0, 1, 2, 3, 0, 1, 4, 0, 1, 2};
    int frames[MAX_FRAMES];
    int page_faults = 0;
    int next_frame_index = 0;

    for (int i = 0; i < MAX_FRAMES; ++i) {
        frames[i] = -1;
    }

    printf("Reference String: ");
    for (int i = 0; i < MAX_PAGES; ++i) {
        printf("%d ", reference_string[i]);
    }
    printf("\n");

    for (int i = 0; i < MAX_PAGES; ++i) {
        int page_number = reference_string[i];
        int page_found = 0;

        for (int j = 0; j < MAX_FRAMES; ++j) {
            if (frames[j] == page_number) {
                page_found = 1;
                break;
            }
        }

        if (!page_found) {
            frames[next_frame_index] = page_number;
            next_frame_index = (next_frame_index + 1) % MAX_FRAMES;
            page_faults++;
        }

        printf("Page %d -> ", page_number);
        for (int j = 0; j < MAX_FRAMES; ++j) {
            if (frames[j] == -1)
                printf("[ ] ");
            else
                printf("[%d] ", frames[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}
