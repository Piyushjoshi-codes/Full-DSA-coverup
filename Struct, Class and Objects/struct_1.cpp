#include <iostream>
#include<string>
using namespace std;
struct date {
    int day;
    string month;
    int year;
};
struct Book_list {
    string name, author;
    float price;
    date publ_date;
};
int main() {
    Book_list A = {"COSMOS", "Carl Sagan", 135.4, 1, "Jan", 2010};
    Book_list B = {"Astrophysics for people in hurry", "Neil DeGrasson", 18.95, 2, "May", 2017};
    cout << "Information of the Book :\n\n";
    cout << "Name of the Book : " << A.name << endl;
    cout << "Name of the Author : " << A.author<< endl;
    cout << "Price of the Book : $" << A.price << endl;
    cout << "Date of Publication : " << A.publ_date.day << " " << A.publ_date.month << " " << A.publ_date.year << " " << endl;
    cout << endl;
    cout << "Name of the Book : " << B.name << endl;
    cout << "Name of the Author : " << B.author<< endl;
    cout << "Price of the Book : $" << B.price << endl;
    cout << "Date of Publication : " << B.publ_date.day << " " << B.publ_date.month << " " << B.publ_date.year << " " << endl;
    return 0;
}