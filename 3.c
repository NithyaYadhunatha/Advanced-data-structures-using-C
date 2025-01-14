#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10

int top = -1;
int stack_arr[SIZE];

void push();
int pop();
void palindrome();
void display();

int main() {
    int choice;

    while(1) {
        printf("\nEnter stack operations:");
        printf("\n1. Push\n2. Pop\n3. Palindrome\n4. Display\n5. End\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: palindrome(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("\nEnter a valid choice\n");
        }
    }
    return 0;
}

void push() {
    int value;
    if(top == SIZE - 1) {
        printf("\nStack Overflow\n");
    } else {
        printf("Enter the item to be pushed: ");
        scanf("%d", &value);
        top++;
        stack_arr[top] = value;
        printf("%d pushed into stack\n", value);
    }
}

int pop() {
    if(top == -1) {
        printf("\nStack Underflow\n");
        return -1;
    } else {
        int removed_item = stack_arr[top];
        top--;
        printf("Deleted item is: %d\n", removed_item);
        return removed_item;
    }
}

void display() {
    if(top == -1) {
        printf("\nStack is empty\n");
    } else {
        printf("\nStack contents:\n");
        for(int i = top; i >= 0; i--) {
            printf("%d\n", stack_arr[i]);
        }
    }
}

void palindrome() {
    char str[SIZE];
    printf("Enter the string: ");
    scanf("%s", str);

    int n = strlen(str);
    int is_palindrome = 1;

    for(int i = 0; i < n; i++) {
        top++;
        stack_arr[top] = str[i];
    }

    for(int i = 0; i < n; i++) {
        if(stack_arr[top] != str[i]) {
            is_palindrome = 0;
            break;
        }
        top--;
    }

    if(is_palindrome) {
        printf("Palindrome!!\n");
    } else {
        printf("Not a palindrome!!\n");
    }
}
