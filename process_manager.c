#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>
#include <string.h>
#include "hardware.h"
#include "process_manager.h"

#define MAX_TASKS 20

pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t resource_mutex = PTHREAD_MUTEX_INITIALIZER;


typedef struct {
    char name[64];
    int ram;
    int hdd;
} Task;

Task ready_queue[MAX_TASKS];
int front = 0, rear = 0;
int active_tasks = 0;

pthread_t *thread_pool = NULL;
pid_t *task_pids = NULL;
int task_count = 0;

void enqueue(Task task) {
    pthread_mutex_lock(&queue_mutex);
    if (active_tasks == MAX_TASKS) {
        printf("Queue is full. Cannot add new task.\n");
    } else {
        ready_queue[rear] = task;
        rear = (rear + 1) % MAX_TASKS;
        active_tasks++;
        //get
        sem_post(&ready_queue_items);
        printf("Added to Queue!\n");

    }
    pthread_mutex_unlock(&queue_mutex);


}

Task dequeue() {
    pthread_mutex_lock(&queue_mutex);
    Task task = {"", 0, 0};
    if (active_tasks > 0) {
        task = ready_queue[front];
        front = (front + 1) % MAX_TASKS;
        active_tasks--;
    }
    pthread_mutex_unlock(&queue_mutex);
    return task;
}

void* thread_pool_worker(void* args) {
    while (1) {

        sem_wait(&ready_queue_items);
        Task task = dequeue();

        pthread_mutex_lock(&resource_mutex);
        if (!allocate_resources(task.ram, task.hdd)) {
            printf("Insufficient resources. Task '%s' cancelled.\n", task.name);
            pthread_mutex_unlock(&resource_mutex);
            continue;
        }
        pthread_mutex_unlock(&resource_mutex);

        sem_wait(&core_semaphore);


        pid_t pid = fork();
        if (pid == 0) {
            char full_path[128];
            snprintf(full_path, sizeof(full_path), "./tasks/%s", task.name);
            execlp("konsole", "konsole", "-e", full_path, NULL);


            exit(EXIT_FAILURE);


        } else if (pid > 0) {
            task_pids[task_count++] = pid;
            printf("✅ Running task: %s\n", task.name);
            //check
            int status;
            waitpid(pid, &status, 0);

            printf("Task completed: %s\n", task.name);


            //        wait(NULL);
            free_resources(task.ram, task.hdd);
            sem_post(&core_semaphore);
        }
    }
}


void init_thread_pool() {
    thread_pool = malloc(CORES * sizeof(pthread_t));
    task_pids = malloc(CORES * sizeof(pid_t));

    if (!thread_pool || !task_pids) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < CORES; i++) {
        pthread_create(&thread_pool[i], NULL, thread_pool_worker, NULL);
    }
}

void run_task(const char* task_name, int ram, int hdd) {
    Task task;
    strncpy(task.name, task_name, sizeof(task.name));
    task.ram = ram;
    task.hdd = hdd;
    enqueue(task);
}


void shutdown_tasks() {
    printf("Shutting down all tasks...\n");
    for (int i = 0; i < task_count; i++) {
        if (task_pids[i] > 0) {
            kill(task_pids[i], SIGTERM);
            waitpid(task_pids[i], NULL, 0);
        }
    }
    free(thread_pool);
    free(task_pids);
    printf("✅ All tasks terminated.\n");
}
