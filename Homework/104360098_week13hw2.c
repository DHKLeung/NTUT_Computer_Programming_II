#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
typedef struct student student_t;
struct student {
    int id;
    int score;
};
typedef struct node node_t;
struct node {
    student_t data;
    node_t *next;
    node_t *previous;
};
void printList(node_t *head) {  //print the list
    node_t *ptr;
    ptr = head;
    if (ptr == NULL) {
        printf("null\n");
    }else {
        while (ptr != NULL) {
            printf("%d:%d", (ptr->data).id, (ptr->data).score);
            if (ptr->next != NULL) {
                printf(",");
            }else {
                printf("\n");
            }
            ptr = ptr->next;
        }
    }
}
node_t* getTargetFront(node_t *head, int id, int score, int *counter) {  //return the insertion target's front address, if no node, return NULL
    node_t *ptr;
    ptr = head;
    if (ptr == NULL) {  //no node exists
        return NULL;
    }else {
        while (true) {  //figure out the position according to the score
            (*counter)++;
            if (((ptr->data).score) < score) {  //current node's score < score
                if (ptr->next == NULL) {    //if the targetFront is the last node, return current node
                    return ptr;
                }else { //the targetFront is NOT the last node
                    ptr = ptr->next;
                }
            }else { //if the current node's score > score
                break;
            }
        }
        while (ptr != NULL && (((ptr)->data).score == score) && (((ptr)->data).id < id)) {    //figure out the position according to id
            if (ptr->next == NULL) {
                return ptr;
            }else {
                (*counter)++;
                ptr = ptr->next;
            }
        }
        ptr = ptr->previous;    //figured out the targetFront
        return ptr;
    }
}
node_t* createNode(int id, int score) { //create a node and return the address of the node
    node_t *temp;
    temp = (node_t*)malloc(sizeof(node_t));
    (temp->data).id = id;
    (temp->data).score = score;
    temp->previous = NULL;
    temp->next = NULL;
    return temp;
}
void insertINORDER(node_t **head) {
    node_t *targetFront, *targetBehind, *temp;
    int id, score, counter = 0;
    scanf("%d,%d", &id, &score);
    targetFront = getTargetFront(*head, id, score, &counter); //get the target's front address
    temp = createNode(id, score);
    if (targetFront == NULL && *head == NULL) {  //if no node exists
        *head = temp;
    }else if (targetFront == NULL && *head != NULL) {   //if the targetBehind is the first node
        temp->next = *head;
        (*head)->previous = temp;
        *head = temp;
    }else if (targetFront->next == NULL) {  //if the targetFront is the last node
        targetFront->next = temp;
        temp->previous = targetFront;
    }else { //targetFront is between the head and the last node
        targetBehind = targetFront->next;
        targetFront->next = temp;
        temp->previous = targetFront;
        targetBehind->previous = temp;
        temp->next = targetBehind;
    }
    printf("Insert data %d:%d, Compare:%d, Recursive:%d.\n", id, score, counter, counter + 1);
}
void deleteLarger(node_t **head) {
    int score;
    node_t *deleteFROM, *tobedeleted;
    scanf("%d", &score);
    deleteFROM = *head;
    while (deleteFROM != NULL && (deleteFROM->data).score < score) {  //figure out the address that need to be deleted from
        if (deleteFROM->next != NULL) {
            deleteFROM = deleteFROM->next;
        }else {
            deleteFROM = NULL;
            break;
        }
    }
    if (deleteFROM == NULL || *head == NULL) {  //can't find the students of score larger than the inputted score OR no nodes exist
        printf("No student greater or equal to score:%d.\n", score);
    }else {
        if (deleteFROM->previous == NULL) { //if need to delete from the head
            while (deleteFROM != NULL) {
                tobedeleted = deleteFROM->next;
                printf("Delete student %d:%d successful.\n", (deleteFROM->data).id, (deleteFROM->data).score);
                free(deleteFROM);
                deleteFROM = tobedeleted;
            }
            *head = deleteFROM;
        }else if (deleteFROM->next == NULL) {   //if need to delete from the last node
            (deleteFROM->previous)->next = NULL;
            printf("Delete student %d:%d successful.\n", (deleteFROM->data).id, (deleteFROM->data).score);
            free(deleteFROM);
        }else { //delete between head and last
            (deleteFROM->previous)->next = NULL;
            while (deleteFROM != NULL) {
                tobedeleted = deleteFROM->next;
                printf("Delete student %d:%d successful.\n", (deleteFROM->data).id, (deleteFROM->data).score);
                free(deleteFROM);
                deleteFROM = tobedeleted;
            }
        }
    }
}
void process() {
    char func;
    node_t *head;
    head = NULL;
    while (scanf("%c", &func) && func != 'e') {
        switch (func) {
            case 'p':
                printList(head);    //print the List
                break;
            case 'i':
                insertINORDER(&head);    //insert in order
                break;
            case 'd':
                deleteLarger(&head);
                break;
        }
    }
}
int main(int argc, char **argv) {
    process();
    return 0;
}
