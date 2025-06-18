#include <iostream>
std::string secretWord;
int guesses = 5;
char guess;
std::string progress;
std::string sel;
std::string word;

int enterSecret() {
    std::cout << "Enter the word of choice: ";
    std::cin >> secretWord;
    //std::cout << secretWord << "\n";
    for (int i=0; i<secretWord.length(); i++) {
        progress.replace(i, secretWord.length(), "_ ");
    }
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
    return 0;
}

int guessing() {
    while (guesses != 0) {
        std::cout << progress << guesses << "\nEnter 'letter' for a letter or 'word' to guess the word: ";
        std::cin >> sel;
        if (sel == "word") {
            std::cout << "\nGuess the word: ";
            std::cin >> word;
            if (word == secretWord) {
                std::cout << "\nYou Win!\n";
            }
            else {
                std::cout << "\nIncorrect\n";
                guesses--;
            }
        }
        else if (sel == "letter") {
            std::cout << "\nEnter a guess: ";
            std::cin >> guess;
            std::string tempProgress = progress;

            for (int i=0; i<secretWord.length(); i++) {
            if (guess == secretWord.at(i)) {
                progress.at(i) = guess;
            }
            else {
            }
        }
            if (tempProgress == progress) {
                std::cout << "There was no letter " << guess << "\n";
                guesses--;
            }
            else {
                std::cout << "The letter " << guess << " is in the letter\n";
            }
        
        }
        else {
            std::cout << "Invalid response \n";
        }
        std::cout << "You have " << guesses << " guesses remaining\n";

    }
    if (guesses == 0) { 
        std::cout << "You lost\n The word was " << secretWord << "\n";
    }
    return 0;
}

int main() {
    enterSecret();
    guessing();
    return 0;
}