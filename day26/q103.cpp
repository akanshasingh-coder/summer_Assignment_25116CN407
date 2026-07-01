//wap to create ATM simultation 
#include <iostream>
#include <iomanip>

class ATM {
private:
    int pin;
    double balance;

public:
    // Constructor to initialize default PIN and Balance
    ATM(int initialPin, double initialBalance) {
        pin = initialPin;
        balance = initialBalance;
    }

    // Function to verify user PIN
    bool checkPin(int enteredPin) {
        return enteredPin == pin;
    }

    // Function to display the current balance
    void displayBalance() {
        std::cout << "\n-----------------------------------";
        std::cout << "\nYour current balance is: $" << std::fixed << std::setprecision(2) << balance;
        std::cout << "\n-----------------------------------\n";
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "\n$" << amount << " deposited successfully.";
            displayBalance();
        } else {
            std::cout << "\nInvalid deposit amount.";
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "\nInvalid withdrawal amount.";
        } else if (amount > balance) {
            std::cout << "\nInsufficient balance! Transaction failed.";
        } else {
            balance -= amount;
            std::cout << "\n$" << amount << " withdrawn successfully.";
            displayBalance();
        }
    }
};

int main() {
    // Initializing ATM with a default PIN (1234) and initial balance ($500.00)
    ATM myAtm(1234, 500.00);
    int enteredPin;
    int choice;
    int attempts = 0;
    const int maxAttempts = 3;
    bool authenticated = false;

    std::cout << "=== Welcome to the ATM Simulation ===\n";

    // PIN Authentication Loop
    while (attempts < maxAttempts) {
        std::cout << "Enter your 4-digit PIN: ";
        std::cin >> enteredPin;

        if (myAtm.checkPin(enteredPin)) {
            authenticated = true;
            break;
        } else {
            attempts++;
            std::cout << "Incorrect PIN. Attempts remaining: " << (maxAttempts - attempts) << "\n\n";
        }
    }

    if (!authenticated) {
        std::cout << "Too many incorrect attempts. Card blocked!\n";
        return 0;
    }

    // Main ATM Menu Loop
    do {
        std::cout << "\n===== ATM MENU =====\n";
        std::cout << "1. Check Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                myAtm.displayBalance();
                break;
            case 2: {
                double dAmount;
                std::cout << "Enter deposit amount: $";
                std::cin >> dAmount;
                myAtm.deposit(dAmount);
                break;
            }
            case 3: {
                double wAmount;
                std::cout << "Enter withdrawal amount: $";
                std::cin >> wAmount;
                myAtm.withdraw(wAmount);
                break;
            }
            case 4:
                std::cout << "\nThank you for using our ATM. Goodbye!\n";
                break;
            default:
                std::cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
