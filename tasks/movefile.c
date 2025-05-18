#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {

    char file1[100];
    char file2[100];

    printf("Enter src: ");
    scanf("%99s", file1);
    printf("Enter dest: ");
    scanf("%99s", file2);

    if(rename(file1, file2)) {
        perror("Error moving file");
        return 1;
    }
    printf("File moved successfully!\n");
    sleep(2);
    return 0;
}
