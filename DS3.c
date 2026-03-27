
// Q3: Next Greater Element
// Algorithm:
// 1. Start
// 2. Take array input
// 3. Use stack to track elements
// 4. For each element:
//    → Compare with stack top
//    → Print next greater
// 5. If no greater → print -1
// 6. Stop

#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// push element into stack
void push(int x) { stack[++top] = x; }

// pop element
int pop() { return stack[top--]; }

int main() {
    int arr[] = {5,6,7,8,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;

    // initialize stack with first element
    push(arr[0]);

    for(i=1; i<n; i++) {
        // compare with stack top
        while(top!=-1 && stack[top]<arr[i]) {
            printf("%d -> %d\n", pop(), arr[i]);
        }
        push(arr[i]);
    }

    // print -1 if no greater element
    while(top!=-1) {
        printf("%d -> -1\n", pop());
    }

    return 0;
}
