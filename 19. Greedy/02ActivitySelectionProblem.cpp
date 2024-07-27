/*
 Activity Selection Problem :
   -  Objective : Given a set of activities with start and end times, select the maximum number of non-overlapping activities.
   -  Greedy Choice : Select activities with the earliest finish time that does not overlap with previously selected activities.
   
   
   -  Steps :
     1. Sort activities by finish time.
     2. Select the first activity, then iterate through the remaining activities, selecting those that start after the last selected activity finishes.

   -  Example :
     - Activities: (1, 4), (3, 5), (0, 6), (5, 7), (8, 9), (5, 9)
       - Where (Start, End)

     - Sorted by Finish Time: (1, 4), (3, 5), (5, 7), (8, 9)
     - Schedule: (1, 4), (5, 7), (8, 9)
       - Max Number of Activities: 3



- Notes:
  -  Greedy Choice Property : Making the best choice at each step will lead to an optimal solution.
  -  Optimal Substructure : The problem's solution can be constructed from optimal solutions of subproblems.
  - Greedy algorithms are efficient but may not always produce the optimal solution for every problem. They are most effective when the problem has both the greedy choice property and optimal substructure.
*/
