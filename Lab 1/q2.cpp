#include <iostream>
#include <cstring>
using namespace std;

class Exam {
private:
    char* name;
    char* edate;
    double score;
public:
    Exam(const char* n = "", const char* date = "", double s = 0.0) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        edate = new char[strlen(date) + 1];
        strcpy(edate, date);
        score = s;
    }

    // Destructor
    ~Exam() {
        delete[] name;
        delete[] edate;
    }

    void setname(const char* n) {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    void setedate(const char* date) {
        delete[] edate;
        edate = new char[strlen(date) + 1];
        strcpy(edate, date);
    }

    void setScore(double s) {
        score = s;
    }

    void display() const {
        cout << "Student's Name: " << name << endl;
        cout << "Exam Date: " << edate << endl;
        cout << "Score: " << score << endl;
    }
    // User-defined copy constructor (deep copy)
    Exam(const Exam& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        edate = new char[strlen(other.edate) + 1];
        strcpy(edate, other.edate);
        score = other.score;
    }

    // User-defined copy assignment operator (deep copy)
    Exam& operator=(const Exam& other) {
        if (this != &other) {
            delete[] name;
            delete[] edate;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            edate = new char[strlen(other.edate) + 1];
            strcpy(edate, other.edate);
            score = other.score;
        }
        return *this;
    }
};

int main() {
    Exam e1("Ilsa", "2025-08-23", 95.5);
    cout << "Original exam-1 details:" << endl;
    e1.display();

    // Shallow copy (default copy constructor)
    Exam e2 = e1;
    cout << "\nShallow copied exam-2 details:" << endl;
    e2.display();

    // Modify e2's name and date
    e2.setname("Izza");
    e2.setedate("2025-09-01");
    e2.setScore(97.2);

    cout << "\nAfter modifying exam2:" << endl;
    e2.display();

    cout << "\nCheck exam1 details after modifying exam2:" << endl;
    e1.display();

    // Both exam1 and exam2 will try to delete the same memory, causing undefined behavior
    return 0;
}