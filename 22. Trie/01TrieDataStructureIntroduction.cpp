/*
Hashing aur Trie ke beech farak aur pros aur cons:

1. Hashing:
   - Hashing ek technique hai jismein ek hash function use hota hai data ko store aur retrieve karne ke liye.
   - Yeh ek array ya hash table ko use karta hai jaha data ko ek unique index (hash) pe store kiya jata hai.

   Pros:
   - O(1) average time complexity for search, insert, and delete operations.
   - Simple and easy to implement.
   - Efficient for large datasets.

   Cons:
   - Collisions handle karna mushkil ho sakta hai.
   - Extra space needed for hash table.
   - Hash function ke upar performance depend karta hai.
   - Not ordered, so range queries are not efficient.

2. Trie:
   - Trie ek tree-like data structure hai jo characters ko nodes mein store karta hai aur words ko represent karta hai.
   - Mostly dictionary-like applications mein use hota hai jaha quick prefix searches chahiye hote hain.

   Pros:
   - Efficient for prefix searches and auto-completion.
   - Insertion and search operations are O(L), where L is the length of the word.
   - Can handle dynamic set of strings efficiently.

   Cons:
   - Can consume a lot of memory for large datasets.
   - More complex to implement compared to hashing.
   - Space inefficient if there are few words with common prefixes.

Example of use cases:
- Hashing:
  - When you need fast access to data without worrying about order, like implementing a cache.
  - Suitable for applications where data retrieval speed is crucial, e.g., databases.

- Trie:
  - When you need to store a dynamic set of strings and need fast prefix-based searches, like autocomplete features in text editors.
  - Suitable for applications where you need to find common prefixes, e.g., IP routing tables.
*/
