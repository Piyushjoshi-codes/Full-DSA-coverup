#include<iostream>
#include<queue>
using namespace std;
int main() {
    queue<int> qq;

    //Insertion on the rear end..
    qq.push(10);
    qq.push(20);
    qq.push(30);
    cout << "Original size of the queue : ";
    cout << qq.size();
    cout << "Queue" << endl;
    while (!qq.empty()) {
        cout << qq.front() << " ";

        //Deletion at the front end..
        qq.pop();
    }
    cout << "\n";
    cout << "Final size of the queue : ";
    cout << qq.size();
    return 0;
}

//Insertion and deletion takes place on the rear and front end respectively...
//Thus A queue is a linear data structure with such properties... 