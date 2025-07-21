#include <iostream>
#include <cstdlib> // For std::rand() and std::srand()
#include <ctime>   // For std::time()
#include <limits>  // For std::numeric_limits

// --- Function Prototypes ---
void play_game();
bool ask_to_play_again();

// --- Main Function ---
int main() {
    // Seed the random number generator once at the start of the program
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    do {
        play_game();
    } while (ask_to_play_again());

    std::cout << "\nThanks for playing! Goodbye." << std::endl;

    return 0;
}

// --- Function Implementations ---

// Contains the main logic for a single round of the game
void play_game() {
    // Generate a random number between 1 and 100
    int random_number = std::rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    std::cout << "\nI have selected a number between 1 and 100." << std::endl;
    std::cout << "Can you guess what it is?" << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        // Input validation
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
            continue; // Skip the rest of this loop iteration
        }

        attempts++;

        if (guess > random_number) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (guess < random_number) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "\nCongratulations! You guessed the number!" << std::endl;
            std::cout << "It took you " << attempts << " attempts." << std::endl;
        }

    } while (guess != random_number);
}

// Asks the user if they want to play another round
bool ask_to_play_again() {
    while (true) {
        std::cout << "\nWould you like to play again? (y/n): ";
        char choice;
        std::cin >> choice;

        // Handle potential input errors
        if (std::cin.fail()) {
             std::cin.clear();
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        choice = std::tolower(choice);
        if (choice == 'y') {
            return true;
        }
        if (choice == 'n') {
            return false;
        }
        std::cout << "Invalid choice. Please enter 'y' or 'n'." << std::endl;
    }
}
