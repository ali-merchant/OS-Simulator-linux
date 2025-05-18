#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

#define AUTOSAVE_INTERVAL 30 // Seconds

FILE *fp;
char filename[100];
int changed = 0;

void auto_save(int sig) {
    if(changed) {
        printf("\nAuto-saving...\n");
        fflush(fp);
        changed = 0;
    }
    alarm(AUTOSAVE_INTERVAL);
}

int main() {
    signal(SIGALRM, auto_save);
    alarm(AUTOSAVE_INTERVAL);

    printf("Enter filename: ");
    scanf("%99s", filename);
    fp = fopen(filename, "w+");

    if(!fp) {
        perror("Error creating file");
        return 1;
    }

    printf("Notepad [Ctrl+D to save & exit]\n");
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), stdin)) {
        fputs(buffer, fp);
        changed = 1;
    }

    fclose(fp);
    return 0;
}
