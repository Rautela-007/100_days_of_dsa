#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(Queue *queue) {
    return queue->front == NULL;
}

void enqueue(Queue *queue, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
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

int isEnqueueOperation(char operation[]) {
    return strcmp(operation, "enqueue") == 0 ||
           strcmp(operation, "ENQUEUE") == 0 ||
           strcmp(operation, "Enqueue") == 0 ||
           strcmp(operation, "1") == 0;
}

int isDequeueOperation(char operation[]) {
    return strcmp(operation, "dequeue") == 0 ||
           strcmp(operation, "DEQUEUE") == 0 ||
           strcmp(operation, "Dequeue") == 0 ||
           strcmp(operation, "2") == 0;
}

void clearQueue(Queue *queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
}

int main() {
    int n;
    Queue queue;

    initQueue(&queue);

    printf("Enter number of operations: ");
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        char operation[20];

        printf("Enter operation %d: ", i + 1);
        if (scanf("%19s", operation) != 1) {
            break;
        }

        if (isEnqueueOperation(operation)) {
            int value;
            printf("Enter value to enqueue: ");
            if (scanf("%d", &value) == 1) {
                enqueue(&queue, value);
            }
        } else if (isDequeueOperation(operation)) {
            printf("%d\n", dequeue(&queue));
        }
    }

    clearQueue(&queue);
    return 0;
}
