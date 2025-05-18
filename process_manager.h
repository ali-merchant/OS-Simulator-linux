#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H

#include <pthread.h>
#include <sys/types.h>

extern pthread_t *thread_pool;
extern pid_t *task_pids;
extern int task_count;

void init_thread_pool();
void run_task(const char *path, int ram, int hdd);
void shutdown_tasks();

#endif
