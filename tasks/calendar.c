#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>  // Add this for system()

int main() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    const char *months[] = {"Jan","Feb","Mar","Apr","May","Jun",
        "Jul","Aug","Sep","Oct","Nov","Dec"};  // Fixed array declaration

        printf("Calendar\n");
        printf(" %s %d\n", months[tm->tm_mon], tm->tm_year + 1900);
        system("cal");
        sleep(2);
        return 0;
}
