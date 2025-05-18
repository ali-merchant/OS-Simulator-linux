#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "hardware.h"
#include "ui.h"
#include "process_manager.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <RAM> <HDD> <Cores>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    init_hardware(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    sleep(1);
    init_thread_pool();

    printf("Booting OS FINAL PROJ 23p0634 23f0870...\n");
    sleep(2);
    printf("OS Successfully Loaded!\n");

    show_main_menu();
    return EXIT_SUCCESS;
}
