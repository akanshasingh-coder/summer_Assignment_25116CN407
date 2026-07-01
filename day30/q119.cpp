//wap to create mini employement management system
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;


class Employee {
private:
    int id;
    string name;
    string designation;
    double salary;

public:
   
    Employee(int empId, string empName, string empDesig, double empSalary) {
        id = empId;
        name = empName;
        designation = empDesig;
        salary = empSalary;
    }

    
    int getId() const { return id; }
    string getName() const { return name; }
    string getDesignation() const { return designation; }
    double getSalary() const { return salary; }

   
    void setName(string newName) { name = newName; }
    void setDesignation(string newDesig) { designation = newDesig; }
    void setSalary(double newSalary) { salary = newSalary; }

    
    void displayEmployeeRow() const {
        cout << left << setw(10) << id 
             << setw(25) << name 
             << setw(20) << designation 
             << "$" << fixed << setprecision(2) << salary << endl;
    }
};


class EmployeeManagementSystem {
private:
    vector<Employee> employees;

    
    int findEmployeeIndex(int id) {
        for (size_t i = 0; i < employees.size(); ++i) {
            if (employees[i].getId() == id) {
                return i;
            }
        }
        return -1; 
    }

public:
    
    void addEmployee() {
        int id;
        string name, designation;
        double salary;

        cout << "\n--- Add New Employee ---\n";
        cout << "Enter Employee ID (Integer): ";
        cin >> id;

        
        if (findEmployeeIndex(id) != -1) {
            cout << "Error: An employee with ID " << id << " already exists!\n";
            return;
        }

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Designation: ";
        getline(cin, designation);
        cout << "Enter Salary: ";
        cin >> salary;

        employees.push_back(Employee(id, name, designation, salary));
        cout << "Employee record added successfully!\n";
    }

    
    void displayAllEmployees() const {
        if (employees.empty()) {
            cout << "\nNo employee records found in the system.\n";
            return;
        }

        cout << "\n-----------------------------------------------------------------\n";
        cout << left << setw(10) << "ID" << setw(25) << "Name" << setw(20) << "Designation" << "Salary" << endl;
        cout << "-----------------------------------------------------------------\n";
        for (const auto& emp : employees) {
            emp.displayEmployeeRow();
        }
        cout << "-----------------------------------------------------------------\n";
    }


    void searchEmployee() {
        if (employees.empty()) {
            cout << "\nNo records available to search.\n";
            return;
        }

        int id;
        cout << "\nEnter Employee ID to search: ";
        cin >> id;

        int index = findEmployeeIndex(id);
        if (index != -1) {
            cout << "\nRecord Found:\n";
            cout << "-----------------------------------------------------------------\n";
            cout << left << setw(10) << "ID" << setw(25) << "Name" << setw(20) << "Designation" << "Salary" << endl;
            cout << "-----------------------------------------------------------------\n";
            employees[index].displayEmployeeRow();
            cout << "-----------------------------------------------------------------\n";
        } else {
            cout << "Employee with ID " << id << " not found.\n";
        }
    }

   
    void updateEmployee() {
        if (employees.empty()) {
            cout << "\nNo records available to update.\n";
            return;
        }

        int id;
        cout << "\nEnter Employee ID to update: ";
        cin >> id;

        int index = findEmployeeIndex(id);
        if (index == -1) {
            cout << "Employee with ID " << id << " not found.\n";
            return;
        }

        string newName, newDesig;
        double newSalary;

        cin.ignore();
        cout << "Enter New Name (Leave blank to keep unchanged): ";
        getline(cin, newName);
        if (!newName.empty()) {
            employees[index].setName(newName);
        }

        cout << "Enter New Designation (Leave blank to keep unchanged): ";
        getline(cin, newDesig);
        if (!newDesig.empty()) {
            employees[index].setDesignation(newDesig);
        }

        cout << "Enter New Salary (Enter -1 to keep unchanged): ";
        cin >> newSalary;
        if (newSalary >= 0) {
            employees[index].setSalary(newSalary);
        }

        cout << "Employee record updated successfully!\n";
    }

    
    void deleteEmployee() {
        if (employees.empty()) {
            cout << "\nNo records available to delete.\n";
            return;
        }

        int id;
        cout << "\nEnter Employee ID to delete: ";
        cin >> id;

        int index = findEmployeeIndex(id);
        if (index != -1) {
            employees.erase(employees.begin() + index);
            cout << "Employee record deleted successfully!\n";
        } else {
            cout << "Employee with ID " << id << " not found.\n";
        }
    }
};


int main() {
    EmployeeManagementSystem ems;
    int choice;

    do {
        cout << "\n====================================\n";
        cout << "  Employee Management Mini-System \n";
        cout << "====================================\n";
        cout << "1. Add Employee Record\n";
        cout << "2. Display All Employee Records\n";
        cout << "3. Search Employee Record\n";
        cout << "4. Update Employee Record\n";
        cout << "5. Delete Employee Record\n";
        cout << "6. Exit\n";
        cout << "====================================\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                ems.addEmployee();
                break;
            case 2:
                ems.displayAllEmployees();
                break;
            case 3:
                ems.searchEmployee();
                break;
            case 4:
                ems.updateEmployee();
                break;
            case 5:
                ems.deleteEmployee();
                break;
            case 6:
                cout << "\nExiting the system. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid selection! Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
