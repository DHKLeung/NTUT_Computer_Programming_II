#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
typedef struct school_s school_t;
typedef struct choice_s choice_t;
struct school_s {
    char name[51];
    bool BC;
    bool NC;
    bool CT;
    bool NS;
    bool NM;
    bool HL;
    bool NL;
};
struct choice_s {
    bool BC;
    bool NC;
    bool CT;
    bool NS;
    bool NM;
    bool HL;
    bool NL;
};
void initialize_school(school_t allschool[], int n) {  //initialize all the data
    int i;
    for (i = 0; i < n; i++) {
        strcpy(allschool[i].name, "");
        allschool[i].BC = false;
        allschool[i].NC = false;
        allschool[i].CT = false;
        allschool[i].NS = false;
        allschool[i].NM = false;
        allschool[i].HL = false;
        allschool[i].NL = false;
    }
}
void initialize_choice(choice_t choice[]) {  //initialize all the choice
    int i;
    for (i = 0; i < 10; i++) {
        choice[i].BC = false;
        choice[i].NC = false;
        choice[i].CT = false;
        choice[i].NS = false;
        choice[i].NM = false;
        choice[i].HL = false;
        choice[i].NL = false;
    }
}
int inputData_split(char str[]) {  //split the string
    int i, counter = 0, length;
    length = strlen(str);
    for (i = 0; i < length; i++) {
        if (str[i] == ' ') {
            str[i] = '\0';
            counter++;
        }
    }
    return counter + 1;
}
void inputData(school_t allschool[], int n) {   //input the data and classify them
    char temp[101], *ptr;
    int i, j, numElement;
    for (i = 0; i < n; i++) {
        numElement = 0;
        fgets(temp, 101, stdin);
        temp[strlen(temp) - 1] = '\0';
        numElement = inputData_split(temp);
        ptr = temp;
        strcpy(allschool[i].name, ptr);
        ptr += strlen(ptr) + 1;
        for (j = 1; j < numElement; j++) {
            if (strcmp(ptr, "BC") == 0) {
                allschool[i].BC = true;
            }else if (strcmp(ptr, "NC") == 0) {
                allschool[i].NC = true;
            }else if (strcmp(ptr, "CT") == 0) {
                allschool[i].CT = true;
            }else if (strcmp(ptr, "NS") == 0) {
                allschool[i].NS = true;
            }else if (strcmp(ptr, "NM") == 0) {
                allschool[i].NM = true;
            }else if (strcmp(ptr, "HL") == 0) {
                allschool[i].HL = true;
            }else if (strcmp(ptr, "NL") == 0) {
                allschool[i].NL = true;
            }
            ptr += strlen(ptr) + 1;
        }
    }
}
void trimString(char str[]) {   //trim the string
    int i, j = 0;
    char temp[101];
    for (i = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            temp[j] = str[i];
            j++;
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}
void splitchoice(choice_t choice[], char temp[], int *counter) {    //split the choice with logic "and" and "or"
    int i;
    for (i = 0; i < strlen(temp); i++) {
        if (temp[i] != '+') {
            if (strncmp(&temp[i], "BC", 2) == 0) {
                choice[*counter].BC = true;
            }else if (strncmp(&temp[i], "NC", 2) == 0) {
                choice[*counter].NC = true;
            }else if (strncmp(&temp[i], "CT", 2) == 0) {
                choice[*counter].CT = true;
            }else if (strncmp(&temp[i], "NS", 2) == 0) {
                choice[*counter].NS = true;
            }else if (strncmp(&temp[i], "NM", 2) == 0) {
                choice[*counter].NM = true;
            }else if (strncmp(&temp[i], "HL", 2) == 0) {
                choice[*counter].HL = true;
            }else if (strncmp(&temp[i], "NL", 2) == 0) {
                choice[*counter].NL = true;
            }
            i++;
        }else if (temp[i] == '+') {
            (*counter)++;
        }
    }
    (*counter)++;
}
void printresult(choice_t choice[], int counter, school_t allschool[], int n) {
    int i, j;
    bool valid;
    for (i = 0; i < n; i++) {
        for (j = 0; j < counter; j++) {
            valid = true;
            if (choice[j].BC == true && allschool[i].BC != true) {
                valid = false;
            }
            if (choice[j].NC == true && allschool[i].NC != true) {
                valid = false;
            }
            if (choice[j].CT == true && allschool[i].CT != true) {
                valid = false;
            }
            if (choice[j].NS == true && allschool[i].NS != true) {
                valid = false;
            }
            if (choice[j].NM == true && allschool[i].NM != true) {
                valid = false;
            }
            if (choice[j].HL == true && allschool[i].HL != true) {
                valid = false;
            }
            if (choice[j].NL == true && allschool[i].NL != true) {
                valid = false;
            }
            if (valid) {
                printf("%s ", allschool[i].name);
                break;
            }
        }
    }
    printf("\n");
}
void processWill(int m, school_t allschool[], int n) { //process the choice of student
    int i, j, counter;
    choice_t choice[10];
    char temp[101];
    for (i = 0; i < m; i++) {
        counter = 0;
        initialize_choice(choice);
        fgets(temp, 101, stdin);
        temp[strlen(temp) - 1] = '\0';
        trimString(temp);
        splitchoice(choice, temp, &counter);
        printresult(choice, counter, allschool, n);
    }
}
void process() {
    int n, m;
    school_t allschool[20];
    scanf("%d", &n);
    getchar();
    initialize_school(allschool, n);
    inputData(allschool, n);
    scanf("%d", &m);
    getchar();
    processWill(m, allschool, n);
}
int main(int argc, char **argv) {
    process();
    return 0;
}
