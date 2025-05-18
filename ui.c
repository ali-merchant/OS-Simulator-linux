#include <stdio.h>
#include <stdlib.h>
#include "process_manager.h"
#include <unistd.h>

void show_main_menu() {
    int choice;
    int i=0;
    while (1) {
        if(i !=0){sleep(1);}
        i++;
        printf("\n--- 🖥  AliOS Task Menu ---\n");
        printf("1. Calculator\n");
        printf("2. Notepad\n");
        printf("3. Clock\n");
        printf("4. Calendar\n");
        printf("5. Create File\n");
        printf("6. Copy File\n");
        printf("7. Delete File\n");
        printf("8. File Info\n");
        printf("9. Alarm\n");
        printf("10. Print File\n");
        printf("11. Music\n");
        printf("12. Minesweeper\n");
        printf("13. Reverse String\n");
        printf("0. Exit OS\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  run_task("calc", 50, 10); break;
            case 2:  run_task("notepad", 100, 10); break;
            case 3:  run_task("clock", 20, 5); break;
            case 4:  run_task("calendar", 20, 5); break;
            case 5:  run_task("createfile", 30, 10); break;
            case 6:  run_task("copyfile", 40, 10); break;
            case 7:  run_task("deletefile", 30, 5); break;
            case 8:  run_task("fileinfo", 20, 5); break;
            case 9:  run_task("alarm", 30, 5); break;
            case 10: run_task("printfile", 50, 10); break;
            case 11: run_task("music", 25, 5); break;
            case 12: run_task("minesweeper", 50, 10); break;
            case 13: run_task("reverseString", 30, 5); break;
            case 0:
                printf("Shutting down OS...\n");
                shutdown_tasks();
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

    }
}
