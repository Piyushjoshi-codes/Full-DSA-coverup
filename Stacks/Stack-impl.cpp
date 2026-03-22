#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];   // fixed size stack
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Push
    void push(int x) {
        if (top == 99) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    // Pop
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    // Peek
    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    // isEmpty
    bool isEmpty() {
        return top == -1;
    }

    // Size
    int size() {
        return top + 1;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.peek() << endl;

    s.pop();

    cout << "Top after pop: " << s.peek() << endl;
    cout << "Size: " << s.size() << endl;

    return 0;
}