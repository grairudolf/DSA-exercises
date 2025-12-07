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

Node* insert_bst(Node *root, int val) {
    if (!root) return new_node(val);
    if (val < root->val) root->left = insert_bst(root->left, val);
    else if (val > root->val) root->right = insert_bst(root->right, val);
    return root;
}

Node* lca_bst(Node *root, int p, int q) {
    while (root) {
        if (p < root->val && q < root->val) root = root->left;
        else if (p > root->val && q > root->val) root = root->right;
        else return root;
    }
    return NULL;
}

int main() {
    int n;
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);
    if (n <= 0) return 0;

    Node *root = NULL;
    printf("Enter %d unique values: ", n);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        root = insert_bst(root, x);
    }

    int p, q;
    printf("Enter two node values p and q: ");
    scanf("%d %d", &p, &q);

    Node *ancestor = lca_bst(root, p, q);
    if (ancestor) printf("LCA: %d\n", ancestor->val);
    else printf("LCA not found.\n");
    return 0;
}
