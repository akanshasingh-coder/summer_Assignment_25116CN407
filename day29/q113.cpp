//wap to create menu driven calculator
#include <iostream>

using namespace std;

int main() {
    int choice;
    double num1, num2, result;

    do {
        // Displaying the Selection Menu
        cout << "\n===============================\n";
        cout << "     MENU DRIVEN CALCULATOR    \n";
        cout << "===============================\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. Exit\n";
        cout << "-------------------------------\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        // Condition to ask for operands only if user chooses an operation (1 to 4)
        if (choice >= 1 && choice <= 4) {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
        }

        // Executing operation based on choice
        switch (choice) {
            case 1:
                result = num1 + num2;
                cout << "\n>>> Result: " << num1 << " + " << num2 << " = " << result << "\n";
                break;

            case 2:
                result = num1 - num2;
                cout << "\n>>> Result: " << num1 << " - " << num2 << " = " << result << "\n";
                break;

            case 3:
                result = num1 * num2;
                cout << "\n>>> Result: " << num1 << " * " << num2 << " = " << result << "\n";
                break;

            case 4:
                // Runtime validation to prevent system crashing due to undefined states
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "\n>>> Result: " << num1 << " / " << num2 << " = " << result << "\n";
                } else {
                    cout << "\n[Error]: Division by zero is undefined!\n";
                }
                break;

            case 5:
                cout << "\nThank you for using the calculator. Goodbye!\n";
                break;

            default:
                cout << "\n[Error]: Invalid choice! Please select an option between 1 and 5.\n";
                break;
        }

    } while (choice != 5); // Loop runs until choice is 5

    return 0;
}
