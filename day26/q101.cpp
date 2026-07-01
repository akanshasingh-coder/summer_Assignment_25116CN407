//wap to create number guessing game 
#include <iostream>
#include <cstdlib> // Required for rand() and srand()
#include <ctime>   // Required for time()

using namespace std;

int main() {
    // Seed the random number generator with current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random secret number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int userGuess = 0;
    int attempts = 0;

    cout << "=================================\n";
    cout << "    Welcome to the Number Game!  \n";
    cout << "=================================\n";
    cout << "I have picked a secret number between 1 and 100.\n";
    cout << "Can you guess what it is?\n\n";

    // Loop until the user guesses the correct number
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess > secretNumber) {
            cout << "Too high! Try a lower number.\n\n";
        } else if (userGuess < secretNumber) {
            cout << "Too low! Try a higher number.\n\n";
        } else {
            cout << "\n🎉 Congratulations! You guessed the number!\n";
            cout << "It took you " << attempts << " attempts.\n";
        }
    } while (userGuess != secretNumber);

    return 0;
}
