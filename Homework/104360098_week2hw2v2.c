#include <stdio.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void initial(int relations[][20]) {
    int i, j;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            if (j == 0) {
                relations[i][j] = i;
            }else {
                relations[i][j] = -1;
            }
        }
    }
}
void fillmap(int relations[][20], int a, int b, int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        if (relations[b][i] == -1) {
            relations[b][i] = a;
            temp = i + 1;
            break;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (relations[i][j] == b) {
                relations[i][j + 1] = a;
            }
        }
    }
    i = 1;
    while (relations[a][i] != -1) {
        relations[b][temp] = relations[a][i];
        i++;
        temp++;
    }
}
void input_fill(int relations[][20], int n) {
    int i, a, b;
    for (i = 1; i <= n - 1; i++) {
        scanf("%d %d", &a, &b);
        fillmap(relations, a, b, n);
    }
}
int getDistance(int relations[][20], int n, int i, int j) {
    int iindex, jindex;
    for (iindex = 0; relations[i][iindex] != -1; iindex++) {
        for (jindex = 0; relations[j][jindex] != -1; jindex++) {
            if (relations[i][iindex] == relations[j][jindex]) {
                return iindex + jindex;
            }
        }
    }
}
void printresult(int relations[][20], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            printf("%d-%d-%d\n", i, j, getDistance(relations, n, i, j));
        }
    }
}
void process() {
    int relations[20][20], n;
    initial(relations);
    scanf("%d", &n);
    input_fill(relations, n);
    printresult(relations, n);
}
int main(int argc, char **argv) {
    process();
    return 0;
}
