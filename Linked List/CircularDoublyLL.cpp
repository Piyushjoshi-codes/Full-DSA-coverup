#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};
struct CircularDoublyLinkedList {
    Node* head;
    Node* tail;
    CircularDoublyLinkedList() {
        head = tail = NULL;
    }
    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
            head->next = head;
            head->prev = head;

        } else {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
    }
    void push_back(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
        } else {
            newNode->next = head;
            newNode-> prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
    }
    void pop_front() {
        if(head == NULL) return;
        else if(head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }
    void pop_back() {
        if(head == NULL) return;
        else if(head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
    }
    void print() {
        if(head == NULL) {
            cout << "Circular Doubly Linked List is Empty!";
        }        
        Node* temp = head;
        do {
            cout << temp->data << " <=> ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl;
    }
};
int main() {
    CircularDoublyLinkedList CDLL;
    CDLL.push_front(30);
    CDLL.push_front(20);
    CDLL.push_front(10);
    CDLL.push_back(40);
    CDLL.push_back(50);
    cout << "List :" << endl;
    CDLL.print();
    CDLL.pop_front();
    CDLL.pop_back();
    cout << "Final List :" << endl;
    CDLL.print();
}