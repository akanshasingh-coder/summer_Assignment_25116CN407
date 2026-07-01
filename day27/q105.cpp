//wap to create student record management system
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Class representing a single Student
class Student {
private:
    int rollNumber;
    string name;
    int age;
    string course;

public:
    // Constructor
    Student(int r, string n, int a, string c) {
        rollNumber = r;
        name = n;
        age = a;
        course = c;
    }

    // Getters
    int getRollNumber() const { return rollNumber; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getCourse() const { return course; }

    // Setters for updating records
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setCourse(string c) { course = c; }

    // Helper to display a single student's row
    void displayRow() const {
        cout << left << setw(12) << rollNumber 
             << setw(25) << name 
             << setw(8) << age 
             << setw(15) << course << endl;
    }
};

// Class handling management operations
class StudentManagementSystem {
private:
    vector<Student> students;

    // Helper to find a student index by Roll Number
    int findStudentIndex(int roll) {
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].getRollNumber() == roll) {
                return i;
            }
        }
        return -1; // Not found
    }

public:
    // 1. Add a new record
    void addStudent() {
        int roll, age;
        string name, course;

        cout << "\n--- Add New Student Record ---\n";
        cout << "Enter Roll Number: ";
        cin >> roll;

        // Check for duplicates
        if (findStudentIndex(roll) != -1) {
            cout << "❌ Error: Student with Roll Number " << roll << " already exists!\n";
            return;
        }

        cin.ignore(); // Clear input buffer
        cout << "Enter Full Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Course: ";
        getline(cin, course);

        students.push_back(Student(roll, name, age, course));
        cout << "✅ Record added successfully!\n";
    }

    // 2. Display all records
    void viewAllStudents() {
        if (students.empty()) {
            cout << "\n🚫 No student records found.\n";
            return;
        }

        cout << "\n------------------------------------------------------------\n";
        cout << left << setw(12) << "Roll No" << setw(25) << "Name" << setw(8) << "Age" << setw(15) << "Course" << endl;
        cout << "------------------------------------------------------------\n";
        for (const auto& student : students) {
            student.displayRow();
        }
        cout << "------------------------------------------------------------\n";
    }

    // 3. Search record by roll number
    void searchStudent() {
        if (students.empty()) {
            cout << "\n🚫 Database is empty.\n";
            return;
        }

        int roll;
        cout << "\nEnter Roll Number to search: ";
        cin >> roll;

        int index = findStudentIndex(roll);
        if (index != -1) {
            cout << "\n🔍 Record Found:\n";
            cout << "------------------------------------------------------------\n";
            cout << left << setw(12) << "Roll No" << setw(25) << "Name" << setw(8) << "Age" << setw(15) << "Course" << endl;
            cout << "------------------------------------------------------------\n";
            students[index].displayRow();
            cout << "------------------------------------------------------------\n";
        } else {
            cout << "❌ Record not found for Roll Number " << roll << endl;
        }
    }

    // 4. Update an existing record
    void updateStudent() {
        if (students.empty()) {
            cout << "\n🚫 Database is empty.\n";
            return;
        }

        int roll;
        cout << "\nEnter Roll Number to update: ";
        cin >> roll;

        int index = findStudentIndex(roll);
        if (index == -1) {
            cout << "❌ Record not found!\n";
            return;
        }

        string newName, newCourse;
        int newAge;

        cin.ignore();
        cout << "Enter New Name (Leave blank to keep old): ";
        getline(cin, newName);
        if (!newName.empty()) students[index].setName(newName);

        cout << "Enter New Age (Enter 0 to keep old): ";
        cin >> newAge;
        if (newAge > 0) students[index].setAge(newAge);

        cin.ignore();
        cout << "Enter New Course (Leave blank to keep old): ";
        getline(cin, newCourse);
        if (!newCourse.empty()) students[index].setCourse(newCourse);

        cout << "✅ Record updated successfully!\n";
    }

    // 5. Delete a record
    void deleteStudent() {
        if (students.empty()) {
            cout << "\n🚫 Database is empty.\n";
            return;
        }

        int roll;
        cout << "\nEnter Roll Number to delete: ";
        cin >> roll;

        int index = findStudentIndex(roll);
        if (index == -1) {
            cout << "❌ Record not found!\n";
            return;
        }

        students.erase(students.begin() + index);
        cout << "🗑️ Record deleted successfully!\n";
    }
};

// Main execution function
int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\n==================================\n";
        cout << " STUDENT RECORD MANAGEMENT SYSTEM \n";
        cout << "==================================\n";
        cout << "1. Add Student Record\n";
        cout << "2. View All Student Records\n";
        cout << "3. Search Student Record\n";
        cout << "4. Update Student Record\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Exit\n";
        cout << "----------------------------------\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: sms.addStudent(); break;
            case 2: sms.viewAllStudents(); break;
            case 3: sms.searchStudent(); break;
            case 4: sms.updateStudent(); break;
            case 5: sms.deleteStudent(); break;
            case 6: cout << "\n👋 Exiting program. Goodbye!\n"; break;
            default: cout << "\n⚠️ Invalid choice! Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
