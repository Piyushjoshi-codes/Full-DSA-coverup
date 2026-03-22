#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

// Utility functions
int getHeight(Node* n) {
    if (n == NULL) return 0;
    return n->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getBalance(Node* n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// Create node
Node* createNode(int x) {
    Node* n = new Node();
    n->data = x;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

// Right Rotation (LL)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left Rotation (RR)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Insert function
Node* insert(Node* root, int key) {

    // BST insert
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && key < root->left->data)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && key > root->right->data)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


// 🔹 Traversals

// Inorder (LNR)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Preorder (NLR)
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder (LRN)
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}


// 🔹 Main
int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}