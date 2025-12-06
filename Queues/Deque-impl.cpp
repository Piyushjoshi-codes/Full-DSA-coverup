#include<iostream>
using namespace std;

//Creating a class Node inside which data and next pointer that are important for implementing deque as a 
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
//the deque..
class Queue_op {

    //important pointers required to store info of first and last elements..
    Node* front;
    Node* rear;
public:
    Queue_op() {
        front = rear = NULL;
    }
    
    //Insertion takes place at the front end..
    void push_front(int val) {
        Node* newNode = new Node(val);
        if(front == NULL) {
            front = rear = newNode;
            return;
        }
        newNode->next = front;
        front = newNode;
    }

    //Insertion takes place at the rear end.. 
    void push_back(int val) {
        Node* newNode = new Node(val);
        if(front == NULL) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    //Deletion takes place at the front end..
    void pop_front() {
        if(front == NULL) return;
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    //Deletion takes place at the rear end..
    void pop_back() {
        if(front == NULL) return;
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    //Finally printing the deque with two conditions..
    void print() {
        if(front == rear ) {
            cout << "The Deque is Empty";
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
    Queue_op DQ1;  

    //Insertion at the rear end of the deque..
    DQ1.push_front(13);
    DQ1.push_front(12);
    DQ1.push_front(11);
    DQ1.push_front(10);
    cout << "The Deque List after insertion at front end :  ";
    DQ1.print();
 
    //Inserting at the rear end of the deque..
    DQ1.push_back(14);
    DQ1.push_back(15);
    DQ1.push_back(16);
    DQ1.push_back(17);
    cout << "The Deque List after insertion at rear end :  ";
    DQ1.print();
    
    //Deletion at the front end of the deque..
    DQ1.pop_front();
    DQ1.pop_front();
    cout << "The Deque List after deletion at front end :  ";
    DQ1.print();

    //Deletion at the rear end of the deque..
    DQ1.pop_back();
    DQ1.pop_back();
    cout << "The Deque List after deletion at rear end :  ";
    DQ1.print();
}

//Deque is preferred over the queue as it gives flexibility over insertion as well as deletion on 
//both the ends of the list...