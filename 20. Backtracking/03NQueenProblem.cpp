#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int N) {
    for (int i = 0; i < col; i++)
        if (board[row][i] == 1) return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1) return false;

    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j] == 1) return false;

    return true;
}

bool solveNQueensUtil(vector<vector<int>> &board, int col, int N) {
    if (col >= N) return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            if (solveNQueensUtil(board, col + 1, N)) return true;
            board[i][col] = 0;
        }
    }

    return false;
}

void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueensUtil(board, 0, N)) {
        cout << "Solution:" << endl;
        for (auto &row : board) {
            for (auto &cell : row) {
                cout << (cell ? "Q " : ". ");
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists" << endl;
    }
}

int main() {
    int N = 8;
    solveNQueens(N);

    return 0;
}


/*
Iss function ka naam hai isSafe aur yeh check karta hai ki given position par queen place ki ja sakti hai ya nahi.

- Function ka logic:
  1. Yeh function row aur column ke saath diagonals ko bhi check karta hai.
  2. Agar kisi bhi position par queen place nahi hui hai, toh true return karta hai.

Process:
- Pehle, row aur column ki values ko check kiya jata hai.
- Diagonals ko bhi check kiya jata hai.

Example:
- Agar row = 2 aur column = 3 hai:
  - Diagonals aur row-column check ke saath result true ho sakta hai.

Dry Run:
1. Initial setup:
   - row = 2
   - column = 3
2. Check:
   - Row aur column ke cells aur diagonals check kiye jate hain.
3. Output:
   - true/false

Output:
true
*/

/*
Iss function ka naam hai solveNQueensUtil aur yeh N-Queens problem ke solution ko find karta hai.

- Function ka logic:
  1. Recursive calls kiye jate hain column wise queens place karne ke liye.
  2. Agar queen valid position pe place ki jati hai, toh recursion continue hoti hai.

Process:
- Pehle, har column mein queen place ki jati hai aur recursion ki jati hai.
- Agar placement valid hai toh result true hoga.

Example:
- Agar N = 4 hai:
  - Possible solution: 2nd and 4th row in 1st and 3rd column respectively.

Dry Run:
1. Initial setup:
   - Board = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}
2. Recursive calls:
   - Queen placed at (0, 1), (1, 3), (2, 0), (3, 2)
3. Output:
   - Solution exists.

Output:
Solution:
. Q . .
. . . Q
Q . . .
. . Q .
*/
