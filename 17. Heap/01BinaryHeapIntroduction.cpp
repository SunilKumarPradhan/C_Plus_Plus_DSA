/*

# Binary Heap in C++

 1. Basic Concept: 
-  Binary Heap  ek complete binary tree hai jisme har node ki value apne children ki values se badi (max-heap) ya chhoti (min-heap) hoti hai.
- Yeh data structure heap property maintain karta hai.

 2. Types of Binary Heaps: 
-  Max-Heap:  Root node ki value sabse badi hoti hai aur har parent ki value apne children se badi hoti hai.
-  Min-Heap:  Root node ki value sabse chhoti hoti hai aur har parent ki value apne children se chhoti hoti hai.

 3. Usage: 
-  Priority Queue:  Binary heap ko priority queue implement karne ke liye use kiya jata hai.
-  Heap Sort:  Elements ko sort karne ke liye heap sort algorithm ka use hota hai.

 4. Formulas & Operations: 

 i. Heap Operations: 

1.  Insertion (Add a new element): 
   -  Algorithm: 
     - New element ko tree ke last position par add karo.
     - Heap property maintain karne ke liye, newly added element ko parent ke saath swap karo (heapify-up).
   -  Time Complexity:  O(log n)

2.  Deletion (Remove the root element): 
   -  Algorithm: 
     - Root element ko remove karo.
     - Last element ko root position par laao.
     - Heap property maintain karne ke liye, element ko heapify-down karo (sift down).
   -  Time Complexity:  O(log n)

3.  Heapify (Convert an array into heap): 
   -  Algorithm: 
     - Bottom-up approach se, sabhi nodes ko heapify karo.
   -  Time Complexity:  O(n)

 ii. Formulas: 

1.  Parent Node (Index): 
   - For any node at index `i`, parent node ka index `(i-1)/2` hota hai.

2.  Left Child Node (Index): 
   - For any node at index `i`, left child node ka index `2*i + 1` hota hai.

3.  Right Child Node (Index): 
   - For any node at index `i`, right child node ka index `2*i + 2` hota hai.

4. The maximum number of nodes in a binary tree with height h is 2^h - 1

5. The maximum number of nodes in a binary tree at height h is ceil[n/2^h+1]


 iii. Algorithms Associated: 

1.  Heapify-Up (for insertion): 
   -  Algorithm: 
     - Compare newly added element with its parent.
     - Swap if necessary and continue until heap property is restored or root is reached.
   -  Usage:  Ensures the newly inserted element is in the correct position.

2.  Heapify-Down (for deletion): 
   -  Algorithm: 
     - Compare root with its children.
     - Swap with the appropriate child and continue until heap property is restored.
   -  Usage:  Ensures that the root element is in the correct position after deletion.

*/