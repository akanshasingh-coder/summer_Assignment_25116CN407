//wap to create marksheet generation system
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Class to handle individual student marksheet details
class Student {
private:
    string name;
    int rollNumber;
    int mathMarks;
    int scienceMarks;
    int englishMarks;
    int totalMarks;
    double percentage;
    char grade;

    // Internal helper function to calculate percentage and assign grades
    void calculateResults() {
        totalMarks = mathMarks + scienceMarks + englishMarks;
        percentage = (totalMarks / 300.0) * 100;

        if (percentage >= 90) grade = 'A';
        else if (percentage >= 75) grade = 'B';
        else if (percentage >= 50) grade = 'C';
        else if (percentage >= 35) grade = 'D';
        else grade = 'F'; // Fail condition
    }

public:
    // Function to take user inputs safely
    void inputDetails() {
        cout << "\nEnter Student Name: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Enter Roll Number: ";
        cin >> rollNumber;

        // Input validation loop for marks
        do {
            cout << "Enter Mathematics Marks (0-100): ";
            cin >> mathMarks;
        } while (mathMarks < 0 || mathMarks > 100);

        do {
            cout << "Enter Science Marks (0-100): ";
            cin >> scienceMarks;
        } while (scienceMarks < 0 || scienceMarks > 100);

        do {
            cout << "Enter English Marks (0-100): ";
            cin >> englishMarks;
        } while (englishMarks < 0 || englishMarks > 100);

        calculateResults();
    }

    // Function to generate the formatted marksheet output
    void displayMarksheet() const {
        cout << "\n==========================================";
        cout << "\n           OFFICIAL MARKSHEET             ";
        cout << "\n==========================================";
        cout << "\n Name: " << left << setw(20) << name << " Roll No: " << rollNumber;
        cout << "\n------------------------------------------";
        cout << "\n Subject          | Max Marks | Obt Marks ";
        cout << "\n------------------------------------------";
        cout << "\n Mathematics      |    100    |    " << mathMarks;
        cout << "\n Science          |    100    |    " << scienceMarks;
        cout << "\n English          |    100    |    " << englishMarks;
        cout << "\n------------------------------------------";
        cout << "\n TOTAL MARKS: " << totalMarks << "/300";
        cout << "\n PERCENTAGE:  " << fixed << setprecision(2) << percentage << "%";
        cout << "\n FINAL GRADE: " << grade;
        cout << "\n STATUS:      " << (grade == 'F' ? "FAILED" : "PASSED");
        cout << "\n==========================================\n";
    }

    // Getter function for search verification
    int getRollNumber() const {
        return rollNumber;
    }
};

// Main controller loop
int main() {
    vector<Student> database;
    int choice;

    while (true) {
        cout << "\n=== MARKSHEET GENERATION SYSTEM ===";
        cout << "\n1. Add New Student Record";
        cout << "\n2. Display All Marksheets";
        cout << "\n3. Search Marksheet by Roll No";
        cout << "\n4. Exit";
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            s.inputDetails();
            database.push_back(s);
            cout << "\nRecord saved successfully!\n";
        } 
        else if (choice == 2) {
            if (database.empty()) {
                cout << "\nNo records found in the database.\n";
            } else {
                for (const auto& student : database) {
                    student.displayMarksheet();
                }
            }
        } 
        else if (choice == 3) {
            if (database.empty()) {
                cout << "\nDatabase is empty.\n";
            } else {
                int searchRoll;
                bool found = false;
                cout << "\nEnter Roll Number to search: ";
                cin >> searchRoll;

                for (const auto& student : database) {
                    if (student.getRollNumber() == searchRoll) {
                        student.displayMarksheet();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "\nStudent with Roll Number " << searchRoll << " not found.\n";
                }
            }
        } 
        else if (choice == 4) {
            cout << "\nExiting System. Goodbye!\n";
            break;
        } 
        else {
            cout << "\nInvalid selection. Try again.\n";
        }
    }
    return 0;
}
