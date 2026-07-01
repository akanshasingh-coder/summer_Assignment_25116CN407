//wap to create bank account system 
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Class to handle individual bank account data and operations
class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    string accountType; // "Savings" or "Current"
    double balance;

public:
    // Constructor to initialize an account
    BankAccount(int accNum, string name, string type, double initialDeposit) {
        accountNumber = accNum;
        accountHolderName = name;
        accountType = type;
        balance = initialDeposit;
    }

    // Getter for account number to facilitate searching
    int getAccountNumber() const {
        return accountNumber;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\n[Success] $" << fixed << setprecision(2) << amount << " deposited successfully!\n";
        } else {
            cout << "\n[Error] Invalid deposit amount!\n";
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "\n[Error] Invalid withdrawal amount!\n";
        } else if (amount > balance) {
            cout << "\n[Error] Insufficient balance! Current Balance: $" << balance << "\n";
        } else {
            balance -= amount;
            cout << "\n[Success] $" << fixed << setprecision(2) << amount << " withdrawn successfully!\n";
        }
    }

    // Function to display account details
    void displayAccountDetails() const {
        cout << "\n================================";
        cout << "\n       ACCOUNT DETAILS         ";
        cout << "\n================================";
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nHolder Name    : " << accountHolderName;
        cout << "\nAccount Type   : " << accountType;
        cout << "\nCurrent Balance: $" << fixed << setprecision(2) << balance;
        cout << "\n================================\n";
    }
};

// Helper function to find an account by its number
BankAccount* findAccount(vector<BankAccount>& accounts, int accNum) {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNum) {
            return &accounts[i];
        }
    }
    return nullptr;
}

int main() {
    vector<BankAccount> bankAccounts;
    int nextAccountNumber = 1001; // Starting account number
    int choice;

    do {
        cout << "\n=== BANK MANAGEMENT SYSTEM ===";
        cout << "\n1. Create New Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Check Balance / Details";
        cout << "\n5. Exit";
        cout << "\nEnter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, type;
                int typeChoice;
                double initialDeposit;

                cin.ignore(); // Clear buffer before reading string
                cout << "\nEnter Account Holder Name: ";
                getline(cin, name);

                cout << "Select Account Type:\n1. Savings\n2. Current\nChoice: ";
                cin >> typeChoice;
                type = (typeChoice == 2) ? "Current" : "Savings";

                cout << "Enter Initial Deposit Amount: $";
                cin >> initialDeposit;

                if (initialDeposit < 0) {
                    cout << "\n[Error] Initial deposit cannot be negative!\n";
                } else {
                    // Create object and add to data system
                    BankAccount newAccount(nextAccountNumber, name, type, initialDeposit);
                    bankAccounts.push_back(newAccount);
                    cout << "\n[Success] Account created successfully!";
                    cout << "\nYour assigned Account Number is: " << nextAccountNumber << "\n";
                    nextAccountNumber++; // Auto-increment system for safety
                }
                break;
            }
            case 2: {
                int accNum;
                double amount;
                cout << "\nEnter Account Number: ";
                cin >> accNum;

                BankAccount* account = findAccount(bankAccounts, accNum);
                if (account != nullptr) {
                    cout << "Enter Amount to Deposit: $";
                    cin >> amount;
                    account->deposit(amount);
                } else {
                    cout << "\n[Error] Account not found!\n";
                }
                break;
            }
            case 3: {
                int accNum;
                double amount;
                cout << "\nEnter Account Number: ";
                cin >> accNum;

                BankAccount* account = findAccount(bankAccounts, accNum);
                if (account != nullptr) {
                    cout << "Enter Amount to Withdraw: $";
                    cin >> amount;
                    account->withdraw(amount);
                } else {
                    cout << "\n[Error] Account not found!\n";
                }
                break;
            }
            case 4: {
                int accNum;
                cout << "\nEnter Account Number: ";
                cin >> accNum;

                BankAccount* account = findAccount(bankAccounts, accNum);
                if (account != nullptr) {
                    account->displayAccountDetails();
                } else {
                    cout << "\n[Error] Account not found!\n";
                }
                break;
            }
            case 5:
                cout << "\nThank you for using our Banking System. Goodbye!\n";
                break;

            default:
                cout << "\n[Error] Invalid choice! Please select between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
