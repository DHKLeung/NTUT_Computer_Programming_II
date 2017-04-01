#include <stdio.h>
#include <math.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void G(int n, int k) {
    if (n == 1) {
        printf("%d", k);
    }else if (k < (int)round(pow(2, n - 1))) {
        printf("0");
        G(n - 1, k);
    }else if (k >= (int)round(pow(2, n - 1))) {
        printf("1");
        G(n - 1, (int)round(pow(2, n)) - 1 - k);
    }
}
int main(int argc, char **argv) {
    int flag, n, k;
    while (scanf("%d %d", &n, &k)) {
        G(n, k);
        printf("\n");
        if (scanf("%d", &flag) && flag == -1) {
            break;
        }
    }
    return 0;
}
