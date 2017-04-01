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
    char data[9], result[12];
    int flag, i, m, j, accu, max;
    while (scanf("%s", data) != EOF) {
        m = 0;
        for (i = 0; i < 8; i++) {
            if (data[i] == '1') {
                m += (int)round(pow(2, 7 - i));
            }
        }
        accu = 0;
        for (max = m; max >= 0; max--) {
            accu += C(max);
        }
        strcpy(result, "00000000000");
        j = 0;
        while (accu != 0) {
            if (accu % 2 == 1) {
                result[j] = '1';
            }
            j++;
            accu /= 2;
        }
        printf("%s\n", strrev(result));
        if (scanf("%d", &flag) && flag == -1) {
            break;
        }
    }
    return 0;
}
