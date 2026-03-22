#include <iostream>
using namespace std;

#define T 3  // Minimum degree

class BTreeNode {
public:
    int keys[2*T-1];
    BTreeNode* C[2*T];
    int n;
    bool leaf;

    BTreeNode(bool leaf) {
        this->leaf = leaf;
        n = 0;
    }

    // Traversals
    void inorder() {
        int i;
        for (i = 0; i < n; i++) {
            if (!leaf)
                C[i]->inorder();
            cout << keys[i] << " ";
        }
        if (!leaf)
            C[i]->inorder();
    }

    void preorder() {
        cout << "[ ";
        for (int i = 0; i < n; i++)
            cout << keys[i] << " ";
        cout << "] ";

        if (!leaf) {
            for (int i = 0; i <= n; i++)
                C[i]->preorder();
        }
    }

    void postorder() {
        if (!leaf) {
            for (int i = 0; i <= n; i++)
                C[i]->postorder();
        }
        cout << "[ ";
        for (int i = 0; i < n; i++)
            cout << keys[i] << " ";
        cout << "] ";
    }

    // Insert non-full
    void insertNonFull(int k) {
        int i = n - 1;

        if (leaf) {
            while (i >= 0 && keys[i] > k) {
                keys[i+1] = keys[i];
                i--;
            }
            keys[i+1] = k;
            n++;
        } else {
            while (i >= 0 && keys[i] > k)
                i--;
            i++;

            if (C[i]->n == 2*T-1) {
                splitChild(i, C[i]);

                if (keys[i] < k)
                    i++;
            }
            C[i]->insertNonFull(k);
        }
    }

    void splitChild(int i, BTreeNode* y) {
        BTreeNode* z = new BTreeNode(y->leaf);
        z->n = T - 1;

        for (int j = 0; j < T-1; j++)
            z->keys[j] = y->keys[j+T];

        if (!y->leaf) {
            for (int j = 0; j < T; j++)
                z->C[j] = y->C[j+T];
        }

        y->n = T - 1;

        for (int j = n; j >= i+1; j--)
            C[j+1] = C[j];

        C[i+1] = z;

        for (int j = n-1; j >= i; j--)
            keys[j+1] = keys[j];

        keys[i] = y->keys[T-1];
        n++;
    }
};

class BTree {
public:
    BTreeNode* root;

    BTree() {
        root = NULL;
    }

    void insert(int k) {
        if (root == NULL) {
            root = new BTreeNode(true);
            root->keys[0] = k;
            root->n = 1;
        } else {
            if (root->n == 2*T-1) {
                BTreeNode* s = new BTreeNode(false);
                s->C[0] = root;
                s->splitChild(0, root);

                int i = 0;
                if (s->keys[0] < k)
                    i++;
                s->C[i]->insertNonFull(k);

                root = s;
            } else {
                root->insertNonFull(k);
            }
        }
    }

    void inorder() { root->inorder(); }
    void preorder() { root->preorder(); }
    void postorder() { root->postorder(); }
};

int main() {
    BTree t;

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);

    cout << "Inorder: ";
    t.inorder();

    cout << "\nPreorder: ";
    t.preorder();

    cout << "\nPostorder: ";
    t.postorder();

    return 0;
}