#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Playing music...\n");
    for(int i=0; i<10; i++) {
        printf("\a");  // System beep
        fflush(stdout);
        usleep(500000); // 0.5 second delay
    }
    return 0;
}
