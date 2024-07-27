/*
Greedy Algorithms

- Definition:
  A greedy algorithm is a simple and intuitive approach to solving optimization problems by making a sequence of choices, each of which is locally optimal. The idea is to make the best choice at each step with the hope that these local optima will lead to a global optimum.

- Key Concept:
  Greedy algorithms work by iteratively choosing the best possible option at each step, without considering the global consequences of the choice. The algorithm does not backtrack; it proceeds with the choice and hopes that the local optimum will result in a globally optimal solution.

- How It Works:
  1.  Initialization : Start with an empty solution or initial state.
  2.  Selection : At each step, select the best available option that appears to be the most beneficial.
  3.  Feasibility Check : Ensure that the selected option fits within the constraints of the problem.
  4.  Incorporate : Add the selected option to the solution.
  5.  Repeat : Continue to make choices until the solution is complete or no more options are available.

- Applications:
  Greedy algorithms are used in a variety of problems where the global optimum can be reached by making a series of locally optimal choices. Some common applications include:
  1.  Activity Selection Problem : Choosing the maximum number of non-overlapping activities.
  2.  Huffman Coding : Constructing an optimal prefix code for data compression.
  3.  Kruskal's Algorithm : Finding the Minimum Spanning Tree (MST) of a graph by choosing edges with the smallest weight.
  4.  Prim's Algorithm : Another algorithm for finding the Minimum Spanning Tree (MST) of a graph by growing the MST from a starting node.
  5.  Dijkstra's Algorithm : Finding the shortest path from a source vertex to all other vertices in a graph with non-negative edge weights.

- Characteristics:
  1.  Greedy Choice Property : A global optimum can be arrived at by selecting a local optimum.
  2.  Optimal Substructure : The optimal solution to a problem contains optimal solutions to subproblems.

- Example:
  Consider the Coin Change Problem, where the goal is to make a change for a given amount using the minimum number of coins. A greedy algorithm might involve repeatedly taking the largest coin that is less than or equal to the remaining amount until the amount is reduced to zero. This approach works efficiently if the coin denominations are such that the greedy choice always leads to an optimal solution.

- Complexity:
  The time complexity of greedy algorithms is generally linear or polynomial in terms of the number of items or vertices, depending on the specific problem. The space complexity is usually minimal, as the algorithm does not require additional storage beyond the solution.

- Advantages:
  1.  Efficiency : Greedy algorithms often have lower time complexity compared to other approaches like dynamic programming.
  2.  Simplicity : They are easy to implement and understand.

- Disadvantages:
  1.  Optimality : Greedy algorithms do not always produce the optimal solution for all problems. They may fail in cases where the globally optimal solution requires considering future consequences of current choices.
  2.  Problem Specific : The greedy approach is problem-specific and may not be applicable to all optimization problems.

Overall, greedy algorithms are a powerful tool for solving optimization problems where making locally optimal choices leads to a globally optimal solution. However, their applicability depends on the specific nature of the problem being solved.
*/



/*General Algorithm for Solving Greedy Problems

- Steps to Follow:
  1. **Problem Analysis**:
     - Understand the problem requirements and constraints.
     - Identify if a greedy approach can be applied. Typically, this involves checking if the problem has the "greedy choice property" and "optimal substructure".

  2. **Greedy Choice**:
     - Define the criteria for making a local optimal choice. This could involve sorting, selecting the best option at each step, or another strategy depending on the problem.

  3. **Feasibility Check**:
     - Ensure that the selected choice is valid within the problem's constraints. The solution must adhere to all constraints.

  4. **Update**:
     - Update the solution with the chosen option and modify any relevant parameters.

  5. **Repeat**:
     - Repeat the above steps until the solution is complete or no more choices can be made.

  6. **Solution Construction**:
     - Construct the final solution from the choices made during the process.*/
