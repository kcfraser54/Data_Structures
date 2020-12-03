// Kyle Fraser
// Stack.h
// Purpose: This class creates the functionality
// of a stack object which only stores odd integers.

#ifndef STACK_H
#define STACK_H


class Stack
{
 public:

  class EmptyStack{};
  //Exception class thrown when an attempt
  //is made to pop from an empty stack.
  
  explicit Stack(int size = 50);
  //Allocated memory and initializes variables
  //for a new instance of the stack object.
  
  ~Stack();
  //Destructor deallocates memory for an instance
  //of a stack object
  
  
  Stack(const Stack &);
  //Copy constructor copies data from an object into
  //a new object

  Stack& operator=(const Stack& rhs);
  //Overloaded assignment operator overwrites data from
  //one instance of a stack object to another instance of a
  //stack object.
  
 
  void push(int value);
  //Pre: an integer must be passed by value
  //to the function, value must be an odd integer.
  //Post: a value is pushed onto the stack.
  
  int pop();
  //Pre: The stack must not be empty.
  //Post: An value is popped off of the stack.
  
  bool isEmpty() const;
  //Pre: N/A
  //Post: returns true if the stack is empty
  

 private:

  int* stackArray; 
  int stackSize; 
  int top;

  bool isFull();
  //Pre: N/A
  //Post: returns true if the stack is full.
  
  void resize();
  //Pre: the stack is full.
  //Post: the size of the stack is multiplied
  // by 1.5;

};
#endif
