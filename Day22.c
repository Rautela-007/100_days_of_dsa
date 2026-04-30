// Count Nodes in Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n, value;

    printf("Enter number of nodes:\n");
    scanf("%d", &n);
    
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    printf("Enter %d node values separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    printf("Node count: %d\n", countNodes(head));
    return 0;
}
