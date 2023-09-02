#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    char playAgain;
    
    do {
        int secretNumber = std::rand() % 100 + 1;
        int guess;
        int attempts = 0;

        std::cout << "==============================\n";
        std::cout << "Welcome to the Guess the Number Game!\n";
        std::cout << "I'm thinking of a number between 1 and 100. Can you guess it?\n";
        std::cout << "==============================\n\n";

        do {
            std::cout << "Enter your guess: ";
            std::cin >> guess;
            attempts++;

            if (guess < secretNumber) {
                std::cout << "Too low! Try again.\n";
            } else if (guess > secretNumber) {
                std::cout << "Too high! Try again.\n";
            } else {
                std::cout << "Congratulations! You guessed the number (" << secretNumber << ") in " << attempts << " attempts!\n";
            }
        } while (guess != secretNumber);

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
        
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thanks for playing! Goodbye.\n";

    return 0;
}


