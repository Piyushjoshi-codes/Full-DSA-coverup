#include <iostream>
using namespace std;

#define MAX 3

class Node {
public:
    int data[MAX];
    Node* child[MAX+1];
    bool leaf;
    int n;
    Node* next;  // for leaf linking

    Node(bool leaf) {
        this->leaf = leaf;
        n = 0;
        next = NULL;
    }
};

class BPlusTree {
public:
    Node* root;

    BPlusTree() {
        root = NULL;
    }

    // Simple insert (demo level)
    void insert(int x) {
        if (root == NULL) {
            root = new Node(true);
            root->data[0] = x;
            root->n = 1;
        } else {
            insertRec(root, x);
        }
    }

    void insertRec(Node* node, int x) {
        if (node->leaf) {
            int i = node->n - 1;
            while (i >= 0 && node->data[i] > x) {
                node->data[i+1] = node->data[i];
                i--;
            }
            node->data[i+1] = x;
            node->n++;
        } else {
            int i = 0;
            while (i < node->n && x > node->data[i]) i++;
            insertRec(node->child[i], x);
        }
    }

    // Traversals

    void inorder(Node* node) {
        if (node == NULL) return;

        if (node->leaf) {
            for (int i = 0; i < node->n; i++)
                cout << node->data[i] << " ";
        } else {
            for (int i = 0; i < node->n; i++) {
                inorder(node->child[i]);
            }
            inorder(node->child[node->n]);
        }
    }

    void preorder(Node* node) {
        if (node == NULL) return;

        cout << "[ ";
        for (int i = 0; i < node->n; i++)
            cout << node->data[i] << " ";
        cout << "] ";

        if (!node->leaf) {
            for (int i = 0; i <= node->n; i++)
                preorder(node->child[i]);
        }
    }

    void postorder(Node* node) {
        if (node == NULL) return;

        if (!node->leaf) {
            for (int i = 0; i <= node->n; i++)
                postorder(node->child[i]);
        }

        cout << "[ ";
        for (int i = 0; i < node->n; i++)
            cout << node->data[i] << " ";
        cout << "] ";
    }
};

int main() {
    BPlusTree t;

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(15);

    cout << "Inorder: ";
    t.inorder(t.root);

    cout << "\nPreorder: ";
    t.preorder(t.root);

    cout << "\nPostorder: ";
    t.postorder(t.root);

    return 0;
}