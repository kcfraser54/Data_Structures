// Kyle Fraser
// stack.cpp 
// Implementation file for stack described in stack.h



#include "stack.h"

Stack::Stack(int size)
{
  
  if(size < 3){ 
    size = 50;  
  }
  stackArray = new int[size];
  stackSize = size; 
  top = 0;

}


Stack::Stack(const Stack &obj){
  
  stackSize = obj.stackSize;
  stackArray = new int[stackSize];
  for(int i = 0; i < stackSize; i++){
    stackArray[i] = obj.stackArray[i];
    
  }
 
  top = obj.top;  
  
}

Stack& Stack::operator=(const Stack &rhs)
{
 
  if(this!= &rhs){
    
    delete [] stackArray;
    
    stackSize = rhs.stackSize;
    stackArray = new int[stackSize]; 
    for(int i = 0; i < stackSize; i++){
      stackArray[i] = rhs.stackArray[i];
    }
    top = rhs.top;
  }
  
  return *this;
}
  

Stack::~Stack()
{

  delete [] stackArray;

}

void Stack::push(int num)
{
  if(num % 2 != 0){
    
    if(isFull()){
      resize();
  
    }
 
    stackArray[top] = num;
    top++;
  }
  
}

int Stack::pop()
{

  if(!isEmpty()){
    top--;
   
  }
  else{
    throw EmptyStack{};
 
  }
  return stackArray[top];

}

bool Stack::isEmpty() const
{
  
  return top == 0;
  
}


bool Stack::isFull() 
{
  
  return top == stackSize;
}

void Stack::resize()
{
 
  stackSize = stackSize * 1.5;
  int* temp = new int[stackSize];
  for(int i = 0; i < top; i++){
    temp[i] = stackArray[i];
   
  }
  
  delete [] stackArray;
  stackArray = temp;

  
 
}
