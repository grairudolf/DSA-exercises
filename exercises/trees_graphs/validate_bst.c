#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

Node* insert_bst(Node *root, int val) {
    if (!root) return new_node(val);
    if (val < root->val) root->left = insert_bst(root->left, val);
    else if (val > root->val) root->right = insert_bst(root->right, val);
    return root;
}

int is_valid_bst_range(Node *root, long long min, long long max) {
    if (!root) return 1;
    if (root->val <= min || root->val >= max) return 0;
    return is_valid_bst_range(root->left, min, root->val) &&
           is_valid_bst_range(root->right, root->val, max);
}

int main() {
    int n;
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);
    if (n <= 0) return 0;

    Node *root = NULL;
    printf("Enter %d values (will be inserted as BST): ", n);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        root = insert_bst(root, x);
    }

    int valid = is_valid_bst_range(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
    if (valid) printf("Tree is a valid BST.\n");
    else printf("Tree is NOT a valid BST.\n");
    return 0;
}
