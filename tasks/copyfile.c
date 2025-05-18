#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char file1[100];
    char file2[100];

    printf("Enter src: ");
    scanf("%99s", file1);
    printf("Enter dest: ");
    scanf("%99s", file2);



    FILE *src = fopen(file1, "r");
    FILE *dest = fopen(file2, "w");

    if(!src || !dest) {
        perror("File error");
        return 1;
    }

    char ch;
    while((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    fclose(src);
    fclose(dest);
    printf("File copied successfully!\n");
    sleep(2);
    return 0;
}
