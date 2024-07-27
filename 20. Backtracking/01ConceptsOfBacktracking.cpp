#include <bits/stdc++.h>
using namespace std;

/*
Backtracking

- Definition:
  Backtracking is a general algorithmic technique for solving problems incrementally by trying partial solutions and then abandoning them if they are not valid. It systematically searches for a solution by exploring all possible options and undoing choices when necessary.

- Key Concept:
  The idea of backtracking is to build a solution step by step, and if at any point, it is determined that the current solution cannot be extended to a valid solution, the algorithm backtracks to the previous step to try a different option.

- How It Works:
  1.  Choose : Make a choice from available options.
  2.  Explore : Recursively explore further by applying the chosen option.
  3.  Check : Determine if the current solution is valid or if it meets the problem’s criteria.
  4.  Backtrack : If the current solution is invalid or leads to a dead end, undo the choice (i.e., backtrack) and try the next option.
  5.  Repeat : Continue this process until a valid solution is found or all options are exhausted.

- Applications:
  Backtracking is widely used in solving problems involving combinatorial search, such as:
  1.  N-Queens Problem : Placing N queens on an N×N chessboard so that no two queens threaten each other.
  2.  Sudoku : Filling a 9×9 grid so that each column, row, and 3×3 subgrid contains all the digits from 1 to 9.
  3.  Subset Sum Problem : Finding subsets of a set that sum up to a specific value.
  4.  Permutations and Combinations : Generating all possible permutations or combinations of a set.

- Example:
  Consider the N-Queens problem. We place queens on a chessboard row by row. For each row, we try placing the queen in each column and recursively place queens in subsequent rows. If a placement leads to a valid solution, we proceed; otherwise, we backtrack and try the next column.

- Complexity:
  The time complexity of backtracking algorithms can be exponential in the worst case, especially for problems with a large search space. However, it is often manageable with pruning techniques and constraints that reduce the search space.

- Advantages:
  1.  Flexibility : Backtracking can be applied to a wide range of problems.
  2.  Simplicity : It simplifies the implementation of complex problems by breaking them into smaller subproblems.

- Disadvantages:
  1.  Efficiency : Backtracking may not be efficient for problems with a large number of possible solutions.
  2.  Memory Usage : It may require substantial memory to store intermediate states and choices.

Overall, backtracking is a powerful technique for solving problems that involve exploring multiple potential solutions and systematically finding the one that satisfies the problem constraints.
*/

bool isSafe(const string& subseq, const string& exclude) {
    return subseq.find(exclude) == string::npos;
}

void generateSubsequences(const string& str, string subseq, int index, const string& exclude) {
    if (index == str.length()) {
        if (isSafe(subseq, exclude)) {
            cout << subseq << endl;
        }
        return;
    }

    generateSubsequences(str, subseq + str[index], index + 1, exclude);
    generateSubsequences(str, subseq, index + 1, exclude);
}

int main() {
    string str = "pqrst";
    string exclude = "pq";

    generateSubsequences(str, "", 0, exclude);

    return 0;
}

/*
Iss function ka naam hai isSafe aur yeh check karta hai ki subsequence exclude string ko contain karta hai ya nahi.

- Function ka logic:
  1. Yeh function check karta hai ki subsequence me exclude string present nahi hai.
  2. Agar exclude string subsequence mein nahi milti, toh function true return karta hai.

Process:
- Pehle, subsequence ko check kiya jata hai ki exclude string present hai ya nahi.
- Agar subsequence valid hai (exclude string present nahi hai), toh function true return karta hai.

Example:
- Agar subsequence = "pqr" aur exclude = "pq" hai:
  - Function true return karega kyunki "pq" subsequence mein nahi hai.

Dry Run:
1. Initial setup:
   - subsequence = "pqr"
   - exclude = "pq"
2. Check:
   - "pq" subsequence mein nahi milti, toh result true hoga.
3. Output:
   - true

Output:
true
*/

/*
Iss function ka naam hai generateSubsequences aur yeh given string ke saare subsequences generate karta hai except those containing the exclude string.

- Function ka logic:
  1. Yeh function recursively subsequences generate karta hai. Ek baar current character ko include karke aur ek baar exclude karke.
  2. Har generated subsequence ko check kiya jata hai ki exclude string contain karti hai ya nahi.

Process:
- Pehle, current character ko include aur exclude karke subsequences generate kiye jate hain.
- Recursive calls ke through har possible subsequence generate hota hai aur validate kiya jata hai.

Example:
- Agar string = "pqrst" hai aur exclude = "pq" hai:
  - Possible subsequences excluding any that contain "pq" will be: "", "p", "r", "s", "t", "pr", "ps", "pt", "rs", "rt", "st" etc.

Dry Run:
1. Initial setup:
   - string = "pqrst"
   - subseq = ""
   - index = 0
2. Recursive calls:
   - Include "p": "p", continue with index = 1
   - Exclude "p": "", continue with index = 1
   - Continue with other characters similarly.
3. Output:
   - All subsequences that do not contain "pq" will be printed.

Output:
<All subsequences except those containing "pq">
*/
