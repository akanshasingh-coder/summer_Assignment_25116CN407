//wap to create mini library management system
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;


class Book {
private:
    int id;
    string title;
    string author;
    bool isIssued;

public:
   
    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;
    }

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getIssuedStatus() const { return isIssued; }


    void issueBook() { isIssued = true; }
    void returnBook() { isIssued = false; }

    
    void displayBook() const {
        cout << left << setw(10) << id 
             << setw(30) << title 
             << setw(25) << author 
             << setw(15) << (isIssued ? "Issued" : "Available") << endl;
    }
};


class Library {
private:
    vector<Book> books;

public:
    
    void addBook() {
        int id;
        string title, author;

        cout << "\nEnter Book ID (Integer): ";
        cin >> id;
        
        
        for (const auto& book : books) {
            if (book.getId() == id) {
                cout << "Error: A book with this ID already exists!\n";
                return;
            }
        }

        cin.ignore(); 
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book successfully added to the library!\n";
    }

    
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "\nThe library inventory is completely empty.\n";
            return;
        }

        cout << "\n-------------------------------------------------------------------------" << endl;
        cout << left << setw(10) << "ID" << setw(30) << "Title" << setw(25) << "Author" << setw(15) << "Status" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        
        for (const auto& book : books) {
            book.displayBook();
        }
        cout << "-------------------------------------------------------------------------\n";
    }

    
    void searchBook() const {
        if (books.empty()) {
            cout << "\nNo books available to search.\n";
            return;
        }

        int id;
        cout << "\nEnter Book ID to search: ";
        cin >> id;

        for (const auto& book : books) {
            if (book.getId() == id) {
                cout << "\nBook Found:\n";
                cout << "-------------------------------------------------------------------------" << endl;
                book.displayBook();
                cout << "-------------------------------------------------------------------------\n";
                return;
            }
        }
        cout << "Book with ID " << id << " was not found.\n";
    }

    
    void issueBook() {
        int id;
        cout << "\nEnter Book ID to issue: ";
        cin >> id;

        for (auto& book : books) {
            if (book.getId() == id) {
                if (book.getIssuedStatus()) {
                    cout << "Sorry, this book is already issued to someone else.\n";
                } else {
                    book.issueBook();
                    cout << "Book successfully issued!\n";
                }
                return;
            }
        }
        cout << "Book with ID " << id << " does not exist in our library.\n";
    }

    
    void returnBook() {
        int id;
        cout << "\nEnter Book ID to return: ";
        cin >> id;

        for (auto& book : books) {
            if (book.getId() == id) {
                if (!book.getIssuedStatus()) {
                    cout << "This book is already marked as available in the library.\n";
                } else {
                    book.returnBook();
                    cout << "Book successfully returned to inventory!\n";
                }
                return;
            }
        }
        cout << "Book with ID " << id << " does not belong to this library.\n";
    }
};


int main() {
    Library myLibrary;
    int choice;

    while (true) {
        cout << "\n===== MINI LIBRARY MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search Book by ID" << endl;
        cout << "4. Issue a Book" << endl;
        cout << "5. Return a Book" << endl;
        cout << "6. Exit Application" << endl;
        cout << "==========================================" << endl;
        cout << "Enter your choices (1-6): ";
        cin >> choice;

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
                cout << "\nThank you for using the Mini Library System. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please select a number between 1 and 6.\n";
        }
    }
    return 0;
}
