#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void showBoard() {
    cout << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check winner
bool checkWin(char player) {
    // Rows
    for(int i = 0; i < 3; i++)
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;

    // Columns
    for(int i = 0; i < 3; i++)
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;

    // Diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

int main() {
    int choice;
    char turn = 'X';

    for(int move = 0; move < 9; move++) {
        showBoard();
        cout << "\nPlayer " << turn << ", enter position: ";
        cin >> choice;

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if(board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = turn;

            // Check winner
            if(checkWin(turn)) {
                showBoard();
                cout << "\n?? Player " << turn << " WINS!";
                return 0;
            }

            // Switch player
            turn = (turn == 'X') ? 'O' : 'X';
        } 
        else {
            cout << "Invalid move! Try again.\n";
            move--;
        }
    }

    showBoard();
    cout << "\n?? Game Draw!";
    return 0;
}

