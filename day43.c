#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

int firstValue = 1;

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) {
        return NULL;
    }

    struct Node *root = createNode(arr[0]);

    // Queue stores nodes whose children are still to be created.
    // struct Node ** means "array of Node pointers".
    struct Node **queue = (struct Node **)malloc(n * sizeof(struct Node *));
    int front = 0;
    int rear = 0;
    int i = 1;

    queue[rear++] = root;

    while (front < rear && i < n) {
        struct Node *parent = queue[front++];

        // Next value becomes the left child.
        if (arr[i] != -1) {
            parent->left = createNode(arr[i]);
            queue[rear++] = parent->left;
        }
        i++;

        // Next value becomes the right child.
        if (i < n && arr[i] != -1) {
            parent->right = createNode(arr[i]);
            queue[rear++] = parent->right;
        }
        i++;
    }

    free(queue);
    return root;
}

void inorder(struct Node *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);

    if (firstValue == 0) {
        printf(" ");
    }
    printf("%d", root->data);
    firstValue = 0;

    inorder(root->right);
}

void freeTree(struct Node *root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;

    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node *root = buildTree(arr, n);

    inorder(root);
    printf("\n");

    freeTree(root);
    free(arr);

    return 0;
}
