#include <iostream>
using namespace std;
int main() {
    int a = 10, b = 20, c = 30;
    int* arr[3]; // Array of integer pointers

    arr[0] = &a; // Pointing to variable a
    arr[1] = &b; // Pointing to variable b
    arr[2] = &c; // Pointing to variable c

    // Accessing values using the pointer array
    for (int i = 0; i < 3; i++) {
        cout << "Value at arr[" << i << "] = " << *(arr[i]) << endl;
    }
    
    //Printing address stored in each memory location
    for (int i = 0; i < 3; i++) {
        cout << "Address stored in arr[" << i << "] = " << arr[i] << endl;
    }
    return 0;
}