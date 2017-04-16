#include <stdio.h>
#include <stdbool.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void split(int array[], int value) {
    array[0] = value / 1000;
    array[1] = (value - array[0] * 1000) / 100;
    array[2] = (value - array[0] * 1000 - array[1] * 100) / 10;
    array[3] = value - array[0] * 1000 - array[1] * 100 - array[2] * 10;
}
void initial(int board[][5]) {
    int i, index = 0, tempArr[4];
    for (i = 0; i <= 9876; i++) {
        split(tempArr, i);
        if (!(tempArr[0] == tempArr[1] || tempArr[0] == tempArr[2] || tempArr[0] == tempArr[3] || tempArr[1] == tempArr[2] || tempArr[1] == tempArr[3] || tempArr[2] == tempArr[3])) {
            board[index][0] = tempArr[0];
            board[index][1] = tempArr[1];
            board[index][2] = tempArr[2];
            board[index][3] = tempArr[3];
            board[index][4] = 0;
            index++;
        }
    }
}
bool isFinished(int board[][5]) {
    int unchecked = 0, i, mayIndex;
    for (i = 0; i < 5040; i++) {
        if (board[i][4] == 0) {
            unchecked++;
            mayIndex = i;
        }
        if (unchecked > 1) {
            return false;
        }
    }
    printf("%d%d%d%d\n", board[mayIndex][0], board[mayIndex][1], board[mayIndex][2], board[mayIndex][3]);
    return true;
}
bool isSim(int boardArray[], int inputArray[], int A, int B) {
    int i, j, tempA = 0, tempB = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (boardArray[i] == inputArray[j]) {
                if (i == j) {
                    tempA++;
                }else {
                    tempB++;
                }
            }
        }
    }
    if (tempA == A && tempB == B) {
        return true;
    }else {
        return false;
    }
}
void compute(int value, int A, int B, int board[][5]) {
    int input[4], i;
    split(input, value);
    for (i = 0; i < 5040; i++) {
        if (!isSim(input, board[i], A, B)) {
            board[i][4] = 1;
        }
    }
}
void process() {
    int board[5040][5], value, A, B;
    initial(board);
    while (!isFinished(board)) {
        scanf("%d,%dA%dB", &value, &A, &B);
        compute(value, A, B, board);
    }
}
int main(int argc, char **argv) {
    process();
    return 0;
}
