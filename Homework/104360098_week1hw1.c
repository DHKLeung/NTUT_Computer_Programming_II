#include <stdio.h>
#include <stdbool.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
typedef struct _inputdata inputdata;
struct _inputdata { //storing the input
    int value;
    int A;
    int B;
};
void splitvalue(int value, int digits[]) {  //split the 4-digit value into discrete digit in array
    digits[0] = value / 1000;
    digits[1] = (value - digits[0] * 1000) / 100;
    digits[2] = (value - digits[0] * 1000 - digits[1] * 100) / 10;
    digits[3] = value - digits[0] * 1000 - digits[1] * 100 - digits[2] * 10;
}
bool initialmap_isRepeat(int temp[]) {  //check whether it is a possible outcome
    if (temp[0] == temp[1] || temp[0] == temp[2] || temp[0] == temp[3] || temp[1] == temp[2] || temp[1] == temp[3] || temp[2] == temp[3]) {
        return true;
    }
    return false;
}
void initialmap(int (*map)[5]) {    //initialize the map (the possible outcomes)
    int i, j, temp[4], indexcounter = 0;
    for (i = 123; i <= 9876; i++) { //split and check from 0123 to 9876
        splitvalue(i, temp);    //split the integer into 4 digits
        if (!initialmap_isRepeat(temp)) {   //check whether it is a possible outcome
            for (j = 0; j < 4; j++) {   //insert the digits to map
                map[indexcounter][j] = temp[j];
            }
            map[indexcounter][4] = 1;   //initially set the data to be valid
            indexcounter++; //increment
        }
    }
}
void printmap(int (*map)[5]) {  //print map and the amount of possible outcomes
    int i;
    for (i = 0; i < 5040; i++) {
        if (map[i][4] == 1) {
            printf("%d%d%d%d\n", map[i][0], map[i][1], map[i][2], map[i][3]);
        }
    }
}
void process_generalCompare_core(int (*map)[5], int temp[], int stdA, int stdB, int index) {    //compare all possible outcome with the assumption of the fact that the newly imputted value is answer
    int A = 0, B = 0, i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (map[index][i] == temp[j]) { //if the value exists
                if (i == j) {   //if position is correct then A++
                    A++;
                }else { //position isn't correct then B++
                    B++;
                }
            }
        }
    }
    if (!(A == stdA && B == stdB)) {    //if it is not fulfilling the requirement, then set the flag to be 0
        map[index][4] = 0;
    }
}
void process_generalCompare(int (*map)[5], int temp[], int stdA, int stdB) {    //compare all possible outcome
    int i;
    for (i = 0; i < 5040; i++) {
        if (map[i][4] == 0) {   //if flag = 0 then continue the next comparison
            continue;
        }else {
            process_generalCompare_core(map, temp, stdA, stdB, i);  //compare with the assumption of the fact that the newly imputted value is answer
        }
    }
}
bool checkfinish(int (*map)[5]) {   //check whether the answer is able to be figure out
    int i, counter = 0;
    for (i = 0; i < 5040; i++) {
        if (map[i][4] == 1) {
            counter++;
            if (counter > 1) {
                return false;
            }
        }
    }
    return true;
}
void process(int (*map)[5], inputdata data) {    //process of the map data deletion
    int temp[4];
    splitvalue(data.value, temp);   //split the integer into 4 digits
    process_generalCompare(map, temp, data.A, data.B);
    return;
}
int main(int argc, char **argv) {
    inputdata data[10];
    int map[5040][5], datacounter = 0;
    bool isFinish = false;
    initialmap(map);    //initialize the map
    while (true) {
        scanf("%d,%dA%dB", &((&data[datacounter])->value), &((&data[datacounter])->A), &((&data[datacounter])->B));  //input
        datacounter++;  //counter increment
        process(map, data[datacounter - 1]);  //process the map by the data inputted
        if (checkfinish(map)) { //if the status is finished, print the value and program ended
            printmap(map);
            break;
        }
    }
    return 0;
}
