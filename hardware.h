#ifndef HARDWARE_H
#define HARDWARE_H

#include <semaphore.h>

extern sem_t core_semaphore;
extern sem_t ready_queue_items;
extern int TOTAL_RAM, USED_RAM;
extern int TOTAL_HDD, USED_HDD;
extern int CORES;

void init_hardware(int R, int H, int C);
int allocate_resources(int ram, int hdd);
void free_resources(int ram, int hdd);

#endif
