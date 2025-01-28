#include <iostream>
#include <string>
using namespace std;

// Class for Student Information
class Student {
private:
    string name;
    int rollNumber;
    string course;
    double marks;

public:
    // Constructor
    Student(string n = "", int roll = 0, string c = "", double m = 0.0) {
        name = n;
        rollNumber = roll;
        course = c;
        marks = m;
    }

    // Function to add student details
    void addStudentDetails(string n, int roll, string c, double m) {
        name = n;
        rollNumber = roll;
        course = c;
        marks = m;
    }

    // Function to display student details
    void displayStudentDetails() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
    }

    // Getter for roll number
    int getRollNumber() const {
        return rollNumber;
    }
};

// Class to manage multiple students
class StudentManagement {
private:
    Student students[10]; // Array to store multiple students
    int studentCount;

public:
    // Constructor
    StudentManagement() : studentCount(0) {}

    // Function to add a new student
    void addStudent() {
        if (studentCount < 10) {
            string name, course;
            int roll;
            double marks;
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter roll number: ";
            cin >> roll;
            cout << "Enter course: ";
            cin >> course;
            cout << "Enter marks: ";
            cin >> marks;

            students[studentCount].addStudentDetails(name, roll, course, marks);
            studentCount++;
            cout << "Student added successfully!" << endl;
        } else {
            cout << "Cannot add more students. Limit reached!" << endl;
        }
    }

    // Function to search for a student by roll number
    void findStudent(int roll) const {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getRollNumber() == roll) {
                students[i].displayStudentDetails();
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    // Function to display all student details
    void displayAllStudents() const {
        for (int i = 0; i < studentCount; i++) {
            students[i].displayStudentDetails();
            cout << "-----------------------" << endl;
        }
    }
};

int main() {
    StudentManagement management;
    int choice, roll;

    while (true) {
        cout << "\nStudent Management System\n";
        cout << "1. Add New Student\n";
        cout << "2. Search Student by Roll Number\n";
        cout << "3. Display All Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                management.addStudent();
                break;
            case 2:
                cout << "Enter roll number to search: ";
                cin >> roll;
                management.findStudent(roll);
                break;
            case 3:
                management.displayAllStudents();
                break;
            case 4:
                cout << "Exiting the Student Management System!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
