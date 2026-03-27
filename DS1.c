
// Q1: Reverse a string using stack
// Algorithm:
// 1. Start
// 2. Read string
// 3. Push each character into stack
// 4. Pop characters one by one
// 5. Print popped characters (Reversed string)
// 6. Stop

#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

// push function
void push(char ch) {
    stack[++top] = ch;
}

// pop function
char pop() {
    return stack[top--];
}

int main() {
    char str[100];
    int i;

    printf("Enter string: ");
    scanf("%s", str);

    // push all characters
    for(i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    printf("Reversed string: ");
    // pop all characters
    while(top != -1) {
        printf("%c", pop());
    }

    return 0;
}

