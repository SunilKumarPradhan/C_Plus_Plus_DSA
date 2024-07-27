/*
Fractional Knapsack Problem :
   -  Objective : Given a set of items with weights and values, determine the maximum value that can be obtained in a knapsack with a given capacity, allowing fractional items.
   -  Greedy Choice : Select items with the highest value-to-weight ratio and fill the knapsack to capacity.
  
  
   -  Steps :
     1. Compute the value-to-weight ratio for each item.
     2. Sort items in decreasing order of this ratio.
     3. Iterate through the sorted items, adding as much of each item as possible to the knapsack until it is full.

   -  Example :
     - Items: (Weight1, Value1), (Weight2, Value2), (Weight3, Value3)
       - (10, 60), (20, 100), (30, 120)
       - Capacity: 50

     - Ratios: Item1 (6), Item2 (5), Item3 (4)
     - Sorted by Ratio: Item1, Item2, Item3
     - Knapsack: Take all of Item1 (10 weight, 60 value), all of Item2 (20 weight, 100 value), and part of Item3 (20 weight, 80 value).
       - Total Value: 60 + 100 + 80 = 240
*/ 