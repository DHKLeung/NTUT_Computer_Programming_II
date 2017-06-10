#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
typedef struct node node_t;
struct node {
    char data;
    node_t *child[3];
    int validchild;
};
void bubblesort(char arr[]) {
    int i, j, n;
    char temp;
    n = strlen(arr);
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
node_t* createNode(char data) {
    node_t *temp;
    temp = (node_t*)malloc(sizeof(node_t));
    temp->data = data;
    temp->child[0] = temp->child[1] = temp->child[2] = NULL;
    temp->validchild = 0;
    return temp;
}
node_t* getTargetNode(char target_data, node_t *r) {
    node_t *ptr;
    int i;
    if (r == NULL) {
        return NULL;
    }else {
        if (r->data == target_data) {
            return r;
        }else {
            for (i = 0; i < 3; i++) {
                ptr = getTargetNode(target_data, r->child[i]);
                if (ptr != NULL) {
                    return ptr;
                }
            }
        }
    }
    return NULL;
}
void func_i(node_t **root) {
    char input[5];
    int n, i, j;
    node_t *ptr, *temp;
    scanf("%s", input);
    getchar();
    bubblesort(&input[1]);
    if (*root == NULL) {
        *root = createNode(input[0]);
    }
    ptr = getTargetNode(input[0], *root);
    n = strlen(input) - 1;
    for (i = 0; i < n; i++) {
        ptr->child[ptr->validchild] = createNode(input[i + 1]);
        (ptr->validchild)++;
    }
    for (i = 0; i < ptr->validchild - 1; i++) {
        for (j = 0; j < ptr->validchild - i - 1; j++) {
            if (ptr->child[j]->data > ptr->child[j + 1]->data) {
                temp = ptr->child[j];
                ptr->child[j] = ptr->child[j + 1];
                ptr->child[j + 1] = temp;
            }
        }
    }
}
void func_p_DFS(node_t *ptr) {
    int i;
    if (ptr != NULL) {
        printf("%c", ptr->data);
        for (i = 0; i < ptr->validchild; i++) {
            func_p_DFS(ptr->child[i]);
        }
    }
}
void process() {
    node_t *root;
    root = NULL;
    char func;
    while (scanf("%c", &func) != EOF && func != 'e') {
        getchar();
        switch (func) {
            case 'p':
                if (root == NULL) {
                    printf("null\n");
                }else {
                    func_p_DFS(root);
                    printf("\n");
                }
                break;
            case 'i':
                func_i(&root);
                break;
        }
    }
}
int main(int argc, char **argv) {
    process();
    return 0;
}
