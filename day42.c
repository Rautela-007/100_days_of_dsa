#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

struct Stack {
    struct Node *top;
};

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void initializeQueue(struct Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

void initializeStack(struct Stack *stack) {
    stack->top = NULL;
}

int isQueueEmpty(struct Queue *queue) {
    return queue->front == NULL;
}

int isStackEmpty(struct Stack *stack) {
    return stack->top == NULL;
}

void enqueue(struct Queue *queue, int value) {
    struct Node *newNode = createNode(value);

    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue *queue) {
    if (isQueueEmpty(queue)) {
        return -1;
    }

    struct Node *temp = queue->front;
    int value = temp->data;

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return value;
}

void push(struct Stack *stack, int value) {
    struct Node *newNode = createNode(value);

    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack *stack) {
    if (isStackEmpty(stack)) {
        return -1;
    }

    struct Node *temp = stack->top;
    int value = temp->data;

    stack->top = stack->top->next;

    free(temp);
    return value;
}

void reverseQueue(struct Queue *queue) {
    struct Stack stack;
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

void printQueue(struct Queue *queue) {
    struct Node *current = queue->front;

    while (current != NULL) {
        printf("%d", current->data);

        if (current->next != NULL) {
            printf(" ");
        }

        current = current->next;
    }

    printf("\n");
}

void clearQueue(struct Queue *queue) {
    while (!isQueueEmpty(queue)) {
        dequeue(queue);
    }
}

int main() {
    int n;
    int value;
    struct Queue queue;

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
