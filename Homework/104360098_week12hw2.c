#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
typedef struct node node_t;
typedef struct hub hub_t;
struct node {
	int value;
	node_t *next;
};
struct hub {
	char name[21];
	int size;
	node_t *head;
};
void CreateQueue(hub_t hub[], int *queueAmount) {	//create a queue
	char name[21];
	scanf("%s", name);
	strcpy(hub[*queueAmount].name, name);
	hub[*queueAmount].size = 0;
	hub[*queueAmount].head = NULL;
	(*queueAmount)++;
}
node_t* createNode(int value) {	//create a element
	node_t *temp;
	temp = (node_t*)malloc(sizeof(node_t));
	temp->value = value;
	temp->next = NULL;
	return temp;
}
node_t* getRearNode(node_t *head) {	//return the address of the rear node of the queue
	node_t *ptr;
	ptr = head;
	if (ptr != NULL) {	//if at least one node exists
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
	}
	return ptr;
}
void EnQueue(hub_t hub[], int queueAmount) {	//add a new element from the rear
	int i, index, value;
	char name[21];
	bool isExist = false;
	node_t *temp, *rear;
	scanf("%s", name);
	for (index = 0; index < queueAmount; index++) {	//check whether the name inputted exists
		if (strcmp(hub[index].name, name) == 0) {
			isExist = true;
			break;
		}
	}
	if (!isExist) {	//name inputted doesn't exist
		printf("Queue %s isn't exist\n", name);
	}else {	//name inputted exists
		scanf("%d", &value);
		getchar();
		temp = createNode(value);
		rear = getRearNode(hub[index].head);	//get the address of the rear node
		if (rear == NULL) {	//if the queue is originally empty
			hub[index].head = temp;
		}else {
			rear->next = temp;
		}
		(hub[index].size)++;
	}
}
void DeQueue(hub_t hub[], int queueAmount) {
	int i, index, value;
	char name[21];
	bool isExist = false;
	node_t *temp;
	scanf("%s", name);
	for (index = 0; index < queueAmount; index++) {	//check whether the name inputted exists
		if (strcmp(hub[index].name, name) == 0) {
			isExist = true;
			break;
		}
	}
	if (!isExist) {	//name inputted doesn't exist
		printf("Queue %s isn't exist\n", name);
	}else if (hub[index].size == 0) {	//queue size = 0
		printf("Queue is empty\n");
	}else {	//dequeue
		temp = hub[index].head;
		hub[index].head = (hub[index].head)->next;
		free(temp);
		(hub[index].size)--;
	}
}
void eliminateQueue(hub_t hub[], int *queueAmount, int indexB) {	//eliminate the targetted queue
	int i;
	for (i = indexB; i < *queueAmount; i++) {
		hub[i].head = hub[i + 1].head;
		hub[i].size = hub[i + 1].size;
		strcpy(hub[i].name, hub[i + 1].name);
	}
    (*queueAmount)--;
}
void MergeQueue(hub_t hub[], int *queueAmount) {
	char nameA[21], nameB[21];
	int i, indexA, indexB;
	node_t *rearA;
	bool boolA = false, boolB = false;
	scanf("%s %s", nameA, nameB);
	for (i = 0; i < *queueAmount; i++) {	//check whether the two names inputted exist
		if (strcmp(hub[i].name, nameA) == 0) {
			boolA = true;
			indexA = i;
		}else if (strcmp(hub[i].name, nameB) == 0) {
			boolB = true;
			indexB = i;
		}
	}
	if (!(boolA && boolB)) {	//if not exists
		if (!boolA) {
			printf("Queue %s isn't exist\n", nameA);
		}
		if (!boolB) {
			printf("Queue %s isn't exist\n", nameB);
		}
	}else {	//merge and eliminate the queueB
		rearA = getRearNode(hub[indexA].head);
		if (rearA == NULL) {
			hub[indexA].head = hub[indexB].head;
			(hub[indexA].size) += hub[indexB].size;
		}else {
			rearA->next = hub[indexB].head;
			(hub[indexA].size) += hub[indexB].size;
		}
		eliminateQueue(hub, queueAmount, indexB);
	}
}
void printElement(hub_t *hubT) {	//print the queue element
	node_t *ptr;
	if (hubT->size == 0) {
		printf("Queue is empty\n");
	}else {
		ptr = hubT->head;
		while (ptr != NULL) {
			printf("%d ", ptr->value);
			ptr = ptr->next;
		}
		printf("\n");
	}
}
void PrintAllQueue(hub_t hub[], int queueAmount) {	//print the content of queues
	int i;
	printf("****************************************\n");
	if (queueAmount == 0) {	//no queue
		printf("Isn't have any queue\n");
	}else {	//print content of queues
		for (i = 0; i < queueAmount; i++) {
			printf("Queue Name:%s Queue Size:%d Queue Element:", hub[i].name, hub[i].size);
			printElement(hub + i);	//print the specific queue elements
		}
	}
	printf("****************************************\n");
}
void process() {
	int func, queueAmount = 0;
	hub_t hub[50];
	while (scanf("%d", &func) && func != 6) {	//user choose function
		getchar();
		switch (func) {
			case 1:	//func : 1 = create node
				CreateQueue(hub, &queueAmount);
				break;
			case 2:	//func : 2 = Enqueue
				EnQueue(hub, queueAmount);
				break;
			case 3:	//func : 3 = Dequeue
				DeQueue(hub, queueAmount);
				break;
			case 4:	//func : 4 = Merge two queues
				MergeQueue(hub, &queueAmount);
				break;
			case 5:	//func : 5 = print all the element of all queues
				PrintAllQueue(hub, queueAmount);
				break;
		}
	}
}
int main(int argc, char **argv) {
	process();
	return 0;
}
