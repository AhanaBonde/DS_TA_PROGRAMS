#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front, *rear;
} Queue;

Queue* createQueue() {
    Queue *q = malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, int x) {
    Node *p = malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;

    if (!q->rear)
        q->front = q->rear = p;
    else {
        q->rear->next = p;
        q->rear = p;
    }
}

int dequeue(Queue *q, int *ok) {
    if (!q->front) {
        *ok = 0;
        return -1;
    }
    Node *t = q->front;
    int val = t->data;
    q->front = q->front->next;
    if (!q->front)
        q->rear = NULL;
    free(t);
    *ok = 1;
    return val;
}

void display(Queue *q) {
    Node *p = q->front;
    if (!p) {
        printf("Queue Empty\n");
        return;
    }
    for (; p; p = p->next)
        printf("%d ", p->data);
    printf("\n");
}

int main() {
    Queue *q = createQueue();
    int ok;

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    display(q);

    printf("Dequeued: %d\n", dequeue(q, &ok));
    display(q);

    return 0;
}
