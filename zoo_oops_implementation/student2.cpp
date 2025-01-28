#include <iostream>
#include <string>
using namespace std;

// Class to store student details
class Student {
private:
    int rollNo;
    string name;
    int age;
    string course;

public:
    // Default constructor
    Student() {}

    // Parameterized constructor
    Student(int rollNo, string name, int age, string course) {
        this->rollNo = rollNo;
        this->name = name;
        this->age = age;
        this->course = course;
    }

    // Method to display student details
    void displayInfo() {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Course: " << course << endl;
        cout << "-------------------------" << endl;
    }

    // Method to set student details
    void setStudentDetails(int rollNo, string name, int age, string course) {
        this->rollNo = rollNo;
        this->name = name;
        this->age = age;
        this->course = course;
    }

    int getRollNo() { return rollNo; }
};

int main() {
    int numberOfStudents;

    // Ask user how many students they want to add
    cout << "Enter the number of students: ";
    cin >> numberOfStudents;

    // Create an array of Student objects
    Student students[numberOfStudents];

    // Input details for each student
    for (int i = 0; i < numberOfStudents; i++) {
        int rollNo, age;
        string name, course;

        cout << "Enter details for student " << (i + 1) << ":\n";
        cout << "Roll Number: ";
        cin >> rollNo;
        cout << "Name: ";
        cin.ignore(); // To handle newline character from previous input
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cout << "Course: ";
        cin.ignore();
        getline(cin, course);

        // Set details using setter method
        students[i].setStudentDetails(rollNo, name, age, course);
    }

    // Display all students
    cout << "\nAll Students Information:\n";
    for (int i = 0; i < numberOfStudents; i++) {
        students[i].displayInfo();
    }

    return 0;
}
