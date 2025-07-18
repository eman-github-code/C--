#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

void initializeBoard() {
    for (int i = 0, k = '1'; i < 3; ++i) {
        for (int j = 0; j < 3; ++j, ++k) {
            board[i][j] = k;  // Fill with 1�9
        }
    }
    currentPlayer = 'X';
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool isValidMove(int cell) {
    if (cell < 1 || cell > 9) return false;
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    return board[row][col] != 'X' && board[row][col] != 'O';
}

void makeMove(int cell) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    board[row][col] = currentPlayer;
}

bool checkWin() {
    // Rows, columns, and diagonals
    for (int i = 0; i < 3; ++i)
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;

    for (int i = 0; i < 3; ++i)
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return true;

    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    initializeBoard();

    while (true) {
        displayBoard();
        int cell;
        cout << "Player " << currentPlayer << ", enter cell number (1-9): ";
        cin >> cell;

        if (!isValidMove(cell)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        makeMove(cell);

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        switchPlayer();
    }

    return 0;
}

