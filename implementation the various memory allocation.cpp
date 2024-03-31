#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_NAME_LENGTH 20

struct Directory {
    char name[MAX_NAME_LENGTH];
    char files[MAX_FILES][MAX_NAME_LENGTH];
    int num_files;
};

int main() {
    struct Directory cse_dir;
    strcpy(cse_dir.name, "CSE");
    cse_dir.num_files = 0;

    
    strcpy(cse_dir.files[cse_dir.num_files++], "A");
    strcpy(cse_dir.files[cse_dir.num_files++], "B");
    strcpy(cse_dir.files[cse_dir.num_files++], "C");

    
    printf("Directory: %s\n", cse_dir.name);
    printf("Files:\n");
    for (int i = 0; i < cse_dir.num_files; i++) {
        printf("%s\n", cse_dir.files[i]);
    }

    return 0;
}