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

void initQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

void initStack(Stack *stack) {
    stack->top = NULL;
}

int isQueueEmpty(Queue *queue) {
    return queue->front == NULL;
}

int isStackEmpty(Stack *stack) {
    return stack->top == NULL;
}

void enqueue(Queue *queue, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

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
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return;
    }

    newNode->data = value;
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
    initStack(&stack);

    while (!isQueueEmpty(queue)) {
        push(&stack, dequeue(queue));
    }

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
    Queue queue;

    initQueue(&queue);

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        int value;
        if (scanf("%d", &value) == 1) {
            enqueue(&queue, value);
        }
    }

    reverseQueue(&queue);

    printf("Reversed queue: ");
    printQueue(&queue);

    clearQueue(&queue);
    return 0;
}
