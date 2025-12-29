#include <iostream>
using namespace std;
class Demo {
public: 
    int x;
    
    //Constructor
    Demo() {
        x = 10;
        cout << "\n\nConstructor called, X = " << x << endl;
        cout << "Object initailized by allocating the memory.\n" << endl;
    }

    //Destructor
    ~Demo() {
        cout << "Destructor called." << endl;
        cout << "Released the memory occupied by the object.\n" << endl;
    }
};

int main() {
    cout << "Inside main function: " << endl;
    Demo d;     // Object created

    return 0;
}