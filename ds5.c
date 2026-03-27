// Q5: Circular Queue Basic Operations
// Algorithm:
// 1. Initialize front=-1, rear=-1
// 2. Enqueue: insert element at queue[rear]
// 3. Dequeue: remove from front
// 4. Peek: return queue[front]
// 5. Display: start from front and print until rear (i+1)%SIZE

#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front=-1, rear=-1;

// enqueue function
void enqueue(int value) {
    if((rear+1)%SIZE==front) { // check queue full
        printf("Queue is Full\n");
        return;
    }
    if(front==-1) front=0; // first element
    rear=(rear+1)%SIZE;
    queue[rear]=value;
    printf("%d inserted into queue\n", value);
}

// dequeue function
void dequeue() {
    if(front==-1) { // queue empty
        printf("Queue Empty\n");
        return;
    }
    int data=queue[front];
    if(front==rear) front=rear=-1; // queue becomes empty
    else front=(front+1)%SIZE;
    printf("%d removed from queue\n", data);
}

// peek function
void peek() {
    if(front==-1) printf("Queue Empty\n");
    else printf("Front element: %d\n", queue[front]);
}

// display function
void display() {
    if(front==-1) { printf("Queue Empty\n"); return; }
    printf("Queue elements: ");
    int i=front;
    while(1) {
        printf("%d ", queue[i]);
        if(i==rear) break;
        i=(i+1)%SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while(1) {
        printf("\n1. Enqueue 2. Dequeue 3. Peek 4. Display 5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("Enter value: "); scanf("%d", &value); enqueue(value); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
