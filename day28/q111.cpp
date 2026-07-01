//wap to create ticket booking system 
#include <iostream>
#include <string>

using namespace std;

const int ROWS = 5;
const int COLS = 10;

class Seat 
{
public:
    bool booked;
    string name;

    Seat() 
    {
        booked = false;
        name = "";
    }
};

class MovieTheater 
{
private:
    Seat seats[ROWS][COLS];

public:
    void displaySeats() 
    {
        cout << "\nSeating Arrangement (1 = Booked, 0 = Available):\n";
        for (int i = 0; i < ROWS; ++i) 
        {
            cout << "Row " << i + 1 << ": ";
            for (int j = 0; j < COLS; ++j) 
            {
                cout << seats[i][j].booked << " ";
            }
            cout << endl;
        }
    }

    void bookSeat() 
    {
        int row, col;
        string name;

        cout << "Enter row (1-" << ROWS << "): ";
        cin >> row;
        cout << "Enter seat number (1-" << COLS << "): ";
        cin >> col;
        cin.ignore();  // Flush newline

        if (row < 1 || row > ROWS || col < 1 || col > COLS) 
        {
            cout << "Invalid seat selection.\n";
            return;
        }

        if (seats[row - 1][col - 1].booked==1) 
        {
            cout << "Seat already booked.\n";
        } else 
        {
            cout << "Enter your name: ";
            getline(cin, name);
            seats[row - 1][col - 1].booked = true;
            seats[row - 1][col - 1].name = name;
            cout << "Seat (" << row << ", " << col << ") booked for " << name << ".\n";
        }
    }

    void cancelSeat() 
    {
        int row, col;
        cout << "Enter row of the seat to cancel (1-" << ROWS << "): ";
        cin >> row;
        cout << "Enter seat number (1-" << COLS << "): ";
        cin >> col;

        if (row < 1 || row > ROWS || col < 1 || col > COLS) 
        {
            cout << "Invalid seat.\n";
            return;
        }

        if (seats[row - 1][col - 1].booked==1) 
        {
            cout << "Booking for " << seats[row - 1][col - 1].name << " canceled.\n";
            seats[row - 1][col - 1].booked = false;
            seats[row - 1][col - 1].name = "";
        } else 
        {
            cout << "Seat is already available.\n";
        }
    }

    void showBookings() 
    {
        cout << "\nBooked Seats:\n";
        bool found = false;

        for (int i = 0; i < ROWS; ++i) 
        {
            for (int j = 0; j < COLS; ++j) 
            {
                if (seats[i][j].booked==1) 
                {
                    cout << "Seat (" << i + 1 << ", " << j + 1 << ") - " << seats[i][j].name << endl;
                    found = true;
                }
            }
        }

        if (!found)
            cout << "No bookings yet.\n";
    }
};

int main() 
{
    MovieTheater theater;
    int choice;

    while (true) 
    {
        cout << "\n--------------------- Movie Ticket Booking System--------------------\n";
        cout << "1. Show Seat Layout\n";
        cout << "2. Book a Seat\n";
        cout << "3. Cancel a Booking\n";
        cout << "4. Show All Bookings\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<"\n----------------------------------------------------------------------------\n";
        switch (choice) 
        {
            case 1:
                theater.displaySeats();
                break;
            case 2:
                theater.bookSeat();
                break;
            case 3:
                theater.cancelSeat();
                break;
            case 4:
                theater.showBookings();
                break;
            case 5:
                cout << "Exiting system. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}