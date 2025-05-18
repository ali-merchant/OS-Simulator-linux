#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%99s", filename);

    struct stat file_info;
    if(stat(filename, &file_info)) {
        perror("Error getting file info");
        return 1;
    }

    printf("File Info for: %s\n", filename);
    printf("Size: %ld bytes\n", file_info.st_size);
    printf("Last modified: %s", ctime(&file_info.st_mtime));
    printf("Permissions: %o\n", file_info.st_mode & 0777);
    sleep(2);
    return 0;

}
