//wap to create library management system
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

// Class representing an individual Book
class Book {
private:
    string isbn;
    string title;
    string author;
    bool isIssued;

public:
    // Constructor
    Book(string b_isbn, string b_title, string b_author) {
        isbn = b_isbn;
        title = b_title;
        author = b_author;
        isIssued = false;
    }

    // Getters
    string getIsbn() const { return isbn; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getIssuedStatus() const { return isIssued; }

    // Setters for changing issue status
    void issueBook() { isIssued = true; }
    void returnBook() { isIssued = false; }

    // Display individual book details
    void displayBook() const {
        cout << left << setw(15) << isbn 
             << setw(30) << title 
             << setw(25) << author 
             << setw(15) << (isIssued ? "Issued" : "Available") << "\n";
    }
};

// Class managing the Library operations
class Library {
private:
    vector<Book> books;

public:
    // 1. Add a new book to the library catalog
    void addBook() {
        string isbn, title, author;
        cout << "\nEnter ISBN: ";
        cin >> isbn;
        cin.ignore(); // Clear newline buffer
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);

        // Check if the book with same ISBN already exists
        for (const auto& book : books) {
            if (book.getIsbn() == isbn) {
                cout << "\nError: A book with this ISBN already exists!\n";
                return;
            }
        }

        books.push_back(Book(isbn, title, author));
        cout << "\nBook added successfully!\n";
    }

    // 2. Display all books available in the collection
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "\nThe library inventory is currently empty.\n";
            return;
        }

        cout << "\n============================================================================\n";
        cout << left << setw(15) << "ISBN" << setw(30) << "Title" << setw(25) << "Author" << setw(15) << "Status" << "\n";
        cout << "============================================================================\n";
        for (const auto& book : books) {
            book.displayBook();
        }
        cout << "============================================================================\n";
    }

    // 3. Search for a specific book by its ISBN
    void searchBook() const {
        if (books.empty()) {
            cout << "\nThe library inventory is currently empty.\n";
            return;
        }

        string isbn;
        cout << "\nEnter ISBN to search: ";
        cin >> isbn;

        for (const auto& book : books) {
            if (book.getIsbn() == isbn) {
                cout << "\nBook Found:\n";
                cout << "----------------------------------------------------------------------------\n";
                book.displayBook();
                return;
            }
        }
        cout << "\nBook not found with the given ISBN.\n";
    }

    // 4. Checkout / Issue a book to a user
    void issueBook() {
        string isbn;
        cout << "\nEnter ISBN to issue: ";
        cin >> isbn;

        for (auto& book : books) {
            if (book.getIsbn() == isbn) {
                if (book.getIssuedStatus()) {
                    cout << "\nSorry, this book is already checked out.\n";
                    return;
                }
                book.issueBook();
                cout << "\nBook issued successfully!\n";
                return;
            }
        }
        cout << "\nBook not found with the given ISBN.\n";
    }

    // 5. Check-in / Return a borrowed book
    void returnBook() {
        string isbn;
        cout << "\nEnter ISBN to return: ";
        cin >> isbn;

        for (auto& book : books) {
            if (book.getIsbn() == isbn) {
                if (!book.getIssuedStatus()) {
                    cout << "\nThis book was not issued. It is already in the library.\n";
                    return;
                }
                book.returnBook();
                cout << "\nBook returned successfully!\n";
                return;
            }
        }
        cout << "\nBook not found with the given ISBN.\n";
    }
};

// Main Driver Function
int main() {
    Library myLibrary;
    int choice;

    while (true) {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by ISBN\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit Application\n";
        cout << "=====================================\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        // Catch invalid non-integer inputs
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(10000, '\n');
            cout << "\nInvalid choice! Please input a valid integer between 1 and 6.\n";
            continue;
        }

        switch (choice) {
            case 1:
                myLibrary.addBook();
                break;
            case 2:
                myLibrary.displayAllBooks();
                break;
            case 3:
                myLibrary.searchBook();
                break;
            case 4:
                myLibrary.issueBook();
                break;
            case 5:
                myLibrary.returnBook();
                break;
            case 6:
                cout << "\nThank you for using the Library Management System. Goodbye!\n";
                return 0;
            default:
                cout << "\nInvalid choice! Please select an option between 1 and 6.\n";
        }
    }
    return 0;
}
