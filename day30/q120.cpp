//wap to develop complete mini project using arrays, strings and functions
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


const int MAX_STUDENTS = 100;


void displayMenu();
void addStudent(int rollNumbers[], string names[], double gpas[], int& studentCount);
void displayStudents(const int rollNumbers[], const string names[], const double gpas[], int studentCount);
void searchStudent(const int rollNumbers[], const string names[], const double gpas[], int studentCount);
void updateGPA(int rollNumbers[], double gpas[], int studentCount);

int main() {
   
    int rollNumbers[MAX_STUDENTS];
    string names[MAX_STUDENTS];
    double gpas[MAX_STUDENTS];
    
    int studentCount = 0; 
    int choice;

    cout << "=========================================\n";
    cout << "   Welcome to Student Management System  \n";
    cout << "=========================================\n";

    do {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        
        
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cin.ignore(); 

        switch (choice) {
            case 1:
                addStudent(rollNumbers, names, gpas, studentCount);
                break;
            case 2:
                displayStudents(rollNumbers, names, gpas, studentCount);
                break;
            case 3:
                searchStudent(rollNumbers, names, gpas, studentCount);
                break;
            case 4:
                updateGPA(rollNumbers, gpas, studentCount);
                break;
            case 5:
                cout << "\nExiting program. Thank you!\n";
                break;
            default:
                cout << "\nInvalid choice! Please select an option between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}


void displayMenu() {
    cout << "\n-----------------------------------------\n";
    cout << "1. Add New Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student by Roll Number\n";
    cout << "4. Update Student GPA\n";
    cout << "5. Exit Project\n";
    cout << "-----------------------------------------\n";
}


void addStudent(int rollNumbers[], string names[], double gpas[], int& studentCount) {
    if (studentCount >= MAX_STUDENTS) {
        cout << "\nError: System database is full!\n";
        return;
    }

    cout << "\nEnter Roll Number: ";
    cin >> rollNumbers[studentCount];
    cin.ignore(); 

    cout << "Enter Student Name: ";
    getline(cin, names[studentCount]); 

    cout << "Enter Student GPA (0.0 - 4.0): ";
    cin >> gpas[studentCount];


    while (gpas[studentCount] < 0.0 || gpas[studentCount] > 4.0) {
        cout << "Invalid GPA. Enter again (0.0 - 4.0): ";
        cin >> gpas[studentCount];
    }

    studentCount++; 
    cout << "\nStudent record added successfully!\n";
}


void displayStudents(const int rollNumbers[], const string names[], const double gpas[], int studentCount) {
    if (studentCount == 0) {
        cout << "\nNo records found. The database is empty.\n";
        return;
    }

    cout << "\n==================================================\n";
    cout << left << setw(12) << "Roll No" << setw(25) << "Name" << setw(10) << "GPA" << "\n";
    cout << "==================================================\n";

    for (int i = 0; i < studentCount; i++) {
        cout << left << setw(12) << rollNumbers[i] 
             << setw(25) << names[i] 
             << setw(10) << fixed << setprecision(2) << gpas[i] << "\n";
    }
    cout << "==================================================\n";
}


void searchStudent(const int rollNumbers[], const string names[], const double gpas[], int studentCount) {
    if (studentCount == 0) {
        cout << "\nDatabase is empty. Nothing to search.\n";
        return;
    }

    int targetRoll;
    cout << "\nEnter Roll Number to search: ";
    cin >> targetRoll;

    for (int i = 0; i < studentCount; i++) {
        if (rollNumbers[i] == targetRoll) {
            cout << "\nStudent Found:\n";
            cout << "-----------------------\n";
            cout << "Roll Number: " << rollNumbers[i] << "\n";
            cout << "Name:        " << names[i] << "\n";
            cout << "GPA:         " << fixed << setprecision(2) << gpas[i] << "\n";
            return; 
        }
    }
    cout << "\nStudent with Roll Number " << targetRoll << " not found.\n";
}


void updateGPA(int rollNumbers[], double gpas[], int studentCount) {
    if (studentCount == 0) {
        cout << "\nDatabase is empty. No records to update.\n";
        return;
    }

    int targetRoll;
    cout << "\nEnter Roll Number to update GPA: ";
    cin >> targetRoll;

    for (int i = 0; i < studentCount; i++) {
        if (rollNumbers[i] == targetRoll) {
            double newGpa;
            cout << "Current GPA: " << gpas[i] << "\n";
            cout << "Enter New GPA (0.0 - 4.0): ";
            cin >> newGpa;

            while (newGpa < 0.0 || newGpa > 4.0) {
                cout << "Invalid GPA. Enter again (0.0 - 4.0): ";
                cin >> newGpa;
            }

            gpas[i] = newGpa;
            cout << "\nGPA updated successfully!\n";
            return;
        }
    }
    cout << "\nStudent with Roll Number " << targetRoll << " not found.\n";
}
