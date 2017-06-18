#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
typedef struct node node_t;
struct node {
    int id;
    int score;
    node_t *next;
    node_t *previous;
};
void func_p(node_t *head) {
    node_t *ptr;
    if (head == NULL) {
        printf("null\n");
    }else {
        ptr = head;
        while (ptr != NULL) {
            printf("%d:%d", ptr->id, ptr->score);
            if (ptr->next != NULL) {
                printf(",");
            }
            ptr = ptr->next;
        }
        printf("\n");
    }
}
node_t *createNode(int id, int score) {
    node_t *temp;
    temp = (node_t*)malloc(sizeof(node_t));
    temp->id = id;
    temp->score = score;
    temp->previous = NULL;
    temp->next = NULL;
    return temp;
}
void ComputeTargetFrontBehind_i(node_t *head, int id, int score, node_t **targetFront, node_t **targetBehind, int *counter) {
    node_t *ptr;
    *counter = 0;
    ptr = head;
    *targetFront = NULL;
    *targetBehind = ptr;
    while (ptr != NULL) {
        (*counter)++;
        if (score > ptr->score || (score == ptr->score && id > ptr->id)) {
            *targetFront = *targetBehind;
            *targetBehind = (*targetBehind)->next;
            ptr = ptr->next;
        }else if (score < ptr->score || (score == ptr->score && id < ptr->id)) {
            break;
        }
    }
}
void func_i(node_t **head) {
    int id, score, counter = 0;
    node_t *newnode, *targetBehind, *targetFront;
    scanf("%d,%d", &id, &score);
    getchar();
    newnode = createNode(id, score);
    if (*head == NULL) {    //no existed node
        *head = newnode;
    }else {
        ComputeTargetFrontBehind_i(*head, id, score, &targetFront, &targetBehind, &counter);
        if (targetFront == NULL && targetBehind != NULL) {  //insert at the front of the whole nodes
            newnode->next = targetBehind;
            targetBehind->previous = newnode;
            *head = newnode;
        }else if (targetFront != NULL && targetBehind == NULL) {    //insert at the last of the whole nodes
            targetFront->next = newnode;
            newnode->previous = targetFront;
        }else if (targetFront != NULL && targetBehind != NULL) {    //insert between nodes
            targetFront->next = newnode;
            newnode->previous = targetFront;
            newnode->next = targetBehind;
            targetBehind->previous = newnode;
        }
    }
    printf("Insert data %d:%d, compare:%d\n", id, score, counter);
}
node_t* getTargetNode(node_t *head, int id) {
    node_t *ptr;
    ptr = head;
    while (ptr != NULL) {
        if (ptr->id == id) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return ptr;
}
void func_d(node_t **head) {
    int id;
    node_t *targetFront, *targetBehind, *target;
    scanf("%d", &id);
    getchar();
    target = getTargetNode(*head, id);
    if (target == NULL) {
        printf("Student %d is not exist.\n", id);
    }else {
        targetFront = target->previous;
        targetBehind = target->next;
        free(target);
        if (targetFront == NULL && targetBehind == NULL) { //only one node
            *head = NULL;
        }else if (targetFront == NULL && targetBehind != NULL) {    //remove the first node
            targetBehind->previous = NULL;
            *head = targetBehind;
        }else if (targetFront != NULL && targetBehind == NULL) {    //remove the last node
            targetFront->next = NULL;
        }else if (targetFront != NULL && targetBehind != NULL) {    //revove the node between the whole
            targetFront->next = targetBehind;
            targetBehind->previous = targetFront;
        }
        printf("Delete student %d successful.\n", id);
    }
}
void process() {
    node_t *head;
    char func;
    head = NULL;
    while (scanf("%c", &func) != EOF && func != 'e') {
        switch (func) {
            case 'p':
                func_p(head);
                break;
            case 'i':
                func_i(&head);
                break;
            case 'd':
                func_d(&head);
                break;
        }
    }
}
int main(int argc, char **argv) {
    process();
    return 0;
}
