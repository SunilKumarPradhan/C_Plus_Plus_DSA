/*
### Access Specifiers in C++ Classes

1.  Default Access Specifier :
   -  Classes : Members are `private` by default if no access specifier is given.
   -  Structs : Members are `public` by default if no access specifier is given.

2.  Private Members :
   -  Private Methods : Utility functions or helper functions used internally by the class. They can be called by other methods within the same class but not from outside the class.
   -  Private Data : Data that should not be modified directly from outside the class. Access to this data is controlled via public methods.

3.  Using Private Members :
   - Private methods are accessed within the class by public or other private methods.
   - Example of a class with private methods:

*/


   class MinHeap {
   public:
       // Public methods
       void insert(int value);
       void extractMin();
       void printHeap();

   private:
       // Private data and helper methods
       int* heapArray;
       int size;
       
       // Private method for maintaining heap property
       void heapify(int index);
       
       // Private method to swap elements
       void swap(int& a, int& b);
   };

   // Implementation of public method to insert an element
   
   
   //   When defining member functions outside the class definition, 
   //   the syntax might look unusual initially, but it follows a standard format in C++.
   //           |
   //           |
   //          V  
   void MinHeap::insert(int value) {   
       // Code to insert the value
       // ...

       // Call private method to maintain heap property
       heapify(0); // Example usage
   }


   // Class ke andar rehne waale fucntions ko member functions boltein hain 


   // Implementation of private method to maintain heap property
   void MinHeap::heapify(int index) {
       // Code to ensure the heap property is maintained
       // This might involve calling swap()
   }

   // Implementation of private method to swap elements
   void MinHeap::swap(int& a, int& b) {
       int temp = a;
       a = b;
       b = temp;
   }
