#include <stdio.h>
#include <stdlib.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
typedef struct node node_t;
struct node {
    int value;
    node_t *next;
};
node_t* createNode(int value) {
    node_t *temp;
    temp = (node_t*)malloc(sizeof(node_t));
    temp->value = value;
    temp->next = NULL;
    return temp;
}
void push(int value, node_t **top) {
    node_t *temp;
    if (*top == NULL) {
        *top = createNode(value);
    }else {
        temp = createNode(value);
        temp->next = *top;
        *top = temp;
    }
}
void pop(node_t **top) {
    int popvalue;
    node_t *temp;
    if (*top == NULL) {
        printf("The Stack is empty\n");
    }else {
        popvalue = (*top)->value;
        temp = *top;
        *top = (*top)->next;
        free(temp);
        printf("The data %d is pop\n", popvalue);
    }
}
void process() {
    int func, value;
    node_t *top;
    top = NULL;
    while (scanf("%d", &func) && func != 3) {
        if (func == 1) {
            scanf("%d", &value);
        }
        switch (func) {
            case 1:
                push(value, &top);
                break;
            case 2:
                pop(&top);
                break;
        }
    }
}
int main(int argc, char **argv) {
    process();
    return 0;
}
