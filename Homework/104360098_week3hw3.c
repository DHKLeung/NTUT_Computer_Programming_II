#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
int split(char str[]) {
	int i, amount = 0, originLength;
	originLength = strlen(str);
	for (i = 0; i < originLength; i++) {
		if (str[i] == ' ') {
			str[i] = '\0';
			amount++;
		}
	}
	return amount + 1;
}
void process_1_2_3_4_result(char passage[], char P[], char Q[]) {
	int i, j, wordamount, freq[101] = { 0 }, wordlistamount = 0, tempint;
	char *ptr, copy[101], wordlist[30][101], temp[101];
	bool isexist;
	strcpy(copy, passage);
	wordamount = split(copy);
	ptr = copy;
	for (i = 0; i < wordamount; i++) {
		if (strncmp(ptr, P, strlen(P)) == 0) {
			printf("%s ", Q);
		}else {
			printf("%s ", ptr);
		}
		ptr += strlen(ptr) + 1;
	}
	printf("\n");
	ptr = copy;
	for (i = 0; i < wordamount; i++) {
		if (strncmp(ptr, P, strlen(P)) == 0) {
			printf("%s ", Q);
			printf("%s ", ptr);
		}else {
			printf("%s ", ptr);
		}
		ptr += strlen(ptr) + 1;
	}
	printf("\n");
	ptr = copy;
	for (i = 0; i < wordamount; i++) {
		if (!(strncmp(ptr, P, strlen(P)) == 0)) {
			printf("%s ", ptr);
		}
		ptr += strlen(ptr) + 1;
	}
	printf("\n");
	ptr = copy;
	for (i = 0; i < wordamount; i++) {
		isexist = false;
		for (j = 0; j < wordlistamount; j++) {
			if (strcmp(ptr, wordlist[j]) == 0) {
				isexist = true;
				break;
			}
		}
		if (!isexist) {
			strcpy(wordlist[wordlistamount], ptr);
			wordlistamount++;
		}
		ptr += strlen(ptr) + 1;
	}
	ptr = copy;
	for (i = 0; i < wordamount; i++) {
		for (j = 0; j < wordlistamount; j++) {
			if (strcmp(ptr, wordlist[j]) == 0) {
				freq[j]++;
				break;
			}
		}
		ptr += strlen(ptr) + 1;
	}
	for (i = 0; i < wordlistamount - 1; i++) {
		for (j = 0; j < wordlistamount - 1 - i; j++) {
			if (freq[j] < freq[j + 1]) {
				tempint = freq[j];
				freq[j] = freq[j + 1];
				freq[j + 1] = tempint;
				strcpy(temp, wordlist[j]);
				strcpy(wordlist[j], wordlist[j + 1]);
				strcpy(wordlist[j + 1], temp);
			}else if (freq[j] == freq[j + 1]) {
				if (strcmp(wordlist[j], wordlist[j + 1]) > 0) {
					tempint = freq[j];
					freq[j] = freq[j + 1];
					freq[j + 1] = tempint;
					strcpy(temp, wordlist[j]);
					strcpy(wordlist[j], wordlist[j + 1]);
					strcpy(wordlist[j + 1], temp);		
				}
			}
		}
	}
	for (i = 0; i < wordlistamount; i++) {
		printf("%s %d\n", wordlist[i], freq[i]);
	}
}
int main(int argc, char **argv) {
	char passage[101], P[11], Q[11];
	fgets(passage, 101, stdin);
	passage[strlen(passage) - 1] = '\0';
	scanf("%s%s", P, Q);
	process_1_2_3_4_result(passage, P, Q);
	return 0;
}
