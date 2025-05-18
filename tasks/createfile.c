#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    char filename[100], content[1000];
    printf("Enter filename: ");
    scanf("%99s", filename);

    printf("Enter content (max 1000 chars):\n");
    scanf(" %[^\n]", content);

    FILE *fp = fopen(filename, "w");
    if(fp) {
        fputs(content, fp);
        fclose(fp);
        printf("File created successfully!\n");
    } else {
        perror("Error creating file");
    }
    sleep(2);
    return 0;
}
