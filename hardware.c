#include <stdio.h>
#include <semaphore.h>
#include "hardware.h"

sem_t core_semaphore;
sem_t ready_queue_items;
int TOTAL_RAM = 0, USED_RAM = 0;
int TOTAL_HDD = 0, USED_HDD = 0;
int CORES = 0;

void init_hardware(int R, int H, int C) {
    sem_init(&core_semaphore, 0, C);
    sem_init(&ready_queue_items, 0, 0);

    int sval=0,rval=0;
    sem_getvalue(&core_semaphore,&sval);
    sem_getvalue(&ready_queue_items,&rval);

    TOTAL_RAM = R;
    TOTAL_HDD = H;
    CORES = C;
}

int allocate_resources(int ram, int hdd) {
    if (USED_RAM + ram > TOTAL_RAM || USED_HDD + hdd > TOTAL_HDD)
        return 0;
    USED_RAM += ram;
    USED_HDD += hdd;
    return 1;
}

void free_resources(int ram, int hdd) {
    USED_RAM -= ram;
    USED_HDD -= hdd;
}
