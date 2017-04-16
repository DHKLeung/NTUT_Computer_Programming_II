#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void inputData(int dataset[][50], int *n) {
    char temp[31];
    int i, j, weight;
    scanf("%s", temp);
    *n = (strlen(temp) + 1) / 2;
    for (i = 0, weight = *n; i < strlen(temp); i += 2, weight--) {  //first input of student's choice
        dataset[0][temp[i] - 65] = weight * 10;
    }
    for (j = 1; j < *n; j++) {
        scanf("%s", temp);
        for (i = 0, weight = *n; i < strlen(temp); i += 2, weight--) {  //remaining input of student's choice
            dataset[j][temp[i] - 65] = weight * 10;
        }
    }
    for (j = 0; j < *n; j++) {     //input teacher's choice
        scanf("%s", temp);
        for (i = 0, weight = *n; i < strlen(temp); i += 2, weight--) {
            dataset[temp[i] - (90 - (*n - 1))][j] += weight;
        }
    }
}
void computeResult(int dataset[][50], int n, bool occu[]) {
    int target, i, j, k, w;
    target = n * 10 + n;
    for (i = target; i >= 11; i--) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                if (dataset[j][k] == i && occu[k] == false) {
                    for (w = 0; w < n; w++) {
                        dataset[j][w] = -1;
                    }
                    dataset[j][k] = 100;
                    occu[k] = true;
                }
            }
        }
    }
}
void printResult(int dataset[][50], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dataset[i][j] == 100) {
                printf("%c->%c\n", i + 90 - (n - 1), j + 65);
            }
        }
    }
}
void process() {
    int dataset[50][50] = { 0 }, n;
    bool occu[50] = { false };
    inputData(dataset, &n);
    computeResult(dataset, n, occu);
    printResult(dataset, n);
}
int main(int argc, char **argv) {
    process();
    return 0;
}
