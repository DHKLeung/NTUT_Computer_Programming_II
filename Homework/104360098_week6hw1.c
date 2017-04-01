#include <stdio.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void input(int map[][40], int *n) {
    int i, j;
    scanf("%d", n);
    for (i = 0; i < *n; i++) {
        for (j = 0; j < *n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
}
void printmap(int map[][40], int n) {
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
int walkMaze(int map[][40], int x, int y, int n) {
    map[x][y] = 2;
    if (x == n - 2 && y == n - 2) {
        return -1;
    }else {
        if (map[x - 1][y] != 1 && map[x - 1][y] != 2) {
            if (walkMaze(map, x - 1, y, n) == -1) {
                return -1;
            }
        }
        if (map[x][y + 1] != 1 && map[x][y + 1] != 2) {
            if (walkMaze(map, x, y + 1, n) == -1) {
                return -1;
            }
        }
        if (map[x + 1][y] != 1 && map[x + 1][y] != 2) {
            if (walkMaze(map, x + 1, y, n) == -1) {
                return -1;
            }
        }
        if (map[x][y - 1] != 1 && map[x][y - 1] != 2) {
            if (walkMaze(map, x, y - 1, n) == -1) {
                return -1;
            }
        }
    }
    map[x][y] = 0;
}
int main(int argc, char **argv) {
    int map[40][40], n;
    input(map, &n);
    if (walkMaze(map, 1, 1, n) == -1) {
        printmap(map, n);
    }
    return 0;
}
