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

void printRange(Node *root, int low, int high) {
    if (!root) return;
    if (root->data > low)
        printRange(root->left, low, high);
    if (root->data >= low && root->data <= high)
        printf("%d ", root->data);
    if (root->data < high)
        printRange(root->right, low, high);
}

int main() {
    int a[] = {40, 20, 60, 10, 30, 50, 70};
    Node *root = NULL;
    for (int i = 0; i < 7; i++)
        root = insert(root, a[i]);

    int low = 25, high = 65;
    printf("Data in range [%d, %d]: ", low, high);
    printRange(root, low, high);
    return 0;
}
