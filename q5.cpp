#include <iostream>
using namespace std;

// Forward declaration of Teacher
class Teacher;

class Student {
private:
    string name;
    int grade1, grade2, grade3;

public:
    Student(string n, int g1, int g2, int g3) {
        name = n;
        grade1 = g1;
        grade2 = g2;
        grade3 = g3;
    }

    void displayGrades() {
        cout << "Grades for " << name << ": " 
             << grade1 << ", " << grade2 << ", " << grade3 << endl;
    }

    // Declare Teacher as friend class
    friend class Teacher;

    // Declare friend function
    friend double calculateAverageGrade(Student s);
};

class Teacher {
public:
    void updateGrade(Student& s, int gradeNumber, int newGrade) {
        switch (gradeNumber) {
            case 1: s.grade1 = newGrade; break;
            case 2: s.grade2 = newGrade; break;
            case 3: s.grade3 = newGrade; break;
            default: cout << "Invalid grade number!" << endl;
        }
    }
};

// Friend function to calculate average
double calculateAverageGrade(Student s) {
    return (s.grade1 + s.grade2 + s.grade3) / 3.0;
}

int main() {
    Student s1("Alice", 70, 85, 90);
    Teacher t1;

    cout << "Initial Grades:" << endl;
    s1.displayGrades();
    cout << "Average: " << calculateAverageGrade(s1) << endl;

    cout << "\nTeacher updates grade 1 to 95." << endl;
    t1.updateGrade(s1, 1, 95);

    cout << "\nUpdated Grades:" << endl;
    s1.displayGrades();
    cout << "New Average: " << calculateAverageGrade(s1) << endl;

    return 0;
}
