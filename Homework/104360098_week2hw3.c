#include <stdio.h>
#include <stdbool.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
void input(int stu[][21], int prof[][21], int *amount) {
	char inchar;
	int index = 0, i;
	while (scanf("%c", &inchar) && inchar != '\n') {
		if (inchar != ',') {
			stu[0][index] = inchar;
			*amount = *amount + 1;
			index++;
		}
	}
	for (i = 1; i < *amount; i++) {
		index = 0;
		while (scanf("%c", &inchar) && inchar != '\n') {
			if (inchar != ',') {
				stu[i][index] = inchar;
				index++;
			}
		}
	}
	for (i = 0; i < *amount; i++) {
		index = 0;
		while (scanf("%c", &inchar) && inchar != '\n') {
			if (inchar != ',') {
				prof[i][index] = inchar;
				index++;
			}
		}
	}
}
bool process_isFinished(int result[], int amount) {
	int i, j;
	for (i = 0; i < amount - 1; i++) {
		for (j = i + 1; j < amount; j++) {
			if (result[i] == result[j]) {
				return false;
			}
		}
	}
	return true;
}
void process_compare_assignAndshift(int result[], int stuAssign[], int stuShift[], int Assign, int Shift) {
    result[Assign] = stuAssign[stuAssign[20]];
    stuShift[20] += 1;
    result[Shift] = stuShift[stuShift[20]];
}
void process_compare(int stuA[], int stuB[], int prof[][21], int amount, int result[], int  A, int B, int minstu) {
	int i;
	if (stuA[stuA[20]] == stuB[stuB[20]]) {
		if (stuA[20] < stuB[20]) {
            process_compare_assignAndshift(result, stuA, stuB, A, B);
        }else if (stuB[20] < stuA[20]) {
            process_compare_assignAndshift(result, stuB, stuA, B, A);
        }else {
    		for (i = 0; i < amount; i++) {
    			if (prof[stuA[stuA[20]] - 65][i] == (A + minstu)) {
    				process_compare_assignAndshift(result, stuA, stuB, A, B);
    				break;
    			}else if (prof[stuB[stuB[20]] - 65][i] == (B + minstu)) {
    				process_compare_assignAndshift(result, stuB, stuA, B, A);
    				break;
    			}
    		}
        }
	}else {
		result[A] = stuA[stuA[20]];
		result[B] = stuB[stuB[20]];
	}
}
void process(int stu[][21], int prof[][21], int amount, int result[], int *minstu) {
	int i, j;
	*minstu = prof[0][0];
	for (i = 0; i < amount; i++) {
		for (j = 0; j < amount; j++) {
			if (prof[i][j] < *minstu) {
				*minstu = prof[i][j];
			}
		}
	}
    while (!process_isFinished(result, amount)) {
		for (i = 0; i < amount - 1; i++) {
			for (j = i + 1; j < amount; j++) {
				process_compare(stu[i], stu[j], prof, amount, result, i, j, *minstu);
			}
		}
    }
}
void printresult(int result[], int amount, int minstu) {
    int i;
    for (i = 0; i < amount; i++) {
        printf("%c->%c\n", i + minstu, result[i]);
    }
}
int main(int argc, char **argv) {
	int stu[20][21] = { 0 }, prof[20][21] = { 0 }, amount = 0, result[20] = { 0 }, minstu;
	input(stu, prof, &amount);
	process(stu, prof, amount, result, &minstu);
	printresult(result, amount, minstu);
	return 0;
}
