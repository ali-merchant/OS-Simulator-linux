#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int seconds;
    printf("Set alarm (seconds): ");
    scanf("%d", &seconds);

    printf("Alarm set for %d seconds\n", seconds);
    sleep(seconds);
    printf("\aALARM! ALARM! ALARM!\n"); // \a is bell character
    return 0;
}
