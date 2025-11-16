#include<iostream>
using namespace std;
int main() {
    int arr1[3][3];
    int arr2[3][3];
    int arr3[3][3];
    int option;
    cout << "Enter values for Array 1: \n";
    for(int i = 0; i < 3; i++) {
        for( int j = 0; j < 3; j++) {
            cin >> arr1[i][j];
        }
    }
    cout << "Enter values for Array 2: \n";
    for(int i = 0; i < 3; i++) {
        for( int j = 0; j < 3; j++) {
            cin >> arr2[i][j];
        }
    }
    cout << "Array 1 :\n";
    for(int i = 0; i < 3; i++) {
        for( int j = 0; j < 3; j++) {
            cout << arr1[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Array 2 :\n";
    for(int i = 0; i < 3; i++) {
        for( int j = 0; j < 3; j++) {
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Enter the correct number for operation given below :" << endl;
    cout << "Addition -> 1\n";
    cout << "Subtraction -> 2\n";
    cout << "Multiplication -> 3\n";
    cin >> option;
    switch (option)
    {
    case 1:
    cout << "Addition : \n";
    for(int i = 0; i < 3; i++) {
        for( int j = 0; j < 3; j++) {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    break;
    case 2:
    cout << "Subtraction : \n";
    for(int i = 0; i < 3; i++) {
        for( int j = 0; j < 3; j++) {
            arr3[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    break;
    case 3:
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr3[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    break;
    default:
    cout << "Written number is Invalid" << endl;
    cout << "Please try again later";
    break;
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr3[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}