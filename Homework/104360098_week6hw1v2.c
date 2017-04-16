#include <stdio.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void printmap(int n, int map[][20]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (map[i][j] == 2) {
                printf("# ");
            }else {
                printf("%d ", map[i][j]);
            }
        }
        printf("\n");
    }
}
void inputData(int *n, int map[][20]) {
    int i, j;
    scanf("%d", n);
    for (i = 0; i < *n; i++) {
        for (j = 0; j < *n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
}
void maze(int n, int map[][20], int x, int y) {
    map[x][y] = 2;
    if (x == n - 2 && y == n - 2) {
        printmap(n, map);
    }else {
        if (map[x - 1][y] == 0) {
            maze(n, map, x - 1, y);
        }
        if (map[x][y + 1] == 0) {
            maze(n, map, x, y + 1);
        }
        if (map[x + 1][y] == 0) {
            maze(n, map, x + 1, y);
        }
        if (map[x][y - 1] == 0) {
            maze(n, map, x, y - 1);
        }
    }
    map[x][y] = 0;
}
void process() {
    int n, map[20][20];
    inputData(&n, map);
    maze(n, map, 1, 1);
}
int main(int argc, char **argv) {
    process();
    return 0;
}
