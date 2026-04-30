// Delete First Occurrence of a Key
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* deleteKey(struct Node* head, int key) {
    // Handle head deletion
    if (head != NULL && head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    struct Node* prev = NULL;
    struct Node* current = head;
    
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }
    
    if (current != NULL) {
        prev->next = current->next;
        free(current);
    }
    
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, value, key;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    printf("Enter number of nodes:\n");
    scanf("%d", &n);

    printf("Enter %d node values separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    printf("Enter key to delete:\n");
    scanf("%d", &key);
    head = deleteKey(head, key);
    printf("Linked list after deletion: ");
    printList(head);
    return 0;
}
