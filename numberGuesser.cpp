#include <iostream>
#include <cstdlib>

int secNum;
int guess;
int guesses = 5;
int wins = 0;

int randomize() {
    srand(time(0));
    secNum = rand() % 50 + 1;
    return 0;
}

int guessing() {
    
    std::cout << "Guess a number between 1-50: ";
    std::cin >> guess;
    if (guess > secNum) {
        guesses--;
        std::cout << "Your guess is too high. You have " << guesses << " remaining.\n";
        
    }
    else if (guess < secNum) {
        guesses--;
        std::cout << "Your guess is too low. You have " << guesses << " remaining.\n";
        
    }
    else {
        std::cout << "You Win!\n";
        guesses = 0;
        wins++;
    }
    
    return 0;
}

int gameOver() {
    if (guesses == 0 && guess != secNum){
        std::cout << "Game Over!\nThe number was " << secNum;
    }
    else {}
    return 0;
}

int main() {
    randomize();
    while (guesses > 0){
    guessing();
    gameOver();
    }
    return 0;
}