#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Computer Programming (II), Coded by Leung Ho Kwan 104360098*/
typedef struct node node_t;
struct node {
    char data;
    node_t *left;
    node_t *right;
};
typedef struct queue queue_t;
struct queue {
    node_t *qdata[50];
    int headindex;
    int rareindex;
};
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
void enqueue(node_t *element, queue_t *q) {
    q->qdata[q->rareindex] = element;
    (q->rareindex)++;
}
void LevelTraversal(queue_t *q) {   //level traversal
    while (q->headindex != q->rareindex) {  //queue isn't empty, means there are nodes that need to be processed
        printf("%c", (q->qdata[q->headindex])->data);
        if ((q->qdata[q->headindex])->left != NULL) {   //if the current node has left child
            enqueue((q->qdata[q->headindex])->left, q);
        }
        if ((q->qdata[q->headindex])->right != NULL) {  //if the current node has right child
            enqueue((q->qdata[q->headindex])->right, q);
        }
        (q->headindex)++;   //queue head increment
    }
    printf("\n");
}
queue_t* makequeue() {
    queue_t *temp;
    temp = (queue_t*)malloc(sizeof(queue_t));
    temp->headindex = 0;
    temp->rareindex = 0;
    return temp;
}
node_t* makeNode(char data) {
    node_t *temp;
    temp = (node_t*)malloc(sizeof(node_t));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
node_t* build_PreAndIn(char *i, char *s, int n) {
    node_t *r = NULL;
    int nl = 0;
    if (n == 1) {
        return makeNode(*i);
    }
    while (i[nl] != s[0]) {
        nl++;
    }
    r = makeNode(*s);
    if (n - nl - 1 > 0) {
        r->right = build_PreAndIn(i + nl + 1, s + nl + 1, n - nl - 1);
    }
    if (nl > 0) {
        r->left = build_PreAndIn(i, s + 1, nl);
    }
    return r;
}
node_t* build_PostAndIn(char *i, char *s, int n) {
    node_t *r = NULL;
    int nl = 0;
    if (n == 1) {
        return makeNode(*i);
    }
    while (i[nl] != s[0]) {
        nl++;
    }
    r = makeNode(*s);
    if (n - nl - 1 > 0) {
        r->right = build_PostAndIn(i + nl + 1, s + 1, n - nl - 1);
    }
    if (nl > 0) {
        r->left = build_PostAndIn(i, s + (n - nl), nl);
    }
    return r;
}
int input(char i[], char s[]) {
    char flag;
    int f;
    scanf("%c", &flag);
    if (flag == 'P' || flag == 'O') {
        if (flag == 'P') {
            f = 1;
        }else {
            f = -1;
        }
        scanf("%s", s);
        getchar();
        scanf("%c", &flag);
        scanf("%s", i);
        getchar();
    }else {
        scanf("%s", i);
        getchar();
        scanf("%c", &flag);
        if (flag == 'P') {
            f = 1;
        }else {
            f = -1;
        }
        scanf("%s", s);
        getchar();
    }
    return f;
}
void process() {
    char i[50], s[50];
    int n, f;
    node_t *root;
    queue_t *q;
    f = input(i, s);
    n = (int)strlen(i);
    if (f == 1) {
        root = build_PreAndIn(i, s, (int)strlen(i));
    }else if (f == -1) {
        strrev(s);
        root = build_PostAndIn(i, s, (int)strlen(i));
    }
    q = makequeue();
    enqueue(root, q);
    LevelTraversal(q);
}
int main(int argc, char **argv) {
    process();
    return 0;
}
