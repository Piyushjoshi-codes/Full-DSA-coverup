#include<iostream>
using namespace std;
int main() {
    int arr1[3][3];
    cout << "Enter the values for the Matrix :\n";
    for(int i = 0; i < 3; i++) {
        for( int j = 0; j < 3; j++) {
            cin >> arr1[3][3];
        }
    }
    cout << "Matrix :\n";
    for(int i = 0; i < 3; i++) {
        for( int j = 0; j < 3; j++) {
            cout << arr1[3][3] << "\t"; 
        }
        cout << endl;
    }
    cout << "Transpose of Matrix :" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr1[j][i];
        }
    }
}