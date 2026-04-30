// Find Intersection Point of Two Linked Lists
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

void appendNode(struct Node** head, struct Node** tail, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;
    
    // Advance longer list
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            ptr1 = ptr1->next;
        }
    } else {
        for (int i = 0; i < len2 - len1; i++) {
            ptr2 = ptr2->next;
        }
    }
    
    // Find intersection
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data) {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return NULL;
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    printf("Enter number of nodes in first linked list:\n");
    scanf("%d", &n);

    printf("Enter %d values for first linked list:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        appendNode(&head1, &tail1, value);
    }

    printf("Enter number of nodes in second linked list:\n");
    scanf("%d", &m);

    printf("Enter %d values for second linked list:\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        appendNode(&head2, &tail2, value);
    }

    struct Node* intersection = findIntersection(head1, head2);
    if (intersection != NULL) {
        printf("Intersection point: %d\n", intersection->data);
    } else {
        printf("No intersection point found\n");
    }

    return 0;
}
