#include<iostream>
using namespace std;
struct Node {
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};
struct Polynomial {
    Node* head;
    Polynomial() {
        head = NULL;
    }
    void insert(int coeff, int pow) {
        Node* newNode = new Node(coeff, pow);
        if(head == NULL or pow > head->pow) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL && temp->next->pow >= pow) {
            temp = temp->next;
        }
        if(temp->pow == pow) {
            temp->coeff += coeff;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void display() {
        if(head == NULL) {
            cout << "0" << endl;
            return;
        }
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->coeff << "x^" << temp->pow;
            temp = temp->next;

            if(temp != NULL) cout << " + ";
        }
        cout << endl;
    }
Polynomial add(Polynomial &P) {
    Polynomial result;
    Node* t1 = head;
    while(t1 != NULL) {
        result.insert(t1->coeff, t1->pow);
        t1 = t1->next;
    }
    Node* t2 = P.head;
    while(t2 != NULL) {
        result.insert(t2->coeff, t2->pow);
        t2 = t2->next;
    }

    return result;
}
Polynomial subtract(Polynomial &P) {
    Polynomial result;
    Node* t1 = head;
    while(t1 != NULL) {
        result.insert(t1->coeff, t1->pow);
        t1 = t1->next;
    }
    Node* t2 = P.head;
    while(t2 != NULL) {
        result.insert(-t2->coeff, t2->pow); 
        t2 = t2->next;
    }
    return result;
}
Polynomial multiply(Polynomial &P) {
    Polynomial result;
    Node* t1 = head;
    while(t1 != NULL) {
        Node* t2 = P.head;
        while(t2 != NULL) {
            int newCoeff = t1->coeff * t2->coeff;
            int newPow   = t1->pow + t2->pow;
            result.insert(newCoeff, newPow); 
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return result;
}
};
int main() {
    Polynomial P1, P2, P3;
    P1.insert(9,4);
    P1.insert(7,3);
    P1.insert(5,2);
    P1.insert(3,1);
    P1.insert(1,0);
    P1.display();
    P2.insert(10,4);
    P2.insert(8,3);
    P2.insert(6,2);
    P2.insert(4,1);
    P2.insert(2,0);
    P2.display();
    P3 = P1.add(P2);
    cout << "Addition: ";
    P3.display();
    P3 = P1.subtract(P2);
    cout << "Subtraction: ";
    P3.display();
    P3 = P1.subtract(P2);
    cout << "Multiplication: ";
    P3.display();
    return 0;
}