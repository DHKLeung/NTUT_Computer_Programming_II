#include <stdio.h>
#include <stdbool.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
typedef enum _result result;
enum _result {  //result type
    draw = 0,
    p1wins = 1,
    p2wins = 2
};
void initialmap(int (*map)[3]) {   //initialize the map
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            map[i][j] = 0;
        }
    }
}
void input(int (*map)[3], int player) { //user input data to the map
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &map[i][j]);
        }
    }
}
void process_portmap(int (*map)[3], int ans[]) {    //port the map
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                if (map[i][j] == ans[k]) {
                    map[i][j] = 0;
                }
            }
        }
    }
}
bool process_checkmap(int (*map)[3]) {  //check map
    int i;
    for (i = 0; i < 3; i++) {   //check every rows
        if (map[i][0] == map[i][1] && map[i][0] == map[i][2] && map[i][0] == 0) {
            return true;
        }
    }
    for (i = 0; i < 3; i++) {   //check every columnws
        if (map[0][i] == map[1][i] && map[0][i] == map[2][i] && map[0][i] == 0) {
            return true;
        }
    }
    if (map[0][2] == map[1][1] && map[0][2] == map[2][0] && map[0][2] == 0) {   //check slash
        return true;
    }
    if (map[0][0] == map[1][1] && map[0][0] == map[2][2] && map[0][0] == 0) {   //check backslash
        return true;
    }
    return false;
}
result process(int (*p1map)[3], int (*p2map)[3], int ans[]) {   //process and return the result
    bool checkp1, checkp2;
    process_portmap(p1map, ans);    //port the map
    process_portmap(p2map, ans);
    checkp1 = process_checkmap(p1map);  //check who's map can perform the answer
    checkp2 = process_checkmap(p2map);
    if (checkp1 == true && checkp2 == false) {  //return result
        return p1wins;
    }else if (checkp1 == false && checkp2 == true) {
        return p2wins;
    }else {
        return draw;
    }
}
int main(int argc, char **argv) {
    int p1map[3][3], p2map[3][3], ans[3], leave;
    result finalresult;
    initialmap(p1map);  //initialize map
    initialmap(p2map);  //initialize map
    while (true) {   //check if user entered -1
        input(p1map, 1);    //input player1's map
        input(p2map, 2);    //input player2's map
        scanf("%d %d %d", ans, ans + 1, ans + 2);   //input answer
        finalresult = process(p1map, p2map, ans);   //process and return who wins
        switch (finalresult) {  //display result
            case draw :
                printf("Draw\n");
                break;
            case p1wins :
                printf("Player1 wins\n");
                break;
            case p2wins :
                printf("Player2 wins\n");
                break;
        }
        if (scanf("%d", &leave) && leave == -1) {   //check leave
            break;
        }
    }
    return 0;
}
