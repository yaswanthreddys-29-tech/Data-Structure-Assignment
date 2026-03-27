// Q4: Printer Queue Simulation
// Algorithm:
// 1. Start
// 2. Initialize queue
// 3. Display Menu (Add, Print, Display)
// 4. Perform operations using FIFO
// 5. Stop

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front=-1, rear=-1;

// enqueue function
void enqueue(int x) {
    if(rear==MAX-1) { // check queue full
        printf("Queue Full\n");
        return;
    }
    if(front==-1) front=0; // first element
    queue[++rear]=x;
    printf("%d added to queue\n", x);
}

// dequeue function
void dequeue() {
    // remove element
    if(front==-1 || front>rear) {
        printf("Queue Empty\n");
        return;
    }
    printf("Printed document: %d\n", queue[front++]);
}

// display function
void display() {
    // display queue
    if(front==-1 || front>rear) {
        printf("No pending documents\n");
        return;
    }
    printf("Pending documents: ");
    for(int i=front; i<=rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, doc;
    while(1) {
        printf("\n1. Add 2. Print 3. Display 4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("Enter id: "); scanf("%d", &doc); enqueue(doc); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}

