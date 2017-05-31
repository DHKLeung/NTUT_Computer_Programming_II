#include <stdio.h>
#include <stdlib.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
typedef struct node node_t;
struct node {
    int data;
    node_t *left;
    node_t *right;
};
void printInorder(node_t *ptr) {    //print inorder
    if (ptr != NULL) {
        printInorder(ptr->left);
        printf("%d ", ptr->data);
        printInorder(ptr->right);
    }
}
void func_p(node_t *root) { //function p
    if (root == NULL) { //no tree exists
        printf("null\n");
    }else { //tree exists
        printInorder(root); //print the tree in order
        printf("\n");
    }
}
node_t* getTargetParent(node_t *ptr, int insertvalue) { //get the target position's parent
    if (insertvalue <= ptr->data) { //should be linked to left
        if (ptr->left != NULL) {    //left child exists
            return getTargetParent(ptr->left, insertvalue);
        }else { //no left child, the current ptr is the target position's parent
            return ptr;
        }
    }else if (insertvalue > ptr->data) {    //should be linked to right
        if (ptr->right != NULL) {   //right child exists
            return getTargetParent(ptr->right, insertvalue);
        }else { //no right child, the current ptr is the target position's parent
            return ptr;
        }
    }
}
node_t* createNode(int value) { //create a node
    node_t *ptr;
    ptr = (node_t*)malloc(sizeof(node_t));
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->data = value;
    return ptr;
}
void func_i(node_t **root) {    //function i
    int insertvalue;
    node_t *targetParent, *ptr;
    scanf("%d", &insertvalue);  //input the being insertted value
    ptr = createNode(insertvalue);  //create a node
    if (*root == NULL) {    //if not tree exists, new one
        *root = ptr;
    }else { //tree exists
        targetParent = getTargetParent(*root, insertvalue); //figure out the target's parent
        if (insertvalue <= targetParent->data) {    //link to the left child
            targetParent->left = ptr;
        }else if (insertvalue > targetParent->data) {   //link to the right child
            targetParent->right = ptr;
        }
    }
}
void process() {
    char func;
    node_t *root;
    root = NULL;
    while (scanf("%c", &func) != EOF && func != 'e') {  //keep inputting the func
        switch (func) {
            case 'p':   //function p
                func_p(root);
                break;
            case 'i':   //function i
                func_i(&root);
                break;
        }
    }
}
int main(int argc, char **argv) {
    process();
    return 0;
}