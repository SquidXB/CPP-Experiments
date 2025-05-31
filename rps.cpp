#include <iostream>
#include <cstdlib>

int wins = 0;
int rounds = 0;
char x;
char y;

int userPick() {
    std::cout << "Pick r, p, or s: ";
    std::cin >> x;
    return 0;
}

int cpuPick() {
    srand(time(0));
    int randNum = rand();
    randNum %= 3;

    switch (randNum) {
    case 0:
        y = 'r';
        std::cout << "Computer chose Rock\n";
        break;
    
    case 1:
        y = 'p';
        std::cout << "Computer chose Paper\n";
        break;
    
    case 2:
        y = 's';
        std::cout << "Computer chose Scissors\n";
        break;

    default:
        std::cout << "Didn't work";
    }
    return 0;
}

int pickWin() {
    switch (x) {
    case 'r':
        switch (y) {
        case 'r':
        std::cout << "Tie";
        rounds++;
        break;

        case 'p':
        std::cout << "You Lose";
        rounds++;
        break;

        case 's':
        std::cout << "You Win";
        rounds++;
        wins++;
        break;

        default:
        std::cout << "Error Player Rock";
        break;
        }
    break;

    case 'p':
        switch (y) {
        case 'r':
        std::cout << "You Win";
        rounds++;
        wins++;
        break;

        case 'p':
        std::cout << "Tie";
        rounds++;
        break;

        case 's':
        std::cout << "You Lose";
        rounds++;
        break;

        default:
        std::cout << "Error Player Paper";
        break;
        }
    break;

    case 's': // should be fine
        switch (y) {
        case 'r':
        std::cout << "You Lose";
        rounds++;
        break;

        case 'p':
        std::cout << "You Win";
        rounds++;
        wins++;
        break;

        case 's':
        std::cout << "Tie";
        rounds++;
        break;

        default:
        std::cout << "Error Player Scissors";
        break;
        }
    break;
    }

    return 0;
}

int main () {
    userPick();
    cpuPick();
    pickWin();
    return 0;
}