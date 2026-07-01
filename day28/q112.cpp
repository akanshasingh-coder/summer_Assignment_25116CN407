//wap to create contact management system 
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>

class Contact {
private:
    std::string name;
    std::string phone;
    std::string email;

public:
    Contact(std::string n, std::string p, std::string e) 
        : name(n), phone(p), email(e) {}

    // Getters
    std::string getName() const { return name; }
    std::string getPhone() const { return phone; }
    std::string getEmail() const { return email; }

    // Setters for editing
    void setName(const std::string& n) { name = n; }
    void setPhone(const std::string& p) { phone = p; }
    void setEmail(const std::string& e) { email = e; }

    // Display row format
    void displayContactRow(int index) const {
        std::cout << std::left << std::setw(6) << index 
                  << std::setw(25) << name 
                  << std::setw(15) << phone 
                  << std::setw(30) << email << std::endl;
    }
};

class ContactManager {
private:
    std::vector<Contact> contacts;

    // Utility helper to safely read string inputs with spaces
    std::string getValidatedInput(const std::string& prompt) {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);
        while (input.empty()) {
            std::getline(std::cin, input);
        }
        return input;
    }

public:
    void addContact() {
        std::cout << "\n--- Add New Contact ---\n";
        std::string name = getValidatedInput("Enter Name: ");
        std::string phone = getValidatedInput("Enter Phone Number: ");
        std::string email = getValidatedInput("Enter Email Address: ");

        contacts.push_back(Contact(name, phone, email));
        std::cout << "\nSuccess: Contact added successfully!\n";
    }

    void displayAllContacts() const {
        if (contacts.empty()) {
            std::cout << "\nNotification: No contacts available in the system.\n";
            return;
        }

        std::cout << "\n----------------------------------------------------------------------------\n";
        std::cout << std::left << std::setw(6) << "S.No" 
                  << std::setw(25) << "Name" 
                  << std::setw(15) << "Phone" 
                  << std::setw(30) << "Email" << std::endl;
        std::cout << "----------------------------------------------------------------------------\n";

        for (size_t i = 0; i < contacts.size(); ++i) {
            contacts[i].displayContactRow(i + 1);
        }
        std::cout << "----------------------------------------------------------------------------\n";
    }

    void searchContact() const {
        if (contacts.empty()) {
            std::cout << "\nNotification: The contact book is empty.\n";
            return;
        }

        std::cout << "\n--- Search Contact ---\n";
        std::cout << "Enter name to search: ";
        std::string searchName;
        std::getline(std::cin >> std::ws, searchName);

        bool found = false;
        // Case-insensitive primitive check can be applied, or strict match
        for (size_t i = 0; i < contacts.size(); ++i) {
            if (contacts[i].getName() == searchName) {
                if (!found) {
                    std::cout << "\nMatch Found:\n";
                    std::cout << "----------------------------------------------------------------------------\n";
                }
                contacts[i].displayContactRow(i + 1);
                found = true;
            }
        }

        if (!found) {
            std::cout << "\nError: No contact matching '" << searchName << "' was found.\n";
        } else {
            std::cout << "----------------------------------------------------------------------------\n";
        }
    }

    void editContact() {
        if (contacts.empty()) {
            std::cout << "\nNotification: No contacts to modify.\n";
            return;
        }

        displayAllContacts();
        std::cout << "Enter the S.No of the contact you want to edit: ";
        size_t index;
        if (!(std::cin >> index) || index < 1 || index > contacts.size()) {
            std::cout << "\nInvalid Choice: Selection cancelled.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear stream buffer

        Contact& target = contacts[index - 1];
        std::cout << "\nEditing Contact: " << target.getName() << "\n";
        
        std::string newName = getValidatedInput("Enter New Name (or press Enter to skip): ");
        std::string newPhone = getValidatedInput("Enter New Phone (or press Enter to skip): ");
        std::string newEmail = getValidatedInput("Enter New Email (or press Enter to skip): ");

        if (!newName.empty()) target.setName(newName);
        if (!newPhone.empty()) target.setPhone(newPhone);
        if (!newEmail.empty()) target.setEmail(newEmail);

        std::cout << "\nSuccess: Contact updated successfully!\n";
    }

    void deleteContact() {
        if (contacts.empty()) {
            std::cout << "\nNotification: No contacts to delete.\n";
            return;
        }

        displayAllContacts();
        std::cout << "Enter the S.No of the contact you want to delete: ";
        size_t index;
        if (!(std::cin >> index) || index < 1 || index > contacts.size()) {
            std::cout << "\nInvalid Choice: Deletion aborted.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        contacts.erase(contacts.begin() + (index - 1));
        std::cout << "\nSuccess: Contact removed successfully!\n";
    }
};

int main() {
    ContactManager cm;
    int choice;

    while (true) {
        std::cout << "\n===============================\n";
        std::cout << "   CONTACT MANAGEMENT SYSTEM   \n";
        std::cout << "===============================\n";
        std::cout << "1. Add New Contact\n";
        std::cout << "2. Display All Contacts\n";
        std::cout << "3. Search Contact\n";
        std::cout << "4. Edit Contact\n";
        std::cout << "5. Delete Contact\n";
        std::cout << "6. Exit Program\n";
        std::cout << "===============================\n";
        std::cout << "Enter your choice (1-6): ";

        if (!(std::cin >> choice)) {
            std::cout << "\nInvalid Input: Please type a number between 1 and 6.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: cm.addContact(); break;
            case 2: cm.displayAllContacts(); break;
            case 3: cm.searchContact(); break;
            case 4: cm.editContact(); break;
            case 5: cm.deleteContact(); break;
            case 6: 
                std::cout << "\nThank you for using the Contact Management System. Goodbye!\n";
                return 0;
            default: 
                std::cout << "\nInvalid Range: Selection must be 1 to 6.\n";
        }
    }
}
