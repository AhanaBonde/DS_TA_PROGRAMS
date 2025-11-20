#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev, *next;
} DNode;

DNode* create(int a[], int n) {
    DNode *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        DNode *p = malloc(sizeof(DNode));
        p->data = a[i];
        p->prev = tail;
        p->next = NULL;
        if (!head) head = p;
        else tail->next = p;
        tail = p;
    }
    return head;
}

DNode* insertBegin(DNode *h, int x) {
    DNode *p = malloc(sizeof(DNode));
    p->data = x;
    p->prev = NULL;
    p->next = h;
    if (h) h->prev = p;
    return p;
}

DNode* insertEnd(DNode *h, int x) {
    DNode *p = malloc(sizeof(DNode));
    p->data = x;
    p->next = NULL;
    if (!h) { p->prev = NULL; return p; }
    DNode *t = h;
    while (t->next) t = t->next;
    t->next = p;
    p->prev = t;
    return h;
}

DNode* deleteBegin(DNode *h) {
    if (!h) return NULL;
    DNode *t = h->next;
    free(h);
    if (t) t->prev = NULL;
    return t;
}

DNode* deleteEnd(DNode *h) {
    if (!h) return NULL;
    if (!h->next) { free(h); return NULL; }
    DNode *t = h;
    while (t->next) t = t->next;
    t->prev->next = NULL;
    free(t);
    return h;
}

void display(DNode *h) {
    while (h) {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}

int main() {
    int a[] = {4, 1, 6, 3};
    DNode *h = create(a, 4);

    display(h);
    h = insertBegin(h, 9);
    display(h);
    h = insertEnd(h, 2);
    display(h);
    h = deleteBegin(h);
    display(h);
    h = deleteEnd(h);
    display(h);

    return 0;
}
