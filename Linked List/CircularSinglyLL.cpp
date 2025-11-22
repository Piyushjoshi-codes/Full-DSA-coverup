#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
class SinglyLinkedList{
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
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail-> next = head;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;

        }
    }
    void pop_front() {
        if(head == NULL) {
            cout << " Circular Singly-Linked List is Empty.\n";
            return;
        }
        else if(head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }
    void pop_back() {
        if(head == NULL) {
            cout << "Circular Singly-Linked List is Empty.\n";
            return;
        } else if(head == tail ) {
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = tail;
            Node* prev = head;
            while(prev->next != tail) {
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }
    void print(){
        if(head == NULL) return;
        cout << head->data << " -> ";
        Node* temp = head->next;
        while(temp != head) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << head->data << endl;
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