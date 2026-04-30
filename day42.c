#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

typedef struct Stack {
    Node *top;
} Stack;

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void initializeQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

void initializeStack(Stack *stack) {
    stack->top = NULL;
}

int isQueueEmpty(Queue *queue) {
    return queue->front == NULL;
}

int isStackEmpty(Stack *stack) {
    return stack->top == NULL;
}

void enqueue(Queue *queue, int value) {
    Node *newNode = createNode(value);

    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        return -1;
    }

    Node *temp = queue->front;
    int value = temp->data;

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return value;
}

void push(Stack *stack, int value) {
    Node *newNode = createNode(value);

    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        return -1;
    }

    Node *temp = stack->top;
    int value = temp->data;

    stack->top = stack->top->next;

    free(temp);
    return value;
}

void reverseQueue(Queue *queue) {
    Stack stack;
    initializeStack(&stack);

    // First, move all queue elements into the stack.
    while (!isQueueEmpty(queue)) {
        push(&stack, dequeue(queue));
    }

    // Then, move them back. Stack gives values in reverse order.
    while (!isStackEmpty(&stack)) {
        enqueue(queue, pop(&stack));
    }
}

void printQueue(Queue *queue) {
    Node *current = queue->front;

    while (current != NULL) {
        printf("%d", current->data);

        if (current->next != NULL) {
            printf(" ");
        }

        current = current->next;
    }

    printf("\n");
}

void clearQueue(Queue *queue) {
    while (!isQueueEmpty(queue)) {
        dequeue(queue);
    }
}

int main() {
    int n;
    int value;
    Queue queue;

    initializeQueue(&queue);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(&queue, value);
    }

    reverseQueue(&queue);
    printQueue(&queue);

    clearQueue(&queue);

    return 0;
}
