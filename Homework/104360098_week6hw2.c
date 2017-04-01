#include <stdio.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
int main(int argc, char **argv) {
    unsigned long long int i, n, ppre = 0, pre = 1, cur = 1, temp;
    scanf("%llu", &n);
    for (i = 2 ; i <= n; i++) {
        temp = ppre + pre + cur;
        ppre = pre;
        pre = cur;
        cur = temp;
    }
    printf("%llu\n", cur);
    return 0;
}
