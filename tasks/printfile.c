#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    char filename[100], content[1000];
    printf("Enter filename: ");
    scanf("%99s", filename);

    FILE *fp = fopen(filename, "r");
    if(!fp) {
        perror("Error opening file");
        return 1;
    }

    char ch;
    while((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
    sleep(2);
    return 0;
}
