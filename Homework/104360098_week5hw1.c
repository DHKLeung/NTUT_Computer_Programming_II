#include <stdio.h>
#include <math.h>
#include <string.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
int C(int m) {
    if (m == 0 || m == 1) {
        return 0;
    }else if (m % 2 == 0) {
        return 1 + C(m / 2);
    }else {
        return 1 + C((m + 1) / 2);
    }
}
int main(int argc, char **argv) {
    char data[9], result[5];
    int flag, i, m, returnvalue, j, remain, binary, a;
    while (scanf("%s", data) != EOF) {
        m = 0;
        for (i = 0; i < 8; i++) {
            if (data[i] == '1') {
                m += (int)round(pow(2, 7 - i));
            }
        }
        returnvalue = C(m);
        j = 1;
        binary = 0;
        while (returnvalue != 0) {
            remain = returnvalue % 2;
            returnvalue /= 2;
            binary += remain * j;
            j *= 10;
        }
        sprintf(result, "%d", binary);
        a = 4 - strlen(result);
        strrev(result);
        for (j = 0; j < a; j++) {
            strcat(result, "0");
        }
        strrev(result);
        printf("%s\n", result);
        if (scanf("%d", &flag) && flag == -1) {
            break;
        }
    }
    return 0;
}
