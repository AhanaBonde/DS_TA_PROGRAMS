#include <stdio.h>
#define MAX 50
int stack[MAX], top = -1;

void push(int n) { stack[++top] = n; }

int main() {
    int num;
    printf("Enter decimal: ");
    scanf("%d", &num);
    while (num > 0) {
        push(num % 2);
        num /= 2;
    }
    printf("Binary: ");
    for (int i = top; i >= 0; i--) printf("%d", stack[i]);
    printf("\n");
    return 0;
}
