#include<iostream>
#include<list>
using namespace std;
int main() {
    list<int> SLL;
    SLL.push_front(3);
    SLL.push_front(2);
    SLL.push_front(1);
    SLL.push_back(4);
    SLL.push_back(5);
    cout << "List: ";
    for(int x : SLL) cout << x << " -> ";
    cout << "The Linked List is Empty!" << endl;
    SLL.pop_front();
    SLL.pop_back();
    cout << "Final List: ";
    for(int x : SLL) cout << x << " -> ";
    cout << "The Linked List is Empty!" << endl;
    return 0;
}