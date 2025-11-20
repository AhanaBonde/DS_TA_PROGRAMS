#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int x) {
    Node *p = malloc(sizeof(Node));
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

Node* insert(Node *r, int x) {
    if (!r) return newNode(x);
    if (x < r->data) r->left = insert(r->left, x);
    else r->right = insert(r->right, x);
    return r;
}

int findMin(Node *r) {
    while (r && r->left)
        r = r->left;
    return r ? r->data : -1;
}

int findMax(Node *r) {
    while (r && r->right)
        r = r->right;
    return r ? r->data : -1;
}

int main() {
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    Node *root = NULL;
    for (int i = 0; i < 7; i++)
        root = insert(root, a[i]);

    printf("Min = %d\n", findMin(root));
    printf("Max = %d\n", findMax(root));
    return 0;
}
