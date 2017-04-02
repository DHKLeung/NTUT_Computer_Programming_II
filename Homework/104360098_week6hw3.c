#include <stdio.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void print(int coe[][51], int res[], int numformu) {
    int i, j;
    for (i = 1; i <= numformu; i++) {
        for (j = 1; j <= numformu; j++) {
            printf("%d ", coe[i][j]);
        }
        printf("%d\n", res[i]);
    }
}
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
void backsub(int coe[][51], int res[], int numformu) {
    int fres[51];
}
int main(int argc, char **argv) {
    int coe[51][51], res[51], numformu;
    input(coe, res, &numformu); //input augmented matrix
    gaussianprocess(coe, res, numformu);    //complete the gaussian elimination
    print(coe, res, numformu);
    backsub(coe, res, numformu);
    return 0;
}
