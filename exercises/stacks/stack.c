#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of stack

// Stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function prototypes
void init(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
void display(Stack *s);
int size(Stack *s);
int top(Stack *s);

int main() {
    Stack s;
    int choice, value;
    
    // Initialize stack
    init(&s);
    
    printf("=== STACK IMPLEMENTATION USING ARRAY ===\n");
    
    do {
        printf("\n--- MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Size of Stack\n");
        printf("5. Top Element\n");
        printf("6. Check if Empty\n");
        printf("7. Check if Full\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (isFull(&s)) {
                    printf("Stack Overflow! Cannot push element.\n");
                } else {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push(&s, value);
                    printf("%d pushed to stack.\n", value);
                }
                break;
                
            case 2:
                if (isEmpty(&s)) {
                    printf("Stack Underflow! Cannot pop element.\n");
                } else {
                    value = pop(&s);
                    printf("%d popped from stack.\n", value);
                }
                break;
                
            case 3:
                display(&s);
                break;
                
            case 4:
                printf("Size of stack: %d\n", size(&s));
                break;
                
            case 5:
                if (isEmpty(&s)) {
                    printf("Stack is empty! No top element.\n");
                } else {
                    printf("Top element: %d\n", top(&s));
                }
                break;
                
            case 6:
                if (isEmpty(&s)) {
                    printf("Stack is EMPTY.\n");
                } else {
                    printf("Stack is NOT empty.\n");
                }
                break;
                
            case 7:
                if (isFull(&s)) {
                    printf("Stack is FULL.\n");
                } else {
                    printf("Stack is NOT full.\n");
                }
                break;
                
            case 8:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 8);
    
    return 0;
}

// Initialize stack
void init(Stack *s) {
    s->top = -1;  // Empty stack
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return (s->top == -1);
}

// Check if stack is full
int isFull(Stack *s) {
    return (s->top == MAX - 1);
}

// Push element to stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->top++;
    s->items[s->top] = value;
}

// Pop element from stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;  // Error value
    }
    int value = s->items[s->top];
    s->top--;
    return value;
}

// Display stack elements
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    
    printf("Stack elements (top to bottom):\n");
    for(int i = s->top; i >= 0; i--) {
        printf("| %3d |\n", s->items[i]);
    }
    printf("------\n");
}

// Get size of stack
int size(Stack *s) {
    return s->top + 1;
}

// Get top element
int top(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;  // Error value
    }
    return s->items[s->top];
}