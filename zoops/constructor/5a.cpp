#include <iostream>
#include <string>
using namespace std;

// Student class to store student information
class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    // Constructor to initialize a student
    Student() {
        // name = "";
        // rollNumber = 0;
        // marks = 0.0;
    }

    // Function to input student details
    void inputDetails() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);  // To accept multi-word names
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    // Function to display student details
    void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    int numberOfStudents;

    // Ask for the number of students
    cout << "Enter number of students: ";
    cin >> numberOfStudents;

    // Dynamically create an array of Student objects
    Student students[numberOfStudents];
    //Student* students = new Student[numberOfStudents];

    // Input details for each student
    for (int i = 0; i < numberOfStudents; i++) {
        cout << "Enter details for student " << i + 1 << ":\n";
        students[i].inputDetails();
    }

    // Display details for each student
    cout << "\nDisplaying student details:\n";
    for (int i = 0; i < numberOfStudents; i++) {
        cout << "\nDetails of student " << i + 1 << ":\n";
        students[i].displayDetails();
    }

    // Free dynamically allocated memory
   // delete[] students;

    return 0;
}
