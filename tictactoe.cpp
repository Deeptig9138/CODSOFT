#include <iostream>
using namespace std;

char board[3][3]; 
char currentPlayer; 

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '1' + i * 3 + j;
        }
    }
    currentPlayer = 'X'; 
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool playerMove() {
    int move;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> move;
    if (move < 1 || move > 9) {
        cout << "Invalid move. Try again.\n";
        return false;
    }
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Spot already taken. Try again.\n";
        return false;
    }
    board[row][col] = currentPlayer;
    return true;
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }

    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Main function
int main() {
    char playAgain;
    do {
        initializeBoard();
        bool gameWon = false;
        bool gameDraw = false;

        while (!gameWon && !gameDraw) {
            displayBoard();
            if (playerMove()) {
                gameWon = checkWin();
                gameDraw = checkDraw();
                if (!gameWon && !gameDraw) {
                    switchPlayer();
                }
            }
        }

        displayBoard();
        if (gameWon) {
            cout << "Player " << currentPlayer << " wins!\n";
        } else if (gameDraw) {
            cout << "The game is a draw!\n";
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
