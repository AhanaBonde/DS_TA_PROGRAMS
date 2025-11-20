#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 26

typedef struct TrieNode {
    struct TrieNode *child[ALPHABET];
    int end;
} TrieNode;

TrieNode* createNode() {
    TrieNode *node = malloc(sizeof(TrieNode));
    node->end = 0;
    for (int i = 0; i < ALPHABET; i++)
        node->child[i] = NULL;
    return node;
}

void insert(TrieNode *root, char *key) {
    TrieNode *p = root;
    while (*key) {
        int idx = *key - 'a';
        if (!p->child[idx])
            p->child[idx] = createNode();
        p = p->child[idx];
        key++;
    }
    p->end = 1;
}

int search(TrieNode *root, char *key) {
    TrieNode *p = root;
    while (*key) {
        int idx = *key - 'a';
        if (!p->child[idx])
            return 0;
        p = p->child[idx];
        key++;
    }
    return p->end;
}

int main() {
    TrieNode *root = createNode();
    insert(root, "apple");
    insert(root, "app");
    insert(root, "bat");

    printf("Search apple: %s\n", search(root, "apple") ? "Found" : "Not Found");
    printf("Search app: %s\n", search(root, "app") ? "Found" : "Not Found");
    printf("Search bat: %s\n", search(root, "bat") ? "Found" : "Not Found");
    printf("Search ball: %s\n", search(root, "ball") ? "Found" : "Not Found");
    return 0;
}
