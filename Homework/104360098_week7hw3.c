#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
typedef struct ipset_s ipset_t;
struct ipset_s {
    int A;
    int B;
    int C;
    int D;
    char name[21];
    bool valid;
    bool checked;
};
int inputData(ipset_t ipdata[]) {
    int A, B, C, D, counter = 0;
    char name[21];
    while (scanf("%d.%d.%d.%d,%s", &A, &B, &C, &D, name) && !(A == 0 && B == 0 && C == 0 && D == 0 && strcmp(name, "none") == 0)) {
        if (A > 255 || B > 255 || C > 255 || D > 255) {
            ipdata[counter].valid = false;
        }else {
            ipdata[counter].valid = true;
        }
        ipdata[counter].checked = false;
        ipdata[counter].A = A;
        ipdata[counter].B = B;
        ipdata[counter].C = C;
        ipdata[counter].D = D;
        strcpy(ipdata[counter].name, name);
        counter++;
    }
    return counter;
}
bool isSame(ipset_t A, ipset_t B) {
    if (A.A == B.A && A.B == B.B) {
        return true;
    }else {
        return false;
    }
}
void printResult(ipset_t ipdata[], int counter) {
    int i, j, k, samecounter;
    for (i = 0; i < counter; i++) {     //print the result of found same ip
        if (ipdata[i].valid && !ipdata[i].checked) {
            samecounter = 1;
            for (j = i + 1; j < counter; j++) {
                if (isSame(ipdata[j], ipdata[i]) && ipdata[j].valid) {
                    samecounter++;
                }
            }
            if (samecounter != 1) {
                printf("machines ");
                for (j = i, k = 1; j < counter; j++) {
                    if (isSame(ipdata[j], ipdata[i]) && ipdata[j].valid) {
                        printf("%s", ipdata[j].name);
                        if (k == samecounter - 1) {
                            printf(" and ");
                        }else if (k != samecounter) {
                            printf(", ");
                        }
                        ipdata[j].checked = true;
                        k++;
                    }
                }
                printf(" are on the same local network.\n");
            }else {
                ipdata[i].checked = true;
            }
        }
    }
    for (i = 0; i < counter; i++) {     //print the result of erroneous ip
        if (!ipdata[i].valid && !ipdata[i].checked) {
            printf("machine %s is error ip\n", ipdata[i].name);
            ipdata[i].checked = true;
        }
    }
}
void process() {
    ipset_t ipdata[50];
    int counter;
    counter = inputData(ipdata);
    printResult(ipdata, counter);
}
int main(int argc, char **argv) {
    process();
    return 0;
}
