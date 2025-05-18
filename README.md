# OS Simulator

This is a CLI-based simulator created for the Operating Systems Lab Final Project (Spring 2025). It models a simplified multi-core CPU environment using POSIX threads, semaphores, and shared memory.

🔧 Features
- Multi-core simulation with a configurable number of cores
- Simulates job arrival and scheduling
- Thread pool to represent CPU cores
- Semaphore-based synchronization between task producer and consumer
- Task queue implementation
- Deadlock-free design using mutual exclusion

📁 Project Structure
- `main.c` – Entry point, handles simulation lifecycle and user input
- `hardware.c/hardware.h` – Simulates the CPU and hardware-level behavior
- `process_manager.c/h/process_manager.h` – Handles task generation, queueing, and scheduling
- `Makefile` – Compile everything easily with `make`

🚀 How to Run

cd os-cpu-scheduler
make
./main
