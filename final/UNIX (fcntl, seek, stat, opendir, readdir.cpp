#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

int main() {
 int fd = open("test.txt", O_RDONLY);
 struct stat file_stat;
 fstat(fd, &file_stat);
 printf("File size: %ld\n", (long)file_stat.st_size);

 DIR *dir = opendir(".");
 struct dirent *entry;
 while ((entry = readdir(dir)) != NULL) {
 printf("%s\n", entry->d_name);
 }
 closedir(dir);
 return 0;
}