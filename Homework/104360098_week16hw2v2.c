#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
typedef struct node node_t;
struct node {
    char data;
    node_t *child[3];
    int valid;
};
void BubbleSort(node_t *node) {
    int i, j;
    node_t *temp;
    for (i = 0; i < node->valid - 1; i++) {
        for (j = 0; j < node->valid - 1 - i; j++) {
            if (node->child[j]->data > node->child[j + 1]->data) {
                temp = node->child[j];
                node->child[j] = node->child[j + 1];
                node->child[j + 1] = temp;
            }
        }
    }
}
void DFS(node_t *ptr) {
    int i;
    if (ptr != NULL) {
        printf("%c", ptr->data);
        BubbleSort(ptr);
        for (i = 0; i < ptr->valid; i++) {
            DFS(ptr->child[i]);
        }
    }
}
node_t* createNode(char data) {
    node_t *temp;
    temp = (node_t*)malloc(sizeof(node_t));
    temp->data = data;
    temp->child[0] = temp->child[1] = temp->child[2] = NULL;
    temp->valid = 0;
    return temp;
}
node_t* getTargetNode(node_t *ptr, char parent) {
    int i;
    node_t *temp;
    if (ptr != NULL) {
        if (ptr->data == parent) {
            return ptr;
        }else {
            for (i = 0; i < ptr->valid; i++) {
                temp = getTargetNode(ptr->child[i], parent);
                if (temp != NULL) {
                    return temp;
                }
            }
        }
    }
    return NULL;
}
void func_i(node_t **head) {
    char input[20];
    node_t *newnode, *ptr;
    int i;
    scanf("%s", input);
    getchar();
    if (*head == NULL) {
        *head = createNode(input[0]);
    }
    ptr = getTargetNode(*head, input[0]);
    for (i = 1; i < (int)strlen(input); i++) {
        newnode = createNode(input[i]);
        ptr->child[ptr->valid] = newnode;
        (ptr->valid)++;
    }
}
void process() {
    char func;
    node_t *head = NULL;
    while (scanf("%c", &func) != EOF && func != 'e') {
        getchar();
        switch (func) {
            case 'p':
                if (head == NULL) {
                    printf("null\n");
                }else {
                    DFS(head);
                    printf("\n");
                }
                break;
            case 'i':
                func_i(&head);
                break;
        }
    }
}
int main(int argc, char **argv) {
    process();
    return 0;
}
