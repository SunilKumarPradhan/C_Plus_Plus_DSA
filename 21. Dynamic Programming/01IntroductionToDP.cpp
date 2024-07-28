/*
Dynamic Programming (DP)

- Definition:
  Dynamic Programming (DP) ek algorithmic technique hai jo complex problems ko simpler subproblems mein tod kar solve karta hai. Yeh technique tab applicable hoti hai jab problem mein overlapping subproblems aur optimal substructure ho, yani problem ka solution subproblems ke solutions se ban sakta hai.

- Key Concepts:
  1. Overlapping Subproblems: Problem ke subproblems baar-baar repeat hote hain.
  2. Optimal Substructure: Ek optimal solution subproblems ke optimal solutions se ban sakta hai.
  3. Memoization: Subproblem solutions ko store karna taaki future mein unhe baar-baar calculate na karna pade.
  4. Tabulation: Ek bottom-up approach jahan subproblems ko smallest subproblem se start karke solve kiya jata hai aur solutions ko ek table mein store kiya jata hai.

- How It Works:
  1. Problem ko recursively divide karo subproblems mein.
  2. Subproblems ko solve karo aur solutions ko store karo (memoization).
  3. Table (array) ko fill karo bottom-up manner mein (tabulation).
  4. Stored solutions ko use karke original problem solve karo.

- Applications:
  Dynamic Programming bahut se problems mein use hota hai, jaise:
  1. Fibonacci Sequence: F(n) = F(n-1) + F(n-2)
  2. Longest Common Subsequence (LCS): Do strings ka longest common subsequence find karna.
  3. Knapsack Problem: Ek bag mein maximum value items ko fit karna with weight constraints.
  4. Matrix Chain Multiplication: Minimum cost matrix multiplication order find karna.
  5. Edit Distance: Do strings ko match karne ke liye minimum operations find karna.

- Less Known Facts:
  1. DP isme time complexity ko drastically reduce kar sakta hai from exponential to polynomial.
  2. DP problems ko recursive solutions ko iterative solutions mein convert karna asaan hota hai using tabulation.
  3. Memoization aur tabulation dono use karne se DP problems aur efficient ho sakti hain.
  4. DP often requires careful analysis to identify overlapping subproblems and optimal substructure.
  5. Space optimization techniques like using rolling arrays can significantly reduce space complexity.

- Example: Fibonacci Sequence
  - Recursive Approach:
    F(n) = F(n-1) + F(n-2)
  - DP Approach:
    1. Initialize array f[] with base cases: f[0] = 0, f[1] = 1
    2. Iterate from 2 to n, filling f[i] = f[i-1] + f[i-2]
    3. Return f[n]

- Complexity:
  DP algorithms usually have polynomial time complexity, making them much faster than naive exponential algorithms.

- Advantages:
  1. Efficiency: DP drastically reduces time complexity.
  2. Reusability: Solutions to subproblems can be reused.
  3. Simplicity: DP simplifies the process of solving complex problems by breaking them into manageable subproblems.

- Disadvantages:
  1. Memory Usage: DP can require significant memory to store solutions to subproblems.
  2. Problem Identification: Not all problems are suitable for DP; identifying the right problems and optimal substructure can be challenging.

Overall, Dynamic Programming is a powerful and efficient technique for solving a wide range of optimization problems.
*/
