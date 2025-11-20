#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double evalPostfix(char *exp) {
    double stack[100];
    int top = -1;

    char *token = strtok(exp, " ");
    while (token) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
            stack[++top] = atof(token);
        else {
            double b = stack[top--];
            double a = stack[top--];
            double r = 0;

            if (strcmp(token, "+") == 0) r = a + b;
            else if (strcmp(token, "-") == 0) r = a - b;
            else if (strcmp(token, "*") == 0) r = a * b;
            else if (strcmp(token, "/") == 0) r = a / b;
            else if (strcmp(token, "^") == 0) r = pow(a, b);

            stack[++top] = r;
        }
        token = strtok(NULL, " ");
    }
    return stack[top];
}

int main() {
    char exp[200];
    strcpy(exp, "10 2 8 * + 3 -");

    printf("Postfix: %s\n", exp);
    printf("Result: %.2f\n", evalPostfix(exp));
    return 0;
}
