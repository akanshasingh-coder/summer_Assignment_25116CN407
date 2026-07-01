//Wap to Create salary management system
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Employee {
private:
    int empID;
    std::string name;
    std::string designation;
    double basicSalary;
    double allowanceHRA; // House Rent Allowance
    double allowanceDA;  // Dearness Allowance
    double taxDeduction;
    double netSalary;

public:
    // Constructor
    Employee(int id, std::string empName, std::string desig, double basic) {
        empID = id;
        name = empName;
        designation = desig;
        basicSalary = basic;
        calculateSalary();
    }

    // Calculate earnings and deductions dynamically
    void calculateSalary() {
        allowanceHRA = 0.20 * basicSalary; // 20% HRA
        allowanceDA = 0.10 * basicSalary;  // 10% DA
        
        double grossSalary = basicSalary + allowanceHRA + allowanceDA;
        
        // Progressive tax deduction rule
        if (grossSalary > 50000) {
            taxDeduction = 0.12 * grossSalary; // 12% tax
        } else if (grossSalary > 30000) {
            taxDeduction = 0.05 * grossSalary; // 5% tax
        } else {
            taxDeduction = 0.0;
        }
        
        netSalary = grossSalary - taxDeduction;
    }

    // Getters
    int getID() const { return empID; }
    std::string getName() const { return name; }

    // Modify basic salary or designation
    void updateDetails(std::string newDesig, double newBasic) {
        designation = newDesig;
        basicSalary = newBasic;
        calculateSalary();
    }

    // Print detailed salary slip for the individual employee
    void displayPaySlip() const {
        std::cout << "\n=========================================\n";
        std::cout << "            EMPLOYEE PAYSLIP             \n";
        std::cout << "=========================================\n";
        std::cout << " Employee ID   : " << empID << "\n";
        std::cout << " Name          : " << name << "\n";
        std::cout << " Designation   : " << designation << "\n";
        std::cout << "-----------------------------------------\n";
        std::cout << " + Basic Salary: $" << std::fixed << std::setprecision(2) << basicSalary << "\n";
        std::cout << " + HRA (20%)   : $" << allowanceHRA << "\n";
        std::cout << " + DA (10%)    : $" << allowanceDA << "\n";
        std::cout << " ----------------------------------------\n";
        std::cout << " - Tax Ded.    : $" << taxDeduction << "\n";
        std::cout << "=========================================\n";
        std::cout << " NET PAY       : $" << netSalary << "\n";
        std::cout << "=========================================\n";
    }

    // Format row for summary table
    void displayTableRow() const {
        std::cout << std::left << std::setw(8) << empID 
                  << std::setw(15) << name 
                  << std::setw(15) << designation 
                  << "$" << std::fixed << std::setprecision(2) << std::setw(12) << basicSalary 
                  << "$" << std::setw(10) << netSalary << "\n";
    }
};

class SalaryManagementSystem {
private:
    std::vector<Employee> employees;

    // Helper to find employee index by ID
    int findEmployeeIndex(int id) {
        for (size_t i = 0; i < employees.size(); ++i) {
            if (employees[i].getID() == id) {
                return i;
            }
        }
        return -1; // Not found
    }

public:
    void addEmployee() {
        int id;
        std::string name, desig;
        double basic;

        std::cout << "\nEnter Employee ID: ";
        std::cin >> id;
        
        if (findEmployeeIndex(id) != -1) {
            std::cout << "Error: Employee ID already exists!\n";
            return;
        }

        std::cin.ignore(); // Clear buffer
        std::cout << "Enter Employee Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Designation: ";
        std::getline(std::cin, desig);
        std::cout << "Enter Basic Salary ($): ";
        std::cin >> basic;

        employees.push_back(Employee(id, name, desig, basic));
        std::cout << "Employee record added successfully!\n";
    }

    void displayAllEmployees() {
        if (employees.empty()) {
            std::cout << "\nNo employee records found.\n";
            return;
        }

        std::cout << "\n---------------------------------------------------------------\n";
        std::cout << std::left << std::setw(8) << "ID" 
                  << std::setw(15) << "Name" 
                  << std::setw(15) << "Designation" 
                  << std::setw(13) << "Basic" 
                  << "Net Salary\n";
        std::cout << "---------------------------------------------------------------\n";
        for (const auto& emp : employees) {
            emp.displayTableRow();
        }
        std::cout << "---------------------------------------------------------------\n";
    }

    void searchEmployee() {
        int id;
        std::cout << "\nEnter Employee ID to search: ";
        std::cin >> id;

        int index = findEmployeeIndex(id);
        if (index != -1) {
            employees[index].displayPaySlip();
        } else {
            std::cout << "Employee not found.\n";
        }
    }

    void modifyEmployee() {
        int id;
        std::cout << "\nEnter Employee ID to modify: ";
        std::cin >> id;

        int index = findEmployeeIndex(id);
        if (index != -1) {
            std::string newDesig;
            double newBasic;

            std::cin.ignore();
            std::cout << "Enter New Designation: ";
            std::getline(std::cin, newDesig);
            std::cout << "Enter New Basic Salary ($): ";
            std::cin >> newBasic;

            employees[index].updateDetails(newDesig, newBasic);
            std::cout << "Employee details updated successfully!\n";
        } else {
            std::cout << "Employee not found.\n";
        }
    }

    void deleteEmployee() {
        int id;
        std::cout << "\nEnter Employee ID to delete: ";
        std::cin >> id;

        int index = findEmployeeIndex(id);
        if (index != -1) {
            employees.erase(employees.begin() + index);
            std::cout << "Employee record deleted successfully!\n";
        } else {
            std::cout << "Employee not found.\n";
        }
    }
};

int main() {
    SalaryManagementSystem sms;
    int choice;

    do {
        std::cout << "\n=========================================\n";
        std::cout << "        SALARY MANAGEMENT SYSTEM         \n";
        std::cout << "=========================================\n";
        std::cout << "1. Add New Employee\n";
        std::cout << "2. Display All Employees\n";
        std::cout << "3. Search Employee PaySlip\n";
        std::cout << "4. Modify Employee Data\n";
        std::cout << "5. Delete Employee Record\n";
        std::cout << "6. Exit\n";
        std::cout << "=========================================\n";
        std::cout << "Enter your choice (1-6): ";
        std::cin >> choice;

        switch (choice) {
            case 1: sms.addEmployee(); break;
            case 2: sms.displayAllEmployees(); break;
            case 3: sms.searchEmployee(); break;
            case 4: sms.modifyEmployee(); break;
            case 5: sms.deleteEmployee(); break;
            case 6: std::cout << "\nExiting system. Goodbye!\n"; break;
            default: std::cout << "\nInvalid selection! Please choose between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
