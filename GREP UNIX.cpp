#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <pattern> <file>\n", argv[0]);
        return 1;
    }

    char *pattern = argv[1];
    char *file = argv[2];

    FILE *file_ptr = fopen(file, "r");
    if (file_ptr == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file_ptr) != NULL) {
        if (strstr(line, pattern) != NULL) {
            printf("%s\n", line);
        }
    }

    fclose(file_ptr);

    return 0;
}