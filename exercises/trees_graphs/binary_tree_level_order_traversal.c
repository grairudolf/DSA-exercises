#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node* new_node(int val) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

void level_order(Node *root) {
    if (!root) return;

    Node *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int level_size = rear - front;
        for (int i = 0; i < level_size; i++) {
            Node *cur = queue[front++];
            printf("%d ", cur->val);
            if (cur->left) queue[rear++] = cur->left;
            if (cur->right) queue[rear++] = cur->right;
        }
        printf("\n");
    }
}

int main() {
    // Simple sample tree: 1 2 3 4 5
    Node *root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);

    printf("Level order traversal (each level on new line):\n");
    level_order(root);

    return 0;
}
