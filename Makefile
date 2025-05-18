#//makefile

CC = gcc
CFLAGS = -Wall
BIN = os_sim

SRCS = main.c ui.c hardware.c process_manager.c
OBJS = $(SRCS:.c=.o)

TASKS = calc clock  createfile copyfile fileinfo alarm printfile music minesweeper reverseString movefile notepad calendar deletefile
.PHONY: all clean tasks

all: $(BIN) tasks

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

tasks:
	@for task in $(TASKS); do \
		echo "Compiling $$task.c..."; \
		$(CC) tasks/$$task.c -o tasks/$$task; \
	done

clean:
	rm -f *.o $(BIN) tasks/*
