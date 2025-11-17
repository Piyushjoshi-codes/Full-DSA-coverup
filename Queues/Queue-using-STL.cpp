#include<iostream>
#include<queue>
using namespace std;
int main() {
    queue<int> qq;
    qq.push(10);
    qq.push(20);
    qq.push(30);
    cout << "Queue" << endl;
    while (!qq.empty()) {
        cout << qq.front() << " ";
        qq.pop();
    }
    cout << "\n";
    return 0;
}