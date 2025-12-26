//Vector implementation in C++
#include <iostream>
using namespace std;
class Vector {
   private:
    int* arr;      // Pointer to the array
    int capacity;  // Maximum capacity of the vector
    int size;      // Current size of the vector

   public:
    // Constructor to initialize vector
    Vector(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    // Function to add an element at the end
    void push_back(int value) {
        if (size < capacity) {
            arr[size++] = value;
        } else {
            cout << "Vector is full!" << endl;
        }
    }

    // Function to get element at a specific index
    int get(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        } else {
            cout << "Index out of bounds!" << endl;
            return -1; // Return an invalid value
        }
    }

    // Function to get current size of the vector
    int getSize() {
        return size;
    }

    // Destructor to free allocated memory
    ~Vector() {
        delete[] arr;
    }
};
int main() {
    Vector vec(5); // Create a vector of capacity 5

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    cout << "Vector elements: ";
    for (int i = 0; i < vec.getSize(); i++) {
        cout << vec.get(i) << " ";
    }
    cout << endl;

    return 0;
}