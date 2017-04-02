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
void input(int coe[][51], int res[], int *numformu) {
    int i, j;
    scanf("%d", numformu);
    for (i = 1; i <= *numformu; i++) {
        for (j = 1; j <= *numformu; j++) {
            scanf("%d", &coe[i][j]);
        }
        scanf("%d", &res[i]);
    }
}
void gaussian_each(int coe[][51], int res[], int numformu, int pivot) {

}
void gaussianprocess(int coe[][51], int res[], int numformu) {
    int pivot, j;
    for (pivot = 1; pivot <= numformu; pivot++) {
        for (j = pivot + 1; j <= numformu; j++) {
            
        }
    }
}
int main(int argc, char **argv) {
    int coe[51][51], res[51], numformu;
    input(coe, res, &numformu);
    gaussianprocess(coe, res, numformu);

    return 0;
}
