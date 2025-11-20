#include <stdio.h>
#define MAX 10

int arr[MAX];
int top1 = -1, top2 = MAX;

void push1(int x) {
    if (top1 + 1 == top2)
        printf("Overflow\n");
    else
        arr[++top1] = x;
}

void push2(int x) {
    if (top1 + 1 == top2)
        printf("Overflow\n");
    else
        arr[--top2] = x;
}

void pop1() {
    if (top1 == -1)
        printf("Underflow\n");
    else
        printf("Popped from Stack1: %d\n", arr[top1--]);
}

void pop2() {
    if (top2 == MAX)
        printf("Underflow\n");
    else
        printf("Popped from Stack2: %d\n", arr[top2++]);
}

void display() {
    printf("Stack1: ");
    for (int i = top1; i >= 0; i--) printf("%d ", arr[i]);
    printf("\nStack2: ");
    for (int i = top2; i < MAX; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    push1(10);
    push1(20);
    push2(100);
    push2(200);
    display();
    pop1();
    pop2();
    display();
    return 0;
}
