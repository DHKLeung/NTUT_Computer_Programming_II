#include <stdio.h>
#include <stdbool.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void inputboard(int board[][3]) {
    int i, j, row, col, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d %d", &row, &col);
            scanf("%d", &board[row][col]);
        }
    }
}
void printname(int num) {
    if (num >= 212) {
        printf("Soldier");
    }else if (num >= 210) {
        printf("Cannon");
    }else if (num >= 208) {
        printf("Knight");
    }else if (num >= 206) {
        printf("Chariot");
    }else if (num >= 204) {
        printf("Bishop");
    }else if (num >= 202) {
        printf("Assistant");
    }else if (num == 201) {
        printf("King");
    }else if (num >= 112) {
        printf("Pawn");
    }else if (num >= 110) {
        printf("Bom");
    }else if (num >= 108) {
        printf("Horse");
    }else if (num >= 106) {
        printf("Rook");
    }else if (num >= 104) {
        printf("Elephant");
    }else if (num >= 102) {
        printf("Guard");
    }else if (num == 101) {
        printf("General");
    }
}
void printresult(int board[][3], int i, int j, int a, int b) {
    printname(board[i][j]);
    printf("(%d,%d)->", i, j);
    printname(board[a][b]);
    printf("(%d,%d)\n", a, b);
}
bool judge(int A, int B) {
    if (A / 100 == B / 100) {
        return false;
    }else if (A == -1 || B == -1) {
        return false;
    }else {
        if (A / 100 == 1) {
            if (A == 111 || A == 110) { //A is Bom
                    return true;
            }else {
                if (B % 2 == 1 && B != 201 && B < 212) {
                    B = B - 101;
                }else {
                    B = B - 100;
                }
                if (A >= 112 && B == 101) {
                    return true;
                }else {
                    if (A >= 112 && B >= 112) {
                        return true;
                    }else if (A == 101 && B >= 112) {
                        return false;
                    }else if (A <= B) {
                        return true;
                    }
                }
            }
        }else {
            if (A == 211 || A == 210) { //A is Cannon
                    return true;
            }else {
                if (B % 2 == 1 && B != 101 && B < 112) {
                    B = B + 100 - 1;
                }else {
                    B = B + 100;
                }
                if (A >= 212 && B == 201) {
                    return true;
                }else {
                    if (A >= 212 && B >= 212) {
                        return true;
                    }else if (A == 201 && B >= 212) {
                        return false;
                    }else if (A <= B) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
void compute(int board[][3], int i, int j) {
    if (board[i][j] != 210 && board[i][j] != 211 && board[i][j] != 110 && board[i][j] != 111) {
        if (i - 1 >= 0) {   //up
            if (judge(board[i][j], board[i - 1][j])) {
                printresult(board, i, j, i - 1, j);
            }
        }
        if (j - 1 >= 0) {   //left
            if (judge(board[i][j], board[i][j - 1])) {
                printresult(board, i, j, i, j - 1);
            }
        }
        if (j + 1 <= 2) {   //right
            if (judge(board[i][j], board[i][j + 1])) {
                printresult(board, i, j, i, j + 1);
            }
        }
        if (i + 1 <= 2) {   //down
            if (judge(board[i][j], board[i + 1][j])) {
                printresult(board, i, j, i + 1, j);
            }
        }
    }else {
        if (i - 2 >= 0 && board[i - 1][j] != -1) {   //up
            if (judge(board[i][j], board[i - 2][j])) {
                printresult(board, i, j, i - 2, j);
            }
        }
        if (j - 2 >= 0 && board[i][j - 1] != -1) {   //left
            if (judge(board[i][j], board[i][j - 2])) {
                printresult(board, i, j, i, j - 2);
            }
        }
        if (j + 2 <= 2 && board[i][j + 1] != -1) {   //right
            if (judge(board[i][j], board[i][j + 2])) {
                printresult(board, i, j, i, j + 2);
            }
        }
        if (i + 2 <= 2 && board[i + 1][j] != -1) {   //down
            if (judge(board[i][j], board[i + 2][j])) {
                printresult(board, i, j, i + 2, j);
            }
        }
    }
}
void process(int board[][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            compute(board, i, j);
        }
    }
}
int main(int argc, char **argv) {
    int board[3][3] = { 0 };
    inputboard(board);
    process(board);
    return 0;
}
