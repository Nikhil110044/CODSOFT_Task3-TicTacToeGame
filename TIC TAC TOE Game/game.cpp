#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void displayBoard(const vector<vector<char>>& board);
bool playerMove(vector<vector<char>>& board, char player);
bool checkForWin(const vector<vector<char>>& board, char player);
bool checkForDraw(const vector<vector<char>>& board);
void switchPlayers(char& currentPlayer);
bool playAgain();

int main() {
    char currentPlayer = 'X';
    bool gameOver = false;

    do {
        // Initialize the game board
        vector<vector<char>> board(3, vector<char>(3, ' '));

        // Main game loop
        do {
            displayBoard(board);
            gameOver = playerMove(board, currentPlayer);

            if (checkForWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
                break;
            }

            if (checkForDraw(board)) {
                displayBoard(board);
                cout << "It's a draw! The game is over." << endl;
                break;
            }

            switchPlayers(currentPlayer);

        } while (!gameOver);

    } while (playAgain());

    cout << "Thank you for playing Tic-Tac-Toe by Nikhil! Goodbye!" << endl;

    return 0;
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "Welcome to the Tic-Tac-Toe Game by Nikhil!" << endl;
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool playerMove(vector<vector<char>>& board, char player) {
    int row, col;

    cout << "Player " << player << ", enter your move (row and column): ";
    cin >> row >> col;

    // Adjust to 0-based indices
    --row;
    --col;

    // Check if the move is valid
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
        return false; // Game is not over
    } else {
        cout << "Invalid move! Try again." << endl;
        return playerMove(board, player); // Recursive call to get a valid move
    }
}

bool checkForWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true; // Win
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true; // Diagonal win
    }

    return false; // No win
}

bool checkForDraw(const vector<vector<char>>& board) {
    // Check for a draw (no empty spaces left)
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // Not a draw, the game can continue
            }
        }
    }
    return true; // It's a draw
}

void switchPlayers(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
