#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of queue

// Queue structure
typedef struct {
    int items[MAX];
    int front;
    int rear;
    int count;  // To track number of elements
} Queue;

// Function prototypes
void init(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void display(Queue *q);
int size(Queue *q);
int head(Queue *q);
int tail(Queue *q);

int main() {
    Queue q;
    int choice, value;
    
    // Initialize queue
    init(&q);
    
    printf("=== QUEUE IMPLEMENTATION USING ARRAY ===\n");
    printf("Queue size: %d elements\n", MAX);
    
    do {
        printf("\n--- MENU ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Remove)\n");
        printf("3. Display\n");
        printf("4. Size of Queue\n");
        printf("5. Head Element\n");
        printf("6. Tail Element\n");
        printf("7. Check if Empty\n");
        printf("8. Check if Full\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (isFull(&q)) {
                    printf("Queue Overflow! Cannot enqueue element.\n");
                } else {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(&q, value);
                    printf("%d enqueued to queue.\n", value);
                }
                break;
                
            case 2:
                if (isEmpty(&q)) {
                    printf("Queue Underflow! Cannot dequeue element.\n");
                } else {
                    value = dequeue(&q);
                    printf("%d dequeued from queue.\n", value);
                }
                break;
                
            case 3:
                display(&q);
                break;
                
            case 4:
                printf("Size of queue: %d elements\n", size(&q));
                break;
                
            case 5:
                if (isEmpty(&q)) {
                    printf("Queue is empty! No head element.\n");
                } else {
                    printf("Head element: %d\n", head(&q));
                }
                break;
                
            case 6:
                if (isEmpty(&q)) {
                    printf("Queue is empty! No tail element.\n");
                } else {
                    printf("Tail element: %d\n", tail(&q));
                }
                break;
                
            case 7:
                if (isEmpty(&q)) {
                    printf("Queue is EMPTY.\n");
                } else {
                    printf("Queue is NOT empty.\n");
                }
                break;
                
            case 8:
                if (isFull(&q)) {
                    printf("Queue is FULL.\n");
                } else {
                    printf("Queue is NOT full.\n");
                }
                break;
                
            case 9:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 9);
    
    return 0;
}

// Initialize queue
void init(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return (q->count == 0);
}

// Check if queue is full
int isFull(Queue *q) {
    return (q->count == MAX);
}

// Enqueue element to queue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    
    // Circular increment of rear
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    q->count++;
}

// Dequeue element from queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;  // Error value
    }
    
    int value = q->items[q->front];
    // Circular increment of front
    q->front = (q->front + 1) % MAX;
    q->count--;
    return value;
}

// Display queue elements
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue elements (front to rear):\n");
    printf("Front -> ");
    
    if (q->front <= q->rear) {
        // Normal case: front <= rear
        for(int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
    } else {
        // Circular case: rear < front
        for(int i = q->front; i < MAX; i++) {
            printf("%d ", q->items[i]);
        }
        for(int i = 0; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
    }
    printf("<- Rear\n");
    
    // Show array indices for clarity
    printf("Indices: ");
    for(int i = 0; i < MAX; i++) {
        if (q->count > 0 && 
            ((q->front <= q->rear && i >= q->front && i <= q->rear) ||
             (q->front > q->rear && (i >= q->front || i <= q->rear)))) {
            printf("[%d: %d] ", i, q->items[i]);
        } else {
            printf("[%d: --] ", i);
        }
    }
    printf("\n");
}

// Get size of queue
int size(Queue *q) {
    return q->count;
}

// Get head (front) element
int head(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;  // Error value
    }
    return q->items[q->front];
}

// Get tail (rear) element
int tail(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;  // Error value
    }
    return q->items[q->rear];
}