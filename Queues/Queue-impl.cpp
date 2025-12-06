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
            cout << "The Queue is Empty";
            return;
        }
        Node* temp = front;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
}; 
int main() {
    Queue_op Q1;  

    //Insertion at the rear end using push() function..
    Q1.push(10);
    Q1.push(11);
    Q1.push(12);
    Q1.push(13);
    cout << "The Original Queue List :  ";
    Q1.print();
 
    //Inserting at rear end of the Queue..
    Q1.push(14);
    Q1.push(15);
    cout << "The Queue List after insertion :  ";
    Q1.print();
     
    Q1.pop();
    Q1.pop();
    cout << "The Final Queue List after deletion :  ";
    Q1.print();
}