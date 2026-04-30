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

int isEmpty(Queue *queue) {
    return queue->front == NULL;
}

void enqueue(Queue *queue, int value) {
    Node *newNode = createNode(value);

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

int isEnqueue(char operation[]) {
    return operation[0] == 'e' || operation[0] == 'E' || operation[0] == '1';
}

int isDequeue(char operation[]) {
    return operation[0] == 'd' || operation[0] == 'D' || operation[0] == '2';
}

void clearQueue(Queue *queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
}

int main() {
    int n;
    int value;
    char operation[20];
    Queue queue;

    initializeQueue(&queue);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%19s", operation);

        if (isEnqueue(operation)) {
            scanf("%d", &value);
            enqueue(&queue, value);
        } else if (isDequeue(operation)) {
            printf("%d\n", dequeue(&queue));
        }
    }

    clearQueue(&queue);

    return 0;
}
