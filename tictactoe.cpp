#include <iostream>

char board[9] = {'1', '2', '3', 
                  '4', '5', '6', 
                  '7', '8', '9'};
char playerMove;
bool player1Move = true;
bool game = true;
int turns = 0;

int showArrays() {    
    for (int i = 0; i < 9; i++) {
        std::cout << board[i] << " ";
        if (i % 3 == 2 && i > 0) {
            std::cout << "\n";
        }
        else {
        }
    }
    return 0;
}

int userMove() {
    if (player1Move == true) {
    std::cout << "Player 1: Pick a number on screen: ";
    std::cin >> playerMove;
    }
    else {
    std::cout << "Player 2: Pick a number on screen: ";
    std::cin >> playerMove;
    }
    return 0;
}

int checkBoard() {
    for (int n = 0; n < 9; n++){
        if (playerMove == board[n]) { 
            if (player1Move == true){
            board[n] = 'X';
            player1Move = false;
            turns++;
            break;
            }
            else {
            board[n] = 'O';
            player1Move = true;
            turns++;
            break;
            }
        }
        else {
        }
    }
    return 0;
}

int checkWin() {
    if (turns == 8 && game == true){
        std::cout << "Draw";
        game = false;
    }
    else if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X'){
        std::cout << "Player 1 Wins!\n";
	    game = false;
    }
    else if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O'){
        std::cout << "Player 2 Wins!\n";
        game = false;
    }
    else if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') {
        std::cout << "Player 1 Wins!\n";
        game = false;
    }
    else if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') {
        std::cout << "Player 2 Wins!\n";
        game = false;
    }
    else if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') {
        std::cout << "Player 1 Wins!\n";
        game = false;
    }
    else if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') {
        std::cout << "Player 2 Wins!\n";
        game = false;
    }
    else if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') {
        std::cout << "Player 1 Wins!\n";
        game = false;
    }
    else if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O') {
        std::cout << "Player 2 Wins!\n";
        game = false;
    }
    else if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') {
        std::cout << "Player 1 Wins!\n";
        game = false;
    }
    else if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') {
        std::cout << "Player 2 Wins!\n";
        game = false;
    }
    else if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') {
        std::cout << "Player 1 Wins!\n";
        game = false;
    }
    else if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') {
        std::cout << "Player 2 Wins!\n";
        game = false;
    }
    else if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') {
        std::cout << "Player 1 Wins!\n";
        game = false;
    }
    else if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') {
        std::cout << "Player 2 Wins!\n";
        game = false;
    }
    else if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X') {
        std::cout << "Player 1 Wins!\n";
        game = false;
    }
    else if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O') {
        std::cout << "Player 2 Wins!\n";
        game = false;
    }
    else {
    }
    return 0;
}

int main() {
    while (game == true) {
    showArrays();
    userMove();
    checkBoard();
    checkWin();
    }
    return 0;
}