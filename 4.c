#include <stdio.h>
#include <ctype.h>

#define MAX 100

// Function to determine the precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;   // Lowest precedence
    } else if (c == '*' || c == '/') {
        return 2;   // Higher precedence
    } else if (c == '%') {
        return 3;   // Higher precedence than +, -, *, /
    } else if (c == '^') {
        return 4;   // Highest precedence
    }
    return 0;   // If it's not an operator
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char *infix, char *postfix) {
    char stack[MAX];
    int top = -1, k = 0, i;
    char c;

    // Process each character of the infix expression
    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            stack[++top] = c;
        }
        // If the character is ')', pop from the stack until '(' is found
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--;  // Pop '('
        }
        // If the character is an operator, pop operators from the stack based on precedence
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = c;
        }
    }

    // Pop remaining operators from the stack
    while (top != -1) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0';  // Null terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    // Read the infix expression from user
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Print the postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
