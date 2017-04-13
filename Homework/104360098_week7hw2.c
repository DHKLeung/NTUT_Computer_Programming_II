#include <stdio.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void checkPercent(int A, int B) {
    int perA;
    if (A == 0 && B == 0) {
        perA = 50;
    }else if (A <= 0) {
        perA = 0;
    }else if (B <= 0) {
        perA = 100;
    }else {
        perA = (A * 1.0 / (A + B)) * 100;
    }
    printf("A:%d%%,B:%d%%\n", perA, 100 - perA);
}
void checkBalance(int value, char status) {
    printf("%c:%d\n", status, value);
}
void withdraw(int *value, char status) {
    int withdrawvalue;
    scanf("%d", &withdrawvalue);
    *value -= withdrawvalue;
    printf("%c:Withdraw,%d\n%c:%d\n", status, withdrawvalue, status, *value);
}
void deposit(int *value, char status) {
    int depositvalue;
    scanf("%d", &depositvalue);
    *value += depositvalue;
    printf("%c:Deposit,%d\n%c:%d\n", status, depositvalue, status, *value);
}
void process() {
    int A = 0, B = 0;
    char func, status;
    while (scanf("%c", &func) && func != 'e') {
        switch (func) {
            case 'a':
                printf("Select A\n");
                status = 'A';
                break;
            case 'b':
                printf("Select B\n");
                status = 'B';
                break;
            case 'v':
                if (status == 'A') {
                    checkBalance(A, status);
                }else {
                    checkBalance(B, status);
                }
                break;
            case 'w':
                if (status == 'A') {
                    withdraw(&A, status);
                }else {
                    withdraw(&B, status);
                }
                break;
            case 's':
                if (status == 'A') {
                    deposit(&A, status);
                }else {
                    deposit(&B, status);
                }
                break;
            case 'p':
                checkPercent(A, B);
                break;
        }
    }
}
int main(int argc, char **argv) {
    process();
    return 0;
}
