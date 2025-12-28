#include <iostream>
#include <string>
using namespace std;

class Date {
public:
    int day;
    string month;
    int year;

    Date() {}

    Date(int d, string m, int y) {
        day = d;
        month = m;
        year = y;
    }
};

class Musicdata {
private:
    string song_name;
    string singer;
    string genre;
    float avg_rating;
    Date rel_date;

public:
    Musicdata(string s, string sing, string g, float a, Date r) {
        song_name = s;
        singer = sing;
        genre = g;
        avg_rating = a;
        rel_date = r;  
    }
    void display() {
        cout << "-----Music Dataset-----" << endl;
        cout << "Name of the song: " << song_name << endl;
        cout << "Name of the singer: " << singer << endl;
        cout << "Genre: " << genre << endl;
        cout << "Average rating: " << avg_rating << endl;
        cout << "Release date: " << rel_date.day << "-" << rel_date.month << "-" << rel_date.year << endl;
        cout << endl;   
    }
};

int main() {
    Date d1(29, "November", 2019);
    Date d2(6, "January", 2017);

    Musicdata M1("Blinding Lights", "The Weeknd", "Synth-pop", 4.7, d1);
    Musicdata M2("Shape of you", "Ed Sheeren", "pop", 4.6, d2);

    M1.display();
    M2.display();
    
    return 0;
}