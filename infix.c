#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void push(Stack s, char c) {
    if (s.top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s.items[++(s.top)] = c;
}

char pop(Stack s) {
    if (s.top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s.items[(s.top)--];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    stack.top = -1;
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char current = infix[i];

        if (isalnum(current)) {
            postfix[j++] = current;
        } else if (current == '(') {
            push(stack, current);
        } else if (current == ')') {
            while (stack.top != -1 && stack.items[stack.top] != '(') {
                postfix[j++] = pop(stack);
            }
            if (stack.top == -1) {
                printf("Invalid expression\n");
                return;
            }
            pop(stack); // Discard '(' from the stack
        } else {
            while (stack.top != -1 && precedence(current) <= precedence(stack.items[stack.top])) {
                postfix[j++] = pop(stack);
            }
            push(stack, current);
        }
        i++;
    }

    while (stack.top != -1) {
        if (stack.items[stack.top] == '(' || stack.items[stack.top] == ')') {
            printf("Invalid expression\n");
            return;
        }
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strlen(infix) - 1] = '\0';

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}