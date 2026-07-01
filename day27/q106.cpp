//wap to create employee management system
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Employee {
private:
    int id;
    std::string name;
    std::string designation;
    double salary;

public:
    // Constructor to initialize an employee record
    Employee(int empId, std::string empName, std::string empDesig, double empSalary) {
        id = empId;
        name = empName;
        designation = empDesig;
        salary = empSalary;
    }

    // Getter methods
    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getDesignation() const { return designation; }
    double getSalary() const { return salary; }

    // Display employee record as a table row
    void displayRecord() const {
        std::cout << std::left << std::setw(10) << id 
                  << std::setw(20) << name 
                  << std::setw(20) << designation 
                  << std::setw(15) << std::fixed << std::setprecision(2) << salary 
                  << std::endl;
    }
};

class ManagementSystem {
private:
    std::vector<Employee> employees;

public:
    // 1. Add a new employee
    void addEmployee() {
        int id;
        std::string name, designation;
        double salary;

        std::cout << "\n--- Add New Employee ---\n";
        std::cout << "Enter Employee ID: ";
        std::cin >> id;

        // Check if ID already exists
        for (const auto& emp : employees) {
            if (emp.getId() == id) {
                std::cout << "Error: Employee ID already exists!\n";
                return;
            }
        }

        std::cin.ignore(); // Clear newline buffer
        std::cout << "Enter Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Designation: ";
        std::getline(std::cin, designation);
        std::cout << "Enter Salary: ";
        std::cin >> salary;

        employees.push_back(Employee(id, name, designation, salary));
        std::cout << "Employee record added successfully!\n";
    }

    // 2. Display all employee records
    void viewAllEmployees() const {
        if (employees.empty()) {
            std::cout << "\nNo employee records found.\n";
            return;
        }

        std::cout << "\n-----------------------------------------------------------------\n";
        std::cout << std::left << std::setw(10) << "ID" 
                  << std::setw(20) << "Name" 
                  << std::setw(20) << "Designation" 
                  << std::setw(15) << "Salary ($)" << std::endl;
        std::cout << "-----------------------------------------------------------------\n";
        
        for (const auto& emp : employees) {
            emp.displayRecord();
        }
        std::cout << "-----------------------------------------------------------------\n";
    }

    // 3. Search for an employee by ID
    void searchEmployee() const {
        if (employees.empty()) {
            std::cout << "\nNo records available to search.\n";
            return;
        }

        int id;
        std::cout << "\nEnter Employee ID to Search: ";
        std::cin >> id;

        for (const auto& emp : employees) {
            if (emp.getId() == id) {
                std::cout << "\nRecord Found:\n";
                std::cout << "-----------------------------------------------------------------\n";
                emp.displayRecord();
                std::cout << "-----------------------------------------------------------------\n";
                return;
            }
        }
        std::cout << "Employee with ID " << id << " not found.\n";
    }

    // 4. Delete an employee record by ID
    void deleteEmployee() {
        if (employees.empty()) {
            std::cout << "\nNo records available to delete.\n";
            return;
        }

        int id;
        std::cout << "\nEnter Employee ID to Delete: ";
        std::cin >> id;

        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if (it->getId() == id) {
                employees.erase(it);
                std::cout << "Employee record deleted successfully!\n";
                return;
            }
        }
        std::cout << "Employee with ID " << id << " not found.\n";
    }
};

int main() {
    ManagementSystem system;
    int choice;

    do {
        std::cout << "\n===== EMPLOYEE MANAGEMENT SYSTEM =====\n";
        std::cout << "1. Add Employee\n";
        std::cout << "2. View All Employees\n";
        std::cout << "3. Search Employee\n";
        std::cout << "4. Delete Employee\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                system.addEmployee();
                break;
            case 2:
                system.viewAllEmployees();
                break;
            case 3:
                system.searchEmployee();
                break;
            case 4:
                system.deleteEmployee();
                break;
            case 5:
                std::cout << "\nExiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice! Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
