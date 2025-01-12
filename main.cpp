#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int checkWinner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return currentPlayer;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return currentPlayer;

    return 0; // No winner
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
    } else {
        currentMarker = 'X';
    }
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

int main() {
    cout << "Welcome to Tic Tac Toe!\n";
    cout << "Player 1, choose your marker (X or O): ";
    cin >> currentMarker;

    if (currentMarker == 'X') {
        currentPlayer = 1;
    } else {
        currentMarker = 'O';
        currentPlayer = 2;
    }

    drawBoard();

    int winner = 0;
    for (int i = 0; i < 9; i++) {
        cout << "Player " << currentPlayer << ", enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Choose a slot between 1 and 9.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already occupied! Try a different slot.\n";
            i--;
            continue;
        }

        drawBoard();
        winner = checkWinner();

        if (winner != 0) {
            cout << "Player " << winner << " wins! Congratulations!\n";
            break;
        }

        swapPlayerAndMarker();
    }

    if (winner == 0) {
        cout << "It's a tie! Well played!\n";
    }

    return 0;
}