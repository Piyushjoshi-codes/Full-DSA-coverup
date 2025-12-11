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
struct DoublyLinkedList {
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        head = tail = NULL;
    }
    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void push_back(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode-> prev = tail;
            tail = newNode;
        }
    }
    void pop_front() {
        Node* temp = head;
        if(head == NULL) return;
        head = head-> next;
        if(head->next == NULL) {
            delete head;
            head = tail = NULL;
            return;
        }
        if(head != NULL) {
            head->prev = NULL;
        }
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
        Node* temp = tail;
        tail = tail->prev;
        if(head != NULL) {
            tail->next = NULL;
        }
        temp->prev = NULL;
        delete temp;
    }
    void print() { 
        if(head == NULL) {
            cout << "Doubly Linked List is Empty!" << endl;
            return;
        }
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " <=>" << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main() {
    DoublyLinkedList DLL;
    DLL.push_front(30);
    DLL.push_front(20);
    DLL.push_front(10);
    DLL.push_back(40);
    DLL.push_back(50);
    cout << "List :" << endl;
    DLL.print();
    DLL.pop_front();
    DLL.pop_back();
    cout << "Final List :" << endl;
    DLL.print();
}