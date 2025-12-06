#include<iostream>
#include<deque>
using namespace std;
int main() {
    deque<int> dqq;

    //performing insertion by using buit-in push_front() and push-back() functions in STL..
    dqq.push_front(20);
    dqq.push_front(10);
    dqq.push_back(30);
    dqq.push_back(40);
    cout << "Deque List :" << endl;
    for(int i : dqq) cout << i << "\t";
    cout << "\nOrginal size of the Deque : " << dqq.size();
    cout << "\n";

    //Performing deletion by using pop_front() and pop-back()..
    dqq.pop_front();
    dqq.pop_back();
    
    //After deleting first and last elemnts of the list..
    cout << "Deque Final List :" << endl;
    for(int i : dqq) cout << i << "\t";
    cout << "\nFinal size of the Deque : " << dqq.size();
    cout << "\n";
    return 0;
}

// We were able to use these insertion and deletion functions working at both ends of a deque as 
// a deque is defined to be a Double-ended queue that allows both insertion and deletion and  both front and 
// rear end.... 