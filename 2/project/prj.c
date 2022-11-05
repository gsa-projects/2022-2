#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define ROW 19
#define COL 19

#define forboard(board, var) for(int i=0; i<ROW; ++i) for(int j=0; j<COL; ++j, var = &board[i][j])

#define DOL_F '●'
#define DOL_E '○' 

typedef struct Omok {
    char ch;
    int stat;
} Omok;

void make_board(int row, int col) { 
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (i == 0) {
                if (j != 0 && j != col - 1) {
                    printf("┬");
                }
                else if (j == 0) {
                    printf("┌");
                }
                else if (j == col - 1) {
                    printf("┐");
                }
            }
            else if (i == row - 1) {
                if (j != 0 && j != col - 1) {
                    printf("┴");
                }
                else if (j == 0) {
                    printf("└");
                }
                else if (j == col - 1) {
                    printf("┘");
                }
            }
            else {
                if (j != 0 && j != col - 1) {
                    printf("┼");
                }
                else if (j == 0) {
                    printf("├");
                }
                else if (j == col - 1) {
                    printf("┤");
                }
            }
        }
        printf("\n");
    }
}

void 

int main() {
    Omok board[ROW][COL];
    make_board(ROW, COL);

}