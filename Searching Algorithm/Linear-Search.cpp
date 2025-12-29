//linear search in c++
#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index if the key is found
        }
    }
    return -1; // Return -1 if the key is not found
}
int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = 10;
    int key = 50;
    cout << "List: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nKey selected: " << key << endl;

    int result = linearSearch(arr, n, key);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}