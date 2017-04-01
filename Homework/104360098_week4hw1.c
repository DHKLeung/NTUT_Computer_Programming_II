#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void toUpDeck(char a[]) {
    int i = 0;
    for (i = 0; i < strlen(a); i++) {
        a[i] = toupper(a[i]);
    }
}
void toLowDeck(char a[]) {
    int i = 0;
    for (i = 0; i < strlen(a); i++) {
        a[i] = tolower(a[i]);
    }
}
void input(char token[], char *RL, int *num, char word[][101], int *amount, int indexrec[], int *indexcounter) {
    char temp;
    int i = 0, j = 0;
    scanf("%s %d %c", token, num, RL);
    getchar();
    toLowDeck(token);
    i = 0;
    while (scanf("%c", &temp)) {
        if (temp == ' ') {
            word[i][j] = '\0';
            if (strcmp(word[i], token) == 0) {
                indexrec[*indexcounter] = i;
                *indexcounter += 1;
            }
            j = 0;
            i++;
        }else if (temp == '\n'){
            word[i][j] = '\0';
            if (strcmp(word[i], token) == 0) {
                indexrec[*indexcounter] = i;
                *indexcounter += 1;
            }
            break;
        }else {
            word[i][j] = tolower(temp);
            j++;
        }
    }
    *amount = i + 1;
}
bool isLarger(char word[][101], int indexrec[], int Aindex, int Bindex, char RL, int amount) {
    int a, b;
    a = indexrec[Aindex];
    b = indexrec[Bindex];
    if (RL == 'L') {
        a--;
        b--;
        while (a >= 0 && b >= 0) {
            if (strcmp(word[a], word[b]) > 0) {
                return true;
            }else if (strcmp(word[a], word[b]) < 0) {
                return false;
            }else {
                a--;
                b--;
            }
        }
    }else if (RL == 'R') {
        a++;
        b++;
        while (a < amount && b < amount) {
            if (strcmp(word[a], word[b]) > 0) {
                return true;
            }else if (strcmp(word[a], word[b]) < 0) {
                return false;
            }else {
                a++;
                b++;
            }
        }
    }
}
void sortindexrec(char RL, char word[][101], int indexrec[], int indexcounter, int amount) {
    int i, j, temp;
    for (i = 0; i < indexcounter - 1; i++) {
        for (j = 0; j < indexcounter - 1 - i; j++) {
            if (isLarger(word, indexrec, j, j + 1, RL, amount)) {
                temp = indexrec[j];
                indexrec[j] = indexrec[j + 1];
                indexrec[j + 1] = temp;
            }
        }
    }
}
void print(char word[][101], int num, int indexrec[], int indexcounter, int amount) {
    int i, j, k;
    for (i = 0; i < indexcounter; i++) {
        j = indexrec[i];
        for (k = (j - num >= 0) ? j - num : 0; k < j; k++) {
            printf("%s ", word[k]);
        }
        toUpDeck(word[j]);
        printf("%s ", word[k]);
        toLowDeck(word[j]);
        for (k = j + 1; k <= j + num && k < amount; k++) {
            printf("%s ", word[k]);
        }
        printf("\n");
    }
}
int main(int argc, char **argv) {
    char token[101], RL, word[101][101];
    int num, amount = 0, indexrec[101] = { 0 }, indexcounter = 0;
    input(token, &RL, &num, word, &amount, indexrec, &indexcounter);
    sortindexrec(RL, word, indexrec, indexcounter, amount);
    print(word, num, indexrec, indexcounter, amount);
    return 0;
}
