#include <stdio.h>
#include <string.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void input(char firstPassage[], char secondPassage[]) {
    fgets(firstPassage, 301, stdin);
    firstPassage[strlen(firstPassage) - 1] = '\0';
    fgets(secondPassage, 301, stdin);
    secondPassage[strlen(secondPassage) - 1] = '\0';
}
void process_1(char firstPassage[]) {
    int i, accu = 0, times = 1;
    for (i = 0; i < strlen(firstPassage); i++) {
        if (firstPassage[i] >= '0' && firstPassage[i] <= '9') {
            accu += (firstPassage[i] - 48) * times;
            times *= 10;
        }else {
            times = 1;
        }
    }
    printf("%d", accu);
}
void process_2(char secondPassage[]) {
    int i, j, accu[52][3] = { 0 }, temp;
    for (i = 0; i < strlen(secondPassage); i++) {
        if (secondPassage[i] != ' ') {
            if (secondPassage[i] >= 'A' && secondPassage[i] <= 'Z') {
                if (accu[secondPassage[i] - 65][1] == 0) {
                    accu[secondPassage[i] - 65][1] = i;
                }
                accu[secondPassage[i] - 65][2] += 1;
            }else if (secondPassage[i] >= 'a' && secondPassage[i] <= 'z') {
                if (accu[secondPassage[i] - 71][1] == 0) {
                    accu[secondPassage[i] - 71][1] = i;
                }
                accu[secondPassage[i] - 71][2] += 1;
            }
        }
    }
    for (i = 0; i < 52; i++) {
        if (accu[i][2] > 10) {
            accu[i][2] = 0;
        }
    }
    for (i = 0; i < 52; i++) {
        if (i < 26) {
            accu[i][0] = i + 65;
        }else {
            accu[i][0] = i + 71;
        }
    }
    for (i = 0; i < 52 - 1; i++) {
        for (j = 0; j < 52 - 1 - i; j++) {
            if (accu[j][2] < accu[j + 1][2]) {
                temp = accu[j][2];
                accu[j][2] = accu[j + 1][2];
                accu[j + 1][2] = temp;
                temp = accu[j][1];
                accu[j][1] = accu[j + 1][1];
                accu[j + 1][1] = temp;
                temp = accu[j][0];
                accu[j][0] = accu[j + 1][0];
                accu[j + 1][0] = temp;
            }else if (accu[j][2] == accu[j + 1][2]) {
                if (accu[j][1] > accu[j + 1][1]) {
                    temp = accu[j][2];
                    accu[j][2] = accu[j + 1][2];
                    accu[j + 1][2] = temp;
                    temp = accu[j][1];
                    accu[j][1] = accu[j + 1][1];
                    accu[j + 1][1] = temp;
                    temp = accu[j][0];
                    accu[j][0] = accu[j + 1][0];
                    accu[j + 1][0] = temp;
                }
            }
        }
    }
    for (i = 0; i < 4 - 1; i++) {
        for (j = 0; j < 4 - 1 - i; j++) {
            if (accu[j][1] > accu[j + 1][1]) {
                temp = accu[j][2];
                accu[j][2] = accu[j + 1][2];
                accu[j + 1][2] = temp;
                temp = accu[j][1];
                accu[j][1] = accu[j + 1][1];
                accu[j + 1][1] = temp;
                temp = accu[j][0];
                accu[j][0] = accu[j + 1][0];
                accu[j + 1][0] = temp;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        printf("%d", accu[i][2]);
    }
    printf("\n");
}
int main(int argc, char **argv) {
    char firstPassage[301], secondPassage[301];
    input(firstPassage, secondPassage);
    process_1(firstPassage);
    process_2(secondPassage);
    return 0;
}
