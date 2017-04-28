#include <stdio.h>
#include <stdlib.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
typedef struct gate gate_t;
struct gate {
    int inputx;
    int inputy;
    int (*output)(gate_t*);
};
int gateoutputAND(gate_t *g) {
    return (g->inputx)&(g->inputy);
}
int gateoutputOR(gate_t *g) {
    return (g->inputx)|(g->inputy);
}
int gateoutputNOT(gate_t *g) {
    return !(g->inputx);
}
int gateoutputEMPTY(gate_t *g) {
    return g->inputx;
}
gate_t* createGate(char gt) {
    gate_t *temp;
    temp = (gate_t*)malloc(sizeof(gate_t));
    if (gt == 'N') {
        temp->output = gateoutputNOT;
    }else if (gt == 'A') {
        temp->output = gateoutputAND;
    }else if (gt == 'O') {
        temp->output = gateoutputOR;
    }else if (gt == 'E') {
        temp->output = gateoutputEMPTY;
    }
    return temp;
}
void inputData(int *i1, int *i2, int *i3, char *gt1, char *gt2, char *gt3) {
    scanf("%d,%d,%d", i1, i2, i3);
    getchar();
    scanf("%c,%c,%c", gt1, gt2, gt3);
}
void mapping(int i1, int i2, int i3, gate_t *p, gate_t *q, gate_t *r) {
    p->inputx = i1;
    q->inputx = p->output(p);
    q->inputy = i2;
    r->inputx = q->output(q);
    r->inputy = i3;
}
void process() {
    gate_t *p, *q, *r;
    int i1, i2, i3;
    char gt1, gt2, gt3;
    inputData(&i1, &i2, &i3, &gt1, &gt2, &gt3);
    p = createGate(gt1);
    q = createGate(gt2);
    r = createGate(gt3);
    mapping(i1, i2, i3, p, q, r);
    printf("%d,%d,%d\n", p->output(p), q->output(q), r->output(r));
}
int main(int argc, char **argv) {
    process();
    return 0;
}
