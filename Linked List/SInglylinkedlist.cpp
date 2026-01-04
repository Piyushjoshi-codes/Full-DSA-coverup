#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};
class SinglyLinkedList {
    Node* head;
    Node* tail;
    
    public:
    SinglyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    void push_back(int val) {
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_front() {
        if(head == NULL) return;
        if(head->next == NULL) {
            delete head;
            head = tail = NULL;
            return; 
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    void pop_back() {
        if(head == NULL) return;
        if(head->next == NULL) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    void print() {
        if(head == NULL) {
            cout << "Singly Linked List is Empty!" << endl;
            return;
        }
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main() {
    SinglyLinkedList SLL;
    SLL.push_front(3);
    SLL.push_front(2);
    SLL.push_front(1);
    SLL.push_back(4);
    SLL.push_back(5);
    cout << "List: \n";
    SLL.print();
    SLL.pop_front();
    SLL.pop_back();
    cout << "Final List: \n";
    SLL.print();
}