#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define MINES 3

int main() {
    int board[SIZE][SIZE] = {0};
    int visible[SIZE][SIZE] = {0};
    srand(time(NULL));

    // Place mines
    for(int i=0; i<MINES; ) {
        int x = rand()%SIZE;
        int y = rand()%SIZE;
        if(board[x][y] != -1) {
            board[x][y] = -1;
            i++;
        }
    }

    printf("Minesweeper - Enter coordinates (0-4)\n");
    int x,y;
    while(1) {
        printf("Enter x y: ");
        scanf("%d %d", &x, &y);

        if(board[x][y] == -1) {
            printf("BOOM! Game Over\n");
            break;
        }

        // Count adjacent mines
        int count = 0;
        for(int i=-1; i<=1; i++) {
            for(int j=-1; j<=1; j++) {
                if(x+i >=0 && x+i < SIZE && y+j >=0 && y+j < SIZE)
                    count += (board[x+i][y+j] == -1);
            }
        }
        visible[x][y] = 1;
        printf("Safe! %d adjacent mines\n", count);
    }
    return 0;
}
