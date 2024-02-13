#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;

// Function declarations
void drawLine(int n, char symbol);
void rules();
int generateComputerNumber();

int main()
{
    // Initialize variables
    string playerName;
    int playerBalance = 100; // Player starts with $100
    int playerBet;
    int computerNumber;
    int playerGuess;

    // Display welcome message and get player name
    cout << "Welcome to the Guessing Game!" << endl;
    cout << "Enter your name: ";
    getline(cin, playerName);

    // Display rules
    rules();

    // Game loop
    while (playerBalance > 0) {
        // Get player bet
        cout << "Enter your bet (0 to quit): $";
        cin >> playerBet;

        // Check if player wants to quit
        if (playerBet == 0) {
            break;
        }

        // Generate computer number
        computerNumber = generateComputerNumber();

        // Get player guess
        cout << "Guess a number between 1 and 100: ";
        cin >> playerGuess;

        // Check if player guess is correct
        if (playerGuess == computerNumber) {
            cout << "Congratulations, you won! You earned $" << playerBet << "." << endl;
            playerBalance += playerBet;
        } else {
            cout << "Sorry, you lost. The correct number was " << computerNumber << "." << endl;
            playerBalance -= playerBet;
        }

        // Display player balance
        cout << "Your current balance is $" << playerBalance << "." << endl;
    }

    // Display goodbye message
    cout << "Thanks for playing! Goodbye!" << endl;

    return 0;
}

// Function to display a line of symbols
void drawLine(int n, char symbol)
{
    for (int i = 0; i < n; i++) {
        cout << symbol;
    }
    cout << endl;
}

// Function to display the game rules
void rules()
{
    drawLine(50, '-');
    cout << "Game Rules" << endl;
    drawLine(50, '-');
    cout << "1. Guess a number between 1 and 100." << endl;
    cout << "2. Enter your bet (0 to quit)." << endl;
    cout << "3. If you guess correctly, you win the amount of your bet." << endl;
    cout << "4. If you guess incorrectly, you lose the amount of your bet." << endl;
    drawLine(50, '-');
}

// Function to generate a random number between 1 and 100
int generateComputerNumber()
{
    srand(time(0)); // Seed the random number generator
    return rand() % 100 + 1; // Generate a random number between 1 and 100vvbcc`
}