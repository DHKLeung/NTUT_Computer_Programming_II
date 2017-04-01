#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void iniIntArray(int array[], int max) {
    int i;
    for (i = 0; i < max; i++) {
        array[i] = 0;
    }
}
int inputword_getAmount(char wordlist[][101], char passage[]) {
    int i = 0;
    while (scanf("%s", wordlist[i]) && strcmp(wordlist[i], "-1")) {
        i++;
    }
    getchar();
    fgets(passage, 1001, stdin);
    passage[strlen(passage) - 1] = '\0';
    return i;
}
int splitpassage_getLength(char passage[]) {
    int i, wordnum = 0, length;
    length = strlen(passage);
    for (i = 0; i < length; i++) {
        if (passage[i] == ' ') {
            wordnum++;
            passage[i] = '\0';
        }
    }
    wordnum++;
    return wordnum;
}
void process(char passage[], char wordlist[][101], int wordnum, int amount, int wordfreq[], int *notexistNUM, char notexist[][101]) {
    int i, j;
    char *ptr = passage;
    bool exist = false;
    for (i = 0; i < wordnum; i++) {
        for (j = 0; j < amount; j++) {
            if (strcmp(ptr, wordlist[j]) == 0) {
                exist = true;
                wordfreq[j] += 1;
                break;
            }
        }
        if (!exist) {
            strcpy(notexist[*notexistNUM], ptr);
            (*notexistNUM)++;
        }else {
            exist = false;
        }
        ptr += strlen(ptr) + 1;
    }
}
void printresult(char wordlist[][101], int wordfreq[30], int amount, char notexist[][101], int notexistNUM) {
    int i, j, k, qq;
    char temp0[101], temp1[101], temp2[101];
    for (i = 0; i < amount - 1; i++) {
        for (j = 0; j < amount - 1 - i; j++) {
            strcpy(temp1, wordlist[j]);
            strcpy(temp2, wordlist[j + 1]);
            for (k = 0; k < strlen(temp1); k++) {
                temp1[k] = tolower(temp1[k]);
            }
            for (k = 0; k < strlen(temp2); k++) {
                temp2[k] = tolower(temp2[k]);
            }
            if (strcmp(temp1, temp2) > 0) {
                strcpy(temp0, wordlist[j]);
                strcpy(wordlist[j], wordlist[j + 1]);
                strcpy(wordlist[j + 1], temp0);
                qq = wordfreq[j];
                wordfreq[j] = wordfreq[j + 1];
                wordfreq[j + 1] = qq;
            }
        }
    }
    for (i = 0; i < notexistNUM; i++) {
        printf("%s ", notexist[i]);
    }
    printf("\n");
    printf("%d\n", notexistNUM);
    for (i = 0; i < amount; i++) {
        if (wordfreq[i] != 0) {
            printf("%s %d\n", wordlist[i], wordfreq[i]);
        }
    }
}
int main(int argc, char **argv) {
    char wordlist[30][101], passage[1001], notexist[30][101];
    int amount, wordfreq[30], wordnum, notexistNUM = 0, i, j, k;
    iniIntArray(wordfreq, 30);
    amount = inputword_getAmount(wordlist, passage);
    wordnum = splitpassage_getLength(passage);
    process(passage, wordlist, wordnum, amount, wordfreq, &notexistNUM, notexist);
    printresult(wordlist, wordfreq, amount, notexist, notexistNUM);
    return 0;
}
