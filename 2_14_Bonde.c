#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int x) {
    Node *p = malloc(sizeof(Node));
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

Node* insert(Node *root, int x) {
    if (!root) return createNode(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

void inorder(Node *r) {
    if (!r) return;
    inorder(r->left);
    printf("%d ", r->data);
    inorder(r->right);
}

void preorder(Node *r) {
    if (!r) return;
    printf("%d ", r->data);
    preorder(r->left);
    preorder(r->right);
}

void postorder(Node *r) {
    if (!r) return;
    postorder(r->left);
    postorder(r->right);
    printf("%d ", r->data);
}

void bfs(Node *root) {
    if (!root) return;
    Node *q[100];
    int f = 0, r = 0;
    q[r++] = root;
    while (f < r) {
        Node *t = q[f++];
        printf("%d ", t->data);
        if (t->left) q[r++] = t->left;
        if (t->right) q[r++] = t->right;
    }
}

Node* mirror(Node *r) {
    if (!r) return NULL;
    Node *temp = r->left;
    r->left = mirror(r->right);
    r->right = mirror(temp);
    return r;
}

int main() {
    int a[] = {50, 30, 20, 40, 70, 60, 80};
    Node *root = NULL;

    for (int i = 0; i < 7; i++)
        root = insert(root, a[i]);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    printf("BFS: ");
    bfs(root);
    printf("\n");

    root = mirror(root);
    printf("Mirror Inorder: ");
    inorder(root);
    printf("\n");

    return 0;
}
