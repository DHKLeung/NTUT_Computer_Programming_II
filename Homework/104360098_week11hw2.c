#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
typedef struct node node_t;
struct node {
    int power;
    int coe;
    node_t *next;
};
void printlist(node_t *head) {
    node_t *ptr;
    ptr = head;
    while (ptr->next != NULL) {
        printf("(%d,%d), ", ptr->power, ptr->coe);
        ptr = ptr->next;
    }
    printf("(%d,%d)\n", ptr->power, ptr->coe);
}
void inputdata(char pre[], char now[]) {
    fgets(pre, 21, stdin);
    pre[strlen(pre) - 1] = '\0';
    fgets(now, 21, stdin);
    now[strlen(now) - 1] = '\0';
}
node_t* createNode(int power, int coe) {
    node_t *temp;
    temp = (node_t*)malloc(sizeof(node_t));
    temp->power = power;
    temp->coe = coe;
    temp->next = NULL;
    return temp;
}
void classify(char inputstr[], node_t **head) {
    int n = 0, i, *ptr, len;
    char *strptr;
    node_t *temp, *tail;
    for (i = 0; i < strlen(inputstr); i++) {
        if (inputstr[i] == ' ') {
            n++;
        }
    }
    n++;
    ptr = (int*)malloc(sizeof(int) * n);
    len = strlen(inputstr);
    for (i = 0; i < len; i++) {
        if (inputstr[i] == ' ') {
            inputstr[i] = '\0';
        }
    }
    strptr = inputstr;
    for (i = 0; i < n; i++) {
        ptr[i] = atoi(strptr);
        strptr += strlen(strptr) + 1;
    }
    for (i = 0; i < n; i++) {
        if (i == 0) {
            *head = createNode(n - 1 - i, ptr[i]);
            tail = *head;
        }else {
            temp = createNode(n - 1 - i, ptr[i]);
            tail->next = temp;
            tail = temp;
        }
    }
}
void printresult(node_t *prehead, node_t *nowhead) {
    node_t *preptr, *nowptr;
    preptr = prehead;
    nowptr = nowhead;
    while (preptr->next != NULL) {
        if (preptr->power == nowptr->power) {
            printf("%d ", preptr->coe + nowptr->coe);
            preptr = preptr->next;
            nowptr = nowptr->next;
        }else {
            printf("%d ", preptr->coe);
            preptr = preptr->next;
        }
    }
    if (preptr->power == nowptr->power) {
        printf("%d ", preptr->coe + nowptr->coe);
        preptr = preptr->next;
        nowptr = nowptr->next;
    }else {
        printf("%d ", preptr->coe);
        preptr = preptr->next;
    }
}
void process() {
    char pre[21], now[21];
    node_t *prehead, *nowhead, *temp;
    inputdata(pre, now);
    classify(pre, &prehead);
    classify(now, &nowhead);
    if (prehead->power < nowhead->power) {
        temp = prehead;
        prehead = nowhead;
        nowhead = temp;
    }
    printresult(prehead, nowhead);
}
int main(int argc, char **argv) {
    process();
    return 0;
}
