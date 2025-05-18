#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    time_t now;
    struct tm *timeinfo;

    printf("Digital Clock [Ctrl+C to exit]\n");
    while(1) {
        time(&now);
        timeinfo = localtime(&now);
        printf("\r%02d:%02d:%02d",
               timeinfo->tm_hour,
               timeinfo->tm_min,
               timeinfo->tm_sec);
        fflush(stdout);
        sleep(1);
    }
    return 0;
}
