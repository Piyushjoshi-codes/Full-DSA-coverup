#include <iostream>
#include <string>
using namespace std;
template <class T>
class Student {
private:
    string name;
    T totalMarks;
    float cgpa;
    string result;

public:
    Student(string n, T m, float c) {
        name = n;
        totalMarks = m;
        cgpa = c;
        result = (cgpa >= 4.0) ? "PASS" : "FAIL";

        cout << "\n--- Student Record Found ---\n";
        cout << "Name      : " << name << endl;
        cout << "Total Marks: " << totalMarks << endl;
        cout << "CGPA      : " << cgpa << endl;
        cout << "Result    : " << result << endl;
    }
    ~Student() {
        cout << "\nRecord closed for " << name << endl;
    }
};

int main() {
    string names[3] = {"Naruto", "Sasuke", "Sakura"};
    int marks[3]    = {450, 480, 400};
    float cgpas[3]  = {7.8, 8.9, 6.5};

    string userName;
    cout << "Enter student name: ";
    getline(cin, userName);

    bool found = false;

    for (int i = 0; i < 3; i++) {
        if (userName == names[i]) {
            Student<int> s(names[i], marks[i], cgpas[i]);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nNo record found for '" << userName << "'.\n";
    }

    return 0;
}
