#include <stdio.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void process() {
    int accu = 0, i, n, a, b, c;
    char ch;
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++) {
        scanf("%c", &ch);
        if (ch == 'C') {
            scanf("%d", &a);
            getchar();
            printf("%d\n", 2 * a * 4);
            accu += 2 * a * 4;
        }else if (ch == 'R') {
            scanf("%d %d", &a, &b);
            getchar();
            printf("%d\n", (a + b) * 2);
            accu += (a + b) * 2;
        }else if (ch == 'S') {
            scanf("%d", &a);
            getchar();
            printf("%d\n", a * 4);
            accu += a * 4;
        }else if (ch == 'T') {
            scanf("%d %d %d", &a, &b, &c);
            getchar();
            printf("%d\n", a + b + c);
            accu += a + b + c;
        }
    }
    printf("%d\n", accu);
}
int main(int argc, char **argv) {
    process();
    return 0;
}
