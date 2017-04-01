#include <stdio.h>
#include <string.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void initializearray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        array[i] = 0;
    }
}
void initializearray2D(int (*array)[21]) {
    int i, j;
    for (i = 0; i < 21; i++) {
        for (j = 0; j < 21; j++) {
            array[i][j] = 0;
        }
    }
}
void process_desynthesis(int goods[], int *goodscounter, char inputline[]) {
    int i;
    for (i = 0; i <= strlen(inputline); i++) {
        if (inputline[i] != ',' && inputline[i] != '\0') {
            goods[*goodscounter] *= 10;
            goods[*goodscounter] += inputline[i] - 48;
        }else {
            (*goodscounter)++;
        }
    }
}
void process_portmap(int (*map)[21], int goods[], int goodscounter) {
    int i, j;
    for (i = 0; i < goodscounter - 1; i++) {
        for (j = i + 1; j < goodscounter; j++) {
            map[goods[i]][goods[j]] += 1;
            map[goods[j]][goods[i]] += 1;
        }
    }
}
void process(int (*map)[21], char inputline[]) {
    int i, goods[20], goodscounter = 0;
    initializearray(goods, 20);
    process_desynthesis(goods, &goodscounter, inputline);
    process_portmap(map, goods, goodscounter);
}
void output(int (*map)[21]) {
    int largestx = 0, largesty = 0, largestvalue = 0, i, j;
    for (i = 1; i < 21; i++) {
        for (j = 1; j < 21; j++) {
            if (map[i][j] > largestvalue) {
                largestx = i;
                largesty = j;
                largestvalue = map[i][j];
            }
        }
    }
    printf("%d,%d,%d\n", largestx, largesty, largestvalue);
}
int main(int argc, char **argv) {
    int dataamount, map[21][21];
    char inputline[101];
    initializearray2D(map);
    scanf("%d", &dataamount);
    getchar();
    while (dataamount > 0) {
        fgets(inputline, sizeof(inputline), stdin);
        inputline[strlen(inputline) - 1] = '\0';
        process(map, inputline);
        dataamount--;
    }
    output(map);
    return 0;
}
