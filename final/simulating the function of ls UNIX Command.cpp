#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
 struct dirent *entry;
 DIR *dir;

 if (argc > 2) {
 printf("Usage: %s [directory]\n", argv[0]);
 return 1;
 }

 if (argc == 1) {
 dir = opendir(".");
 } else {
 dir = opendir(argv[1]);
 }

 if (dir == NULL) {
 printf("Error opening directory\n");
 return 1;
 }

 while ((entry = readdir(dir)) != NULL) {
 printf("%s\n", entry->d_name);
 }

 closedir(dir);
 return 0;
}