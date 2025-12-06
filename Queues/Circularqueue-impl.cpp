#include<iostream>
using namespace std;

//Creating a class Node inside which data and next pointer that are important for implementing queue as a 
//linked list..
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

//This section includes the actual operations to be performed that consists insertion, deletion and printing
//the Queue..
class Queue_op {

    //important pointers required to store info of first and last elements..
    Node* front;
    Node* rear;
public:
    Queue_op() {
        front = rear = NULL;
    }
    
    //Insertion takes place at the rear end.. 
    void push(int val) {
        Node* newNode = new Node(val);
        if(front == NULL) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    //Deletion takes place at the front end..
    void pop() {
        if(front == NULL) return;
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    void print() {
        if(front == rear ) {
            cout << "The Circular Queue is Empty";
            return;
        }
        Node* temp = front;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << front->data << "\n";
    }
}; 
int main() {
    Queue_op CQ1;  

    //Insertion at the rear end using push() function..
    CQ1.push(10);
    CQ1.push(11);
    CQ1.push(12);
    CQ1.push(13);
    cout << "The Circular Queue List :  ";
    CQ1.print();
 
    //Inserting at rear end of the Queue..
    CQ1.push(14);
    CQ1.push(15);
    cout << "The Circular Queue List after insertion :  ";
    CQ1.print();
     
    CQ1.pop();
    CQ1.pop();
    cout << "The Circular Queue List after deletion :  ";
    CQ1.print();
}