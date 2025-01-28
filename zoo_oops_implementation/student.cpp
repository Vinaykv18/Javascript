#include <iostream>
#include <vector>
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
    // Default Constructor
    Student() {
        rollNo = 0;
        name = "";
        age = 0;
        course = "";
    }

    // Parameterized Constructor
    Student(int rollNo, string name, int age, string course) {
        this->rollNo = rollNo;
        this->name = name;
        this->age = age;
        this->course = course;
    }

    // Method to display student details
    void displayInfo() const {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Course: " << course << endl;
        cout << "-------------------------" << endl;
    }

    // Getters
    int getRollNo() const { return rollNo; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getCourse() const { return course; }

    // Setters
    void setRollNo(int rollNo) { this->rollNo = rollNo; }
    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setCourse(string course) { this->course = course; }
};

// Class to manage multiple students
class StudentManagement {
private:
    vector<Student> students;

public:
    // Method to add a student
    void addStudent(int rollNo, string name, int age, string course) {
        Student student(rollNo, name, age, course);
        students.push_back(student);
    }

    // Method to display all students
    void displayAllStudents() const {
        for (const auto &student : students) {
            student.displayInfo(); // Corrected line
        }
    }

    // Method to find a student by roll number
    void findStudentByRollNo(int rollNo) const {
        for (const auto &student : students) {
            if (student.getRollNo() == rollNo) {
                student.displayInfo();
                return;
            }
        }
        cout << "Student with Roll Number " << rollNo << " not found." << endl;
    }
};

int main() {
    StudentManagement sm;

    // Adding students
    sm.addStudent(101, "Alice", 20, "Computer Science");
    sm.addStudent(102, "Bob", 21, "Mechanical Engineering");
    sm.addStudent(103, "Charlie", 22, "Electrical Engineering");

    // Display all students
    cout << "All Students Information:" << endl;
    sm.displayAllStudents();

    // Find a student by roll number
    cout << "Finding Student with Roll Number 102:" << endl;
    sm.findStudentByRollNo(102);

    return 0;
}


// https://chatgpt.com/share/671e8f49-28cc-8011-9fd0-3c797e9eae1e