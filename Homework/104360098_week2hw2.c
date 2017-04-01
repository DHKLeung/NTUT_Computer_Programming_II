#include <stdio.h>
#include <stdbool.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void initialmap(int (*map)[21]) {   //initialize the relations map
    int i, j;
    for (i = 0; i < 21; i++) {
        for (j = 0; j < 21; j++) {
            if (j == 0) {
                map[i][j] = i;
            }else {
                map[i][j] = -1;
            }
        }
    }
}
void process(int (*relations)[21], int son, int father, int amount) {   //plot the relations map
    int i, j, k;
    for (i = 0; i < amount; i++) {  //copy all the related relations from father's all ancestor to the son's ancestor
        if (relations[son][i] == -1) {
            for (j = 0; j < amount; j++) {
                if (relations[father][j] != -1) {
                    relations[son][i] = relations[father][j];
                    i++;
                }else {
                    break;
                }
            }
            break;
        }
    }
    for (i = 1; i < amount; i++) {  //copy all related relations from son's all ancestor to all possible places
        for (j = 1; j < amount; j++) {
            if (relations[i][j] == son) {
                j++;
                for (k = 1; k < amount; k++) {
                    if (relations[son][k] != -1) {
                        relations[i][j] = relations[son][k];
                        j++;
                    }else {
                        break;
                    }
                }
                break;
            }
        }
    }
}
bool isFinish(int (*relations)[21], int amount) {   //check whether the relations is finished
    int i, j, checkmap[21], stdroot;
    for (i = 0; i < amount; i++) {  //find all's root
        for (j = 0; j < amount; j++) {
            if (relations[i][j] == -1) {
                checkmap[i] = relations[i][j - 1];
                break;
            }
        }
    }
    stdroot = checkmap[0];  //check whether all of their roots are the same, if yes then finished
    for (i = 1; i < amount; i++) {
        if (stdroot != checkmap[i]) {
            return false;
        }
    }
    return true;
}
int result_getEdgeLength(int (*relations)[21], int host, int client, int amount) {  //find relations length
    int hostupper, clientupper, hosttarget, clienttarget, i, j;
    for (i = 0; i < amount; i++) {  //find host's upper
        if (relations[host][i] == -1) {
            hostupper = i - 1;
            break;
        }
    }
    for (i = 0; i < amount; i++) {  //find client's upper
        if (relations[client][i] == -1) {
            clientupper = i - 1;
            break;
        }
    }
    for (i = 0; i <= hostupper; i++) {  //calculate the length and return
        for (j = 0; j <= clientupper; j++) {
            if (relations[host][i] == relations[client][j]) {
                return i + j;
            }
        }
    }
}
void result(int (*relations)[21], int maxmember) {  //calculate the length and print
    int host, client;
    for (host = 0; host <= maxmember - 1; host++) {
        for (client = host + 1; client <= maxmember; client++) {
            printf("%d-%d-%d\n", host, client, result_getEdgeLength(relations, host, client, maxmember + 1));
        }
    }
}
int main(int argc, char **argv) {
    int amount, i, son, father, relations[21][21];
    initialmap(relations);  //initialize the relations map
    scanf("%d", &amount);   //input the amount of relations that will be inputted
    while (true) {  //input relations and plot the relations map
        scanf("%d %d", &father, &son);  //input relations
        process(relations, son, father, amount);    //plot relations map
        if (isFinish(relations, amount)) {  //check whether it is finished
            break;
        }
    }
    result(relations, amount - 1);  //find the result and print
    return 0;
}
