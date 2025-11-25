#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> arr1;
    cout << "Size of array : " << arr1.size() << endl;
    arr1.push_back(10);
    arr1.push_back(20);
    arr1.push_back(30);
    arr1.push_back(40);
    cout << "Vector Elements: " << endl;
    for(int i = 0; i < 4; i++) {
        cout << arr1[i] << "\t";
    }
    cout << endl;
    cout << "Size of array : " << arr1.size() << endl;
    arr1.pop_back();
    arr1.pop_back();
    cout << "Final Vector Elements: " << endl;
    for(int i = 0; i < 4; i++) {
        cout << arr1[i] << "\t";
    }
    cout << endl;
    return 0;
}
