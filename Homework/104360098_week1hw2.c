#include <stdio.h>
#include <stdlib.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
typedef struct _node node;
struct _node {
    int number;
    node *next;
};
node *span(int total) { //span the whole set of nodes
    int i;
    node *head = NULL, *temp = NULL;
    for (i = 1; i <= total; i++) {
        if (i == 1) {
            head = (node*)malloc(sizeof(node));
            head->number = i;
            head->next = NULL;
            temp = head;
        }else {
            temp->next = (node*)malloc(sizeof(node));
            temp = temp->next;
            temp->number = i;
            temp->next = NULL;
        }
    }
    temp->next = head;
    return head;
}
void process(node *target, int M, int K) {  //process
    int m, k;
    node *deltemp = NULL, *delbefore = NULL, prefirst;
    prefirst.number = 0;
    prefirst.next = target;
    target = &prefirst;
    for (k = K; k > 0; k--) {   //process the bombing
        for (m = M; m > 0; m--) {
            if ((target->next)->number == -1) {
                m = m + 1;
            }
            target = target->next;
        }
        printf("%d ", target->number);
        target->number = -1;
    }
    target = target->next;
    while (target->number == -1) {  //find the lucky person
        target = target->next;
    }
    printf("%d\n", target->number); //output the lucky person
}
int main(int argc, char **argv) {
    int N, M, K;
    node *target = NULL;
    scanf("%d %d %d", &N, &M, &K);
    target = span(N);
    process(target, M, K);
    return 0;
}
