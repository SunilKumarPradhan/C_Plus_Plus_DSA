

/*
Iss function ka naam hai mergeKSortedArrays aur yeh function k sorted arrays ko merge karke ek single sorted array banaata hai.

- Function ka logic:
  1. Pehle ek min-heap (priority_queue) banate hain jisme har array ka pehla element daalte hain. Har element ke sath uski array ka index aur element ka index bhi store karte hain.
  2. Min-heap ka use karke, smallest element ko hamesha root pe rakha jata hai. Yeh ensure karta hai ki merge operation efficient rahe.
  3. Heap se minimum element ko nikal kar result array mein daalte hain. Agar nikalne ke baad, us element ki array mein aage aur elements hain, to next element ko heap mein daal dete hain.
  4. Yeh process tab tak repeat karte hain jab tak heap khali nahi ho jaata.

Process:
- Pehle, har array ka pehla element min-heap mein daalte hain.
- Har element ko heap se extract karte hain aur result array mein add karte hain. Agar us element ki array mein aur elements hain, to next element ko heap mein daal dete hain.
- Finally, heap se extract karte hue, result array ko build karte hain jo merge kiya hua sorted array hota hai.

Example:
- Agar arrays [[2, 6, 12], [1, 9], [23, 34, 90, 2000]] hain:

1. Initial min-heap with first elements of each array:
   - Min-Heap: [1, 2, 23]
   - Array Index and Element Index: [(1, 0, 0), (2, 0, 0), (23, 2, 0)]

2. Process:
   - Extract 1 (from array 1), heap: [2, 23]
     - Next element from array 1: 9
     - Min-Heap: [2, 23, 9]
   - Extract 2 (from array 0), heap: [9, 23]
     - Next element from array 0: 6
     - Min-Heap: [6, 23, 9]
   - Extract 6 (from array 0), heap: [9, 23]
     - Next element from array 0: 12
     - Min-Heap: [9, 23, 12]
   - Extract 9 (from array 1), heap: [12, 23]
     - No next element in array 1
   - Extract 12 (from array 0), heap: [23]
     - No next element in array 0
   - Extract 23 (from array 2), heap: [34]
     - Next element from array 2: 34
     - Min-Heap: [34]
   - Extract 34 (from array 2), heap: [90]
     - Next element from array 2: 90
     - Min-Heap: [90]
   - Extract 90 (from array 2), heap: [2000]
     - Next element from array 2: 2000
     - Min-Heap: [2000]
   - Extract 2000 (from array 2), heap is empty

3. Result vector (after heap extraction): [1, 2, 6, 9, 12, 23, 34, 90, 2000]

Output:
Merged array is: 1 2 6 9 12 23 34 90 2000
*/
