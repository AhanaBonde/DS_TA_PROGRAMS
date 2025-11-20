#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create(int a[], int n) {
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        Node *p = malloc(sizeof(Node));
        p->data = a[i];
        p->next = NULL;
        if (!head) head = tail = p;
        else { tail->next = p; tail = p; }
    }
    return head;
}

Node* insertBegin(Node *h, int x) {
    Node *p = malloc(sizeof(Node));
    p->data = x;
    p->next = h;
    return p;
}

Node* insertEnd(Node *h, int x) {
    Node *p = malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    if (!h) return p;
    Node *t = h;
    while (t->next) t = t->next;
    t->next = p;
    return h;
}

Node* deleteBegin(Node *h) {
    if (!h) return NULL;
    Node *t = h->next;
    free(h);
    return t;
}

Node* deleteEnd(Node *h) {
    if (!h) return NULL;
    if (!h->next) { free(h); return NULL; }
    Node *t = h;
    while (t->next->next) t = t->next;
    free(t->next);
    t->next = NULL;
    return h;
}

Node* reverse(Node *h) {
    Node *prev = NULL, *cur = h, *next;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int sumList(Node *h) {
    int sum = 0;
    while (h) {
        sum += h->data;
        h = h->next;
    }
    return sum;
}

Node* findMiddle(Node *h) {
    Node *slow = h, *fast = h;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void display(Node *h) {
    while (h) {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}

int main() {
    int a[] = {3, 1, 4, 2, 7};
    Node *h = create(a, 5);

    display(h);
    h = insertBegin(h, 9);
    display(h);
    h = insertEnd(h, 8);
    display(h);
    h = deleteBegin(h);
    display(h);
    h = deleteEnd(h);
    display(h);
    h = reverse(h);
    display(h);

    printf("Sum = %d\n", sumList(h));
    printf("Middle = %d\n", findMiddle(h)->data);
    return 0;
}
