#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    char filename[100], content[1000];
    printf("Enter filename: ");
    scanf("%99s", filename);



    if(remove(filename) == -1) {  // Fixed condition
        perror("Error deleting file");
        return 1;
    }
    printf("File deleted successfully!\n");
    sleep(2);
    return 0;
}
