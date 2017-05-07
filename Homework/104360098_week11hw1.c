#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
typedef struct user user_t;
typedef struct candidate candidate_t;
struct user {
    char ac[31];
    char pw[31];
    char email[31];
    bool isVoted;
};
struct candidate {
    char name[31];
    int vote;
    int serial;
};
bool isValid_AddUser(user_t temp, user_t user[], int userAmount) {     //validate the user
    int i;
    if (strlen(temp.ac) != 8) {     //length not 8
        printf("Add user error\n");
        printf("username error\n");
        return false;
    }else {
        for (i = 0; i < strlen(temp.ac); i++) {     //check 0-9 a-z A-Z
            if (!((temp.ac[i] >= '0' && temp.ac[i] <= '9')
            || (temp.ac[i] >= 'a' && temp.ac[i] <= 'z')
            || (temp.ac[i] >= 'A' && temp.ac[i] <= 'Z'))) {
                printf("Add user error\n");
                printf("username error\n");
                return false;
            }
        }
        for (i = 0; i < userAmount; i++) {     //check repeat
            if (strcmp(temp.ac, user[i].ac) == 0) {
                printf("Add user error\n");
                printf("username error\n");
                return false;
            }
        }
    }
    if (!((strlen(temp.pw) >= 1 && strlen(temp.pw) <= 8))) {    //length not between 1 and 8
        printf("Add user error\n");
        printf("password error\n");
        return false;
    }else if (strcmp(temp.pw, temp.ac) == 0) {      //cheeck whether pw is the same as ac
        printf("Add user error\n");
        printf("password error\n");
        return false;
    }else {
        for (i = 0; i < strlen(temp.pw); i++) {
            if (!((temp.pw[i] >= '0' && temp.pw[i] <= '9')      //check 0-9 a-z A-Z # % _ - @
            || (temp.pw[i] >= 'a' && temp.pw[i] <= 'z')
            || (temp.pw[i] >= 'A' && temp.pw[i] <= 'Z')
            || temp.pw[i] == '_' || temp.pw[i] == '-' || temp.pw[i] == '@' || temp.pw[i] == '#' || temp.pw[i] == '%')) {
                printf("Add user error\n");
                printf("password error\n");
                return false;
            }
        }
    }
    printf("Add user successful\n");
    return true;
}
void addUser(user_t user[], char *inputstr, int *userAmount) {      //add user
    user_t temp;
    int i, index;
    for (i = 2, index = 0; inputstr[i] != ','; i++, index++) {
        temp.ac[index] = inputstr[i];
    }
    temp.ac[index] = '\0';
    for (i += 1, index = 0; inputstr[i] != ','; i++, index++) {
        temp.pw[index] = inputstr[i];
    }
    temp.pw[index] = '\0';
    for (i += 1, index = 0; i < strlen(inputstr); i++, index++) {
        temp.email[index] = inputstr[i];
    }
    temp.email[index] = '\0';
    if (isValid_AddUser(temp, user, *userAmount)) {     //check validation
        strcpy(user[*userAmount].ac, temp.ac);
        strcpy(user[*userAmount].pw, temp.pw);
        strcpy(user[*userAmount].email, temp.email);
        user[*userAmount].isVoted = false;
        *userAmount += 1;
    }
}
bool isValid_AddCandidate(char ac[], char pw[], user_t user[], int userAmount, candidate_t candidate[], int candidateAmount, int serial, char name[]) {     //validate the login and candidate data
    int i;
    bool valid = false;
    for (i = 0; i < userAmount; i++) {
        if (strcmp(user[i].ac, ac) == 0 && strcmp(user[i].pw, pw) == 0 && i == 0) {
            valid = true;
            break;
        }
    }
    if (!valid) {
        printf("Login error\n");
        return false;
    }
    for (i = 0; i < candidateAmount; i++) {
        if (candidate[i].serial == serial || strcmp(candidate[i].name, name) == 0) {
            printf("Candidate data error\n");
            return false;
        }
    }
    printf("Add candidate successful\n");
    return true;
}
void addCandidate(candidate_t candidate[], char *inputstr, int *candidateAmount, user_t user[], int userAmount) {   //add candidate
    char ac[31], pw[31], name[31], ttemp[11] = { "" };
    int i, index, serial;
    for (i = 2, index = 0; inputstr[i] != ','; i++, index++) {
        ac[index] = inputstr[i];
    }
    ac[index] = '\0';
    for (i += 1, index = 0; inputstr[i] != ','; i++, index++) {
        pw[index] = inputstr[i];
    }
    pw[index] = '\0';
    for (i += 1, index = 0; inputstr[i] != ','; i++, index++) {
        ttemp[index] = inputstr[i];
    }
    ttemp[index] = '\0';
    serial = atoi(ttemp);
    for (i += 1, index = 0; i < strlen(inputstr); i++, index++) {
        name[index] = inputstr[i];
    }
    name[index] = '\0';
    if (isValid_AddCandidate(ac, pw, user, userAmount, candidate, *candidateAmount, serial, name)) {
        candidate[*candidateAmount].serial = serial;
        strcpy(candidate[*candidateAmount].name, name);
        candidate[*candidateAmount].vote = 0;
        *candidateAmount += 1;
    }
}
bool isValid_vote(char ac[], char pw[], user_t user[], int userAmount, candidate_t candidate[], int candidateAmount, int serial) {
    int i, userindex, canindex;
    bool valid = false;
    for (i = 0; i < userAmount; i++) {
        if (strcmp(user[i].ac, ac) == 0 && strcmp(user[i].pw, pw) == 0) {
            valid = true;
            userindex = i;
            break;
        }
    }
    if (!valid) {
        printf("Login error\n");
        return false;
    }
    valid = false;
    for (i = 0; i < candidateAmount; i++) {
        if (serial == candidate[i].serial) {
            valid = true;
            canindex = i;
            break;
        }
    }
    if (!valid) {
        printf("Candidate error\n");
        return false;
    }
    if (user[userindex].isVoted || userindex == 0) {
        printf("Voting error\n");
        return false;
    }
    user[userindex].isVoted = true;
    candidate[canindex].vote += 1;
    printf("Voting successful\n");
    return true;
}
void voteprocess(user_t user[], char *inputstr, candidate_t candidate[], int userAmount, int candidateAmount) {
    char ac[31], pw[31], ttemp[11];
    int i, index, serial;
    for (i = 2, index = 0; inputstr[i] != ','; i++, index++) {
        ac[index] = inputstr[i];
    }
    ac[index] = '\0';
    for (i += 1, index = 0; inputstr[i] != ','; i++, index++) {
        pw[index] = inputstr[i];
    }
    pw[index] = '\0';
    for (i += 1, index = 0; i < strlen(inputstr); i++, index++) {
        ttemp[index] = inputstr[i];
    }
    ttemp[index] = '\0';
    serial = atoi(ttemp);
    isValid_vote(ac, pw, user, userAmount, candidate, candidateAmount, serial);
}
void showresult(user_t user[], char *inputstr, candidate_t candidate[], int userAmount, int candidateAmount) {
    int i, index;
    bool valid = false;
    char ac[31], pw[31];
    for (i = 2, index = 0; inputstr[i] != ','; i++, index++) {
        ac[index] = inputstr[i];
    }
    ac[index] = '\0';
    for (i += 1, index = 0; i < strlen(inputstr); i++, index++) {
        pw[index] = inputstr[i];
    }
    pw[index] = '\0';
    for (i = 0; i < userAmount; i++) {
        if (strcmp(user[i].ac, ac) == 0 && strcmp(user[i].pw, pw) == 0) {
            valid = true;
            break;
        }
    }
    if (!valid) {
        printf("Login error\n");
        return;
    }else {
        int j;
        for (j = 0; j < candidateAmount; j++) {
            printf("(%d,%s,%d)", candidate[j].serial, candidate[j].name, candidate[j].vote);
            if (!(j == candidateAmount - 1)) {
                printf(",");
            }
        }
        printf("\n");
    }
}
void process() {
    user_t user[20];
    candidate_t candidate[20];
    int userAmount = 0, candidateAmount = 0;
    char inputstr[51];
    while (true) {
        fgets(inputstr, sizeof(inputstr), stdin);
        inputstr[strlen(inputstr) - 1] = '\0';
        if (strcmp(inputstr, "E") == 0) {
            printf("Exit\n");
            break;
        }else {
            switch (inputstr[0]) {
                case 'A':
                    addUser(user, inputstr, &userAmount);
                    break;
                case 'M':
                    addCandidate(candidate, inputstr, &candidateAmount, user, userAmount);
                    break;
                case 'V':
                    voteprocess(user, inputstr, candidate, userAmount, candidateAmount);
                    break;
                case 'Q':
                    showresult(user, inputstr, candidate, userAmount, candidateAmount);
                    break;
            }
        }
    }
}
int main(int argc, char **argv) {
    process();
    return 0;
}
