#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void input(int coe[][51], int res[], int *numformu) {   //handle the input of augmented matrix
    int i, j;
    scanf("%d", numformu);
    for (i = 1; i <= *numformu; i++) {
        for (j = 1; j <= *numformu; j++) {
            scanf("%d", &coe[i][j]);
        }
        scanf("%d", &res[i]);
    }
}
void gaussian_each(int A[], int B[], int *ARES, int *BRES, int n, int pivot) {  //do the gaussian elimination for two rows
    int temp[51], i, tempRES;
    for (i = 1; i <= n; i++) {
        temp[i] = A[i] * (0 - B[pivot]);
    }
    tempRES = *ARES * (0 - B[pivot]);
    for (i = 1; i <= n; i++) {
        B[i] *= A[pivot];
    }
    *BRES = *BRES * A[pivot];
    for (i = 1; i <= n; i++) {
        B[i] = temp[i] + B[i];
    }
    *BRES = *BRES + tempRES;
}
void gaussianprocess(int coe[][51], int res[], int numformu) {  //gaussian elimination
    int pivot, j;
    for (pivot = 1; pivot <= numformu; pivot++) {
        for (j = pivot + 1; j <= numformu; j++) {
            gaussian_each(coe[pivot], coe[j], &res[pivot], &res[j], numformu, pivot);   //eliminate each two rows
        }
    }
}
int getHCF(int a, int b) {  //return hcf
    int i;
    i = abs(a);
    while (i >= 1) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
        i--;
    }
}
void printasfraction(double n) {
    int hcf, A, B;
    A = round(n * 10000.0);
    B = 10000;
    hcf = getHCF(A, B); //find hcf
    A /= hcf;
    B /= hcf;
    printf("%d/%d\n", A, B);    //print as fraction
}
void backsub_printresult(double fres[], int numformu) { //print the result
    int i;
    for (i = 1; i <= numformu; i++) {
        if (fres[i] - floor(fres[i]) > 0) {
            printf("X[%d] = ", i);
            printasfraction(fres[i]);   //need to be presented by fraction
        }else {
            printf("X[%d] = %.*lf\n", i, 0, fres[i]);
        }
    }
}
void backsub(int coe[][51], int res[], int numformu) {  ////perform back substitution
    double fres[51] = { 0.0 }, temp;
    int i, j, k;
    for (i = numformu; i >= 1; i--) {
        temp = 0.0;
        for (j = 1; j <= numformu; j++) {
            if (j == i) {
                continue;
            }else {
                temp += fres[j] * (coe[i][j] * 1.0);
            }
        }
        fres[i] = res[i] * 1.0 - temp;
        fres[i] /= (coe[i][i] * 1.0);
    }
    backsub_printresult(fres, numformu);    //print the result
}
int main(int argc, char **argv) {
    int coe[51][51], res[51], numformu;
    input(coe, res, &numformu); //input augmented matrix
    gaussianprocess(coe, res, numformu);    //complete the gaussian elimination
    backsub(coe, res, numformu);    //perform back substitution
    return 0;
}
