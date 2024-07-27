#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int N, vector<vector<int>> &maze, vector<vector<int>> &sol) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y] == 0);
}

bool solveMazeUtil(vector<vector<int>> &maze, int x, int y, vector<vector<int>> &sol, int N) {
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(x, y, N, maze, sol)) {
        sol[x][y] = 1;

        if (solveMazeUtil(maze, x + 1, y, sol, N)) return true;
        if (solveMazeUtil(maze, x, y + 1, sol, N)) return true;

        sol[x][y] = 0;
        return false;
    }

    return false;
}

void solveMaze(vector<vector<int>> &maze, int N) {
    vector<vector<int>> sol(N, vector<int>(N, 0));

    if (solveMazeUtil(maze, 0, 0, sol, N)) {
        cout << "Solution Path:" << endl;
        for (auto &row : sol) {
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
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    int N = maze.size();
    
    solveMaze(maze, N);

    return 0;
}


/*
Iss function ka naam hai isSafe aur yeh check karta hai ki position maze ke boundaries ke andar hai aur us position par rat move kar sakti hai ya nahi.

- Function ka logic:
  1. Yeh function maze ki value aur solution matrix ki value ko check karta hai.
  2. Agar position valid hai aur maze ke cell me 1 hai aur solution matrix me 0 hai, toh true return karta hai.

Process:
- Pehle, boundaries aur cell value ko check kiya jata hai.
- Agar cell valid hai, toh function true return karega.

Example:
- Agar position (1, 1) hai aur maze[1][1] = 1 aur sol[1][1] = 0 hai:
  - Function true return karega.

Dry Run:
1. Initial setup:
   - maze[1][1] = 1
   - sol[1][1] = 0
2. Check:
   - Position valid hai, maze cell value = 1 hai, aur solution cell value = 0 hai.
3. Output:
   - true

Output:
true
*/

/*
Iss function ka naam hai solveMazeUtil aur yeh maze ke cells ko traverse karta hai aur path find karta hai.

- Function ka logic:
  1. Base cases check kiye jate hain: agar destination par pahuche toh true return hota hai.
  2. Recursive calls kiye jate hain move karne ke options ke liye.

Process:
- Pehle, move right aur down ke options try kiye jate hain.
- Recursive calls ke through result determine kiya jata hai.

Example:
- Agar maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}} hai:
  - Possible path: (0, 0) -> (1, 0) -> (1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3).

Dry Run:
1. Initial setup:
   - Maze start point (0, 0)
2. Recursive calls:
   - Move right: (0, 1) invalid
   - Move down: (1, 0) valid
   - Continue recursively...
3. Output:
   - Path exists.

Output:
Solution Path:
1 0 0 0
1 1 0 1
0 1 0 0
0 1 1 1
*/
