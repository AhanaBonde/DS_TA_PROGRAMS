#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;

Node* push(Node *top,int x){ Node *p=malloc(sizeof(Node)); p->data=x; p->next=top; return p; }
Node* pop(Node *top,int *ret){ if(!top) return NULL; *ret=top->data; Node *t=top->next; free(top); return t; }
void display(Node *top){ if(!top){ printf("Empty\n"); return;} for(;top;top=top->next) printf("%d ",top->data); printf("\n"); }

int main(){
    Node *top=NULL; int v;
    top=push(top,10); top=push(top,20); top=push(top,30);
    display(top);
    top=pop(top,&v); printf("Popped %d\n",v);
    display(top);
    return 0;
}
