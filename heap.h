// Kyle Fraser
// heap.h
// Purpose: This class creates the functionality
// of a heap object.

#ifndef HEAP_H
#define HEAP_H

class Heap
{
  
 public:
  
  Heap();
  // Allocated memory and initialuzes varables for a new instance
  // of the heap object.
  
  ~Heap();
  // Destructor deallocates memory for an instance of a heap object.
  
  Heap(const Heap &obj);
  // Copy constructor copies data from an object into a new object.
  
  Heap& operator=(const Heap &rhs);
  // Overloaded assignment operator overwrites data from one
  // instance of a heap object to another instance of a heap
  // object.

  class EmptyHeap{};
  // Exception class thrown when an attempt
  // is made to remove from an empty heap.

  void insert(int val);
  // pre:  Requires an integer value as a parameter.

  // post: The integer will be inserted into the appropriate node
  // in the heap.
  
  int remove();
  // pre: The heap must not be empty.

  // post: The root value of the heap will be removed
  // and returned.
  
  void percDown(int start);
  // pre: Requires the starting or root index for the heap.

  // post: The order of the heap is maintained.
  // All data in parent nodes is less than the data in
  // the children nodes.
  
  void flush(int num);
  // pre: Requires an integer to be flushed from the
  // heap as a parameter. Also requires that the heap
  // is not empty.

  // post: All occurences of the integer passed in are
  // removed from the heap.

  bool isEmpty() const; 
  // pre: N/A

  // post: Returns if the heap is empty or not.

 private:

  bool isFull() const;
  // pre: N/A
  
  // post: Returns if the heap is full or not.

  void resize();
  // pre: N/A

  //post: The size the the array is increased by 1.5;
  
  int* heapArray;
  int heapSize;
  int heapCount;

};

#endif 
