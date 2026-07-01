//Write a program to Create student record system using array and strings
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


const int MAX_STUDENTS = 100;


struct Student {
    string id;
    string name;
    float gpa;
};


void addStudent(Student students[], int& currentCount);
void displayAllStudents(const Student students[], int currentCount);
void searchStudentByID(const Student students[], int currentCount);

int main() {
   
    Student studentDatabase[MAX_STUDENTS];
    int currentStudentCount = 0; 
    int userChoice;

    do {
        // Main Interface Menu
        cout << "\n====================================\n";
        cout << "    STUDENT RECORD SYSTEM (ARRAYS)  \n";
        cout << "====================================\n";
        cout << "1. Add New Student Record\n";
        cout << "2. Display All Student Records\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Exit System\n";
        cout << "------------------------------------\n";
        cout << "Enter your choice (1-4): ";
        cin >> userChoice;

        // Route selection to functional modules
        switch (userChoice) {
            case 1:
                addStudent(studentDatabase, currentStudentCount);
                break;
            case 2:
                displayAllStudents(studentDatabase, currentStudentCount);
                break;
            case 3:
                searchStudentByID(studentDatabase, currentStudentCount);
                break;
            case 4:
                cout << "\nExiting system. Goodbye!\n";
                break;
            default:
                cout << "\n[Error] Invalid choice! Please select between 1 and 4.\n";
        }
    } while (userChoice != 4);

    return 0;
}


void addStudent(Student students[], int& currentCount) {
    if (currentCount >= MAX_STUDENTS) {
        cout << "\n[Error] Database is full! Cannot add more students.\n";
        return;
    }

    Student newStudent;
    cout << "\nEnter Student ID: ";
    cin >> newStudent.id;
    
    
    cin.ignore(); 
    cout << "Enter Student Full Name: ";
    getline(cin, newStudent.name);
    
    cout << "Enter Student GPA (0.0 - 4.0): ";
    cin >> newStudent.gpa;

    
    students[currentCount] = newStudent;
    currentCount++; 
    
    cout << "\n[Success] Record added successfully!\n";
}


void displayAllStudents(const Student students[], int currentCount) {
    if (currentCount == 0) {
        cout << "\n[Info] The database is currently empty.\n";
        return;
    }

    cout << "\n----------------------------------------------------------\n";
    cout << left << setw(15) << "ID" << setw(30) << "Name" << setw(10) << "GPA" << endl;
    cout << "----------------------------------------------------------\n";
    
    for (int i = 0; i < currentCount; i++) {
        cout << left << setw(15) << students[i].id 
             << setw(30) << students[i].name 
             << setw(10) << fixed << setprecision(2) << students[i].gpa << endl;
    }
    cout << "----------------------------------------------------------\n";
}


void searchStudentByID(const Student students[], int currentCount) {
    if (currentCount == 0) {
        cout << "\n[Info] The database is empty. Nothing to search.\n";
        return;
    }

    string searchID;
    cout << "\nEnter Student ID to search: ";
    cin >> searchID;

    bool recordFound = false;
    for (int i = 0; i < currentCount; i++) {
        if (students[i].id == searchID) {
            cout << "\n[Record Found]\n";
            cout << "---------------------------\n";
            cout << "ID:   " << students[i].id << "\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "GPA:  " << fixed << setprecision(2) << students[i].gpa << "\n";
            cout << "---------------------------\n";
            recordFound = true;
            break; 
        }
    }

    if (!recordFound) {
        cout << "\n[Error] Student with ID '" << searchID << "' not found.\n";
    }
}

