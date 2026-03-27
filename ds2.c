// Q2: Balanced Parentheses
// Algorithm:
// 1. Scan expression
// 2. Push opening brackets
// 3. On closing bracket → check match with stack top
// 4. If mismatched → Not Balanced
// 5. At end, if stack empty → Balanced

#include <stdio.h>
#include <string.h>
#define MAX 50

char stack[MAX];
int top = -1;

// push function
void push(char ch) { stack[++top] = ch; }

// pop function
char pop() { return stack[top--]; }

// match function
int match(char a, char b) {
    return (a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']');
}

// check function
int check(char *exp) {
    for(int i=0; i<strlen(exp); i++) {
        // push open
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[') {
            push(exp[i]);
        }
        // mismatch check
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']') {
            if(top==-1 || !match(stack[top], exp[i])) return 0;
            pop();
        }
    }
    // Balanced if empty
    return (top==-1);
}

int main() {
    char exp[MAX];
    printf("Enter expression: ");
    scanf("%s", exp);

    if(check(exp)) printf("Balanced Expression\n");
    else printf("Not Balanced Expression\n");

    return 0;
}
