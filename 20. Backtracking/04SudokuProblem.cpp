#include <bits/stdc++.h>
using namespace std;

/*
Iss function ka naam hai isSafe aur yeh check karta hai ki current number Sudoku board ke current cell mein valid hai ya nahi.

- Function ka logic:
  1. Yeh function check karta hai ki number already row, column, ya 3x3 subgrid mein exist karta hai ya nahi.
  2. Agar number kisi bhi existing element ke barabar nahi hai, toh function true return karta hai.

Process:
- Pehle, row aur column ko check kiya jata hai.
- Uske baad, 3x3 subgrid ko validate kiya jata hai.

Example:
- Agar number 5 hai aur board cell [0][0] ko fill karna hai:
  - Row 0, Column 0, aur 3x3 subgrid ko check kiya jata hai.
  - Agar number 5 kisi bhi check mein nahi milta, toh function true return karega.

Dry Run:
1. Initial setup:
   - Board mein 5 fill karna hai.
   - Row, column, aur subgrid check karna hai.
2. Check:
   - Agar 5 row aur column mein nahi milta aur subgrid mein bhi nahi hai, toh result true hoga.
3. Output:
   - true/false

Output:
true/false
*/

bool isSafe(const vector<vector<int>> &board, int row, int col, int num) {
    // Check if num is present in the current row
    for (int x = 0; x < 9; x++)
        if (board[row][x] == num) return false;

    // Check if num is present in the current column
    for (int x = 0; x < 9; x++)
        if (board[x][col] == num) return false;

    // Check if num is present in the 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num) return false;

    return true;
}

/*
Iss function ka naam hai solveSudokuUtil aur yeh Sudoku board ko solve karta hai recursively.

- Function ka logic:
  1. Yeh function board ke har cell ko fill karne ki koshish karta hai valid numbers ke saath.
  2. Agar cell already filled hai, toh agle cell par move karta hai.
  3. Agar cell empty hai, toh numbers 1 se 9 tak try kiya jata hai aur valid number fill karke recursion kiya jata hai.

Process:
- Pehle, empty cell ko find kiya jata hai.
- Valid numbers ko try kiya jata hai aur check kiya jata hai ki board solve hota hai ya nahi.
- Agar board solve hota hai, toh true return karta hai; agar nahi, toh backtrack karke next number try karta hai.

Example:
- Agar board ke kisi cell mein 5 fill karna hai:
  - Check kiya jata hai ki 5 valid hai ya nahi.
  - Agar valid hai, toh 5 fill kiya jata hai aur solveSudokuUtil function ko recursively call kiya jata hai.

Dry Run:
1. Initial setup:
   - Board mein empty cell = [0][0].
2. Try numbers:
   - Try 1, 2, 3,...9 in the cell.
   - Check each number with isSafe function.
3. Output:
   - Valid filled Sudoku board will be printed if solvable.

Output:
<Completed Sudoku board>
*/

bool solveSudokuUtil(vector<vector<int>> &board, int row, int col) {
    // If we have reached the end of the board
    if (row == 9) return true;
    
    // If we have reached the end of the row, move to the next row
    if (col == 9) {
        row++;
        col = 0;
    }
    
    // If cell is already filled, move to the next cell
    if (board[row][col] != 0) return solveSudokuUtil(board, row, col + 1);

    // Try all numbers from 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudokuUtil(board, row, col + 1)) return true;
            board[row][col] = 0; // Backtrack
        }
    }

    return false;
}

/*
Iss function ka naam hai solveSudoku aur yeh Sudoku board ko solve karta hai using backtracking.

- Function ka logic:
  1. Yeh function solveSudokuUtil function ko call karta hai jo board ko recursively solve karta hai.
  2. Agar solveSudokuUtil true return karta hai, toh solved board print kiya jata hai.
  3. Agar solveSudokuUtil false return karta hai, toh "No solution exists" print kiya jata hai.

Process:
- Pehle, solveSudokuUtil function ko call kiya jata hai.
- Agar board solve hota hai, toh print kiya jata hai.
- Agar solve nahi hota, toh message print kiya jata hai.

Example:
- Given Sudoku board with some pre-filled numbers.
  - solveSudoku function call kiya jata hai.
  - Agar board solve hota hai, toh completed board print hota hai.

Dry Run:
1. Initial setup:
   - Board ke initial state ke saath solveSudoku function call kiya jata hai.
2. Recursive solving:
   - solveSudokuUtil function board ko solve karta hai aur print karta hai.
3. Output:
   - Solved Sudoku board or "No solution exists" message.

Output:
<Completed Sudoku board or No solution exists>
*/

void solveSudoku(vector<vector<int>> &board) {
    if (solveSudokuUtil(board, 0, 0)) {
        cout << "Sudoku Solution:" << endl;
        for (auto &row : board) {
            for (auto &cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists" << endl;
    }
}

int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    solveSudoku(board);

    return 0;
}
