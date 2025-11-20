#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}
void reverse(char *exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char t = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = t;
    }
}
int main() {
    char infix[MAX], prefix[MAX];
    int j = 0;
    printf("Enter infix: ");
    scanf("%s", infix);
    reverse(infix);
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isalnum(c)) prefix[j++] = c;
        else if (c == '(') push(c);
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') prefix[j++] = pop();
            top--;
        } else {
            while (top != -1 && prec(stack[top]) > prec(c)) prefix[j++] = pop();
            push(c);
        }
    }
    while (top != -1) prefix[j++] = pop();
    prefix[j] = '\0';
    reverse(prefix);
    printf("Prefix: %s\n", prefix);
    return 0;
}
