#include <stdio.h>
#include <stdlib.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void permu_computemin(int* num, int N, int *map, int *min) {
    int i, cumulate = 0;
    for (i = 0; i < N - 1; i++) {
    	if (map[num[i] * (N + 1) + num[i + 1]] == 0) {
    		return;
    	}
    	cumulate += map[num[i] * (N + 1) + num[i + 1]];
    }
    if (cumulate < *min) {
    	*min = cumulate;
    }
}
void permu_copyarray(int destin[], int source[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        destin[i] = source[i];
    }
}
void permu_rotate(int num[], int i, int j) {
    int temp;
    int k;
    temp = num[j];
    for (k = j; k > i; k--) {
        num[k] = num[k - 1];
    }
    num[i] = temp;
}
void permu(int num[], int i, int N, int *map, int *min) {
	int *destin = NULL;
	destin = (int*)malloc(sizeof(int) * N);
    if (i < N) {
        int j;
        for (j = i; j < N; j++) {
            permu_copyarray(destin, num, N);
            permu_rotate(destin, i, j);
            permu(destin, i + 1, N, map, min);
        }
    }else {
    	permu_computemin(num, N, map, min);
    }
}
void initialmap(int map[], int N) {
	int i, j;
	for (i = 1; i < N + 1; i++) {
		for (j = 1; j < N + 1; j++) {
			map[i * (N + 1) + j] = 0;
		}
	}
}
void initialnum(int *num, int N) {
	int i;
	for (i = 1; i <= N; i++) {
		num[i - 1] = i;
	}
}
int main(int argc, char **argv) {
    int N, relations, *num, *map, i, x, y, distant, min = 999;
    scanf("%d,%d", &N, &relations);
    num = (int*)malloc(sizeof(int) * N);
    map = (int*)malloc(sizeof(int) * (N + 1) * (N + 1));
    initialnum(num, N);
    initialmap(map, N);
    for (i = 0; i < relations; i++) {
    	scanf("%d,%d,%d", &x, &y, &distant);
    	map[x * (N + 1) + y] = distant;
    	map[y * (N + 1) + x] = distant;
    }
    permu(num, 1, N, map, &min);
    printf("%d\n", min);
    return 0;
}
