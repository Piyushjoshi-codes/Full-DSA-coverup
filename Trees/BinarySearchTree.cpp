#include<iostream>
#include<vector>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
void preOrder(Node* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root) {
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(Node* root) {
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
bool Search(Node* root, int key) {
    if(root == NULL) return false;
    if(root->data == key) return true;
    if(root->data > key) return Search(root->left, key);
    else return Search(root->right, key);
}
Node* insert(Node* root, int val) {
    if(root == NULL) {
        return new Node(val);
    }
    if(val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}
Node* BinarySearchT(vector<int> arr) {
    Node* root = NULL;
    for(int val : arr) {
        root = insert(root, val);
    }
    return root;
}
Node* inOrderSuccessor(Node* root) {  //To find the left-most Node in the right subtree of node to be delete...
    while(root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}
Node* delNode(Node* root, int key) {    //key = Node to delete...
    if(root == NULL) return NULL;
    if(key < root->data) {
        root->left = delNode(root->left, key);
    } else if(key > root->data) {
        root->right = delNode(root->right, key);
    } else {   //key == Root
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* Is = inOrderSuccessor(root->right);
            root->data = Is->data;
            root->right = delNode(root->right, Is->data);
        }
    }
    return root;
}
int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int n;
    Node* root = BinarySearchT(arr);
    cout << "PreOrder Traversal: \t";
    preOrder(root);
    cout << endl;
    cout << "InOrder Traversal: \t";
    inOrder(root);
    cout << endl;
    cout << "PostOrder Traversal: \t";
    postOrder(root);
    cout << endl;

    cout << "Enter the value to be searched: \t"; cin >> n;
    //To search an item in tree...
    if(Search(root, n) == 1) cout << "We found " << n << endl;
    else cout << "No such earches found" << endl; 
    return 0;

    //To delete an item from the list...
    cout << "Tree before deleting : ";
    inOrder(root);
    cout << endl;
    cout << "Tree after deleting : ";
    delNode(root, 5);
    inOrder(root);
    cout << endl;

    return 0;
}