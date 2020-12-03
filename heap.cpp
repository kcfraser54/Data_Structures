// Kyle Fraser
// heap.cpp
// Implementation file for heap described in heap.h.
// No inputs or outputs in heap implementation file.

#include "heap.h"

Heap::Heap()
{
  heapSize = 10;
  heapArray = new int[heapSize];
  heapCount = 0;
}

Heap::~Heap()
{
  
  delete [] heapArray;
  
}

Heap::Heap(const Heap &obj)
{
  heapSize = obj.heapSize;
  heapArray = new int[obj.heapSize];
  for(int i = 0; i < heapSize; i++){
    heapArray[i] = obj.heapArray[i];
  }

  heapCount = obj.heapCount;;
  
}

Heap& Heap::operator=(const Heap &rhs)
{

  if(this != &rhs){
    delete [] heapArray;
    heapArray = new int[rhs.heapSize];
    heapSize = rhs.heapSize;
    for(int i = 0; i < heapSize; i++){
      heapArray[i] = rhs.heapArray[i];
    }
    
    heapCount = rhs.heapCount;

  }

  return *this;

}

void Heap::insert(int val)
{

  if(isFull()){
    resize();
  }

  int hole = ++heapCount;
  while(hole > 1 && val < heapArray[hole/2]){
    heapArray[hole] = heapArray[hole/2];
    hole = hole/2;

  }

  heapArray[hole] = val;
}

int Heap::remove()
{

  if(!isEmpty()){
    
    int val = heapArray[1];
    heapArray[1] = heapArray[heapCount];
    heapCount--;
    percDown(1);
    return val;
    
  }
  else{
    throw EmptyHeap{};
  }

}

void Heap::percDown(int start)
{
  
  int temp = heapArray[start];
  int hole = start; 

  while((hole*2 <= heapCount && temp > heapArray[hole*2]) || (hole*2+1 <=
                               heapCount && temp > heapArray[hole*2+1])){
    
    if(hole*2+1 <= heapCount && heapArray[hole*2+1] < heapArray[hole*2]){
      heapArray[hole] =heapArray[hole*2+1];
      hole = hole*2+1;
    }

    else{
      heapArray[hole] = heapArray[hole*2];
      hole = hole*2;
    }

  }

  heapArray[hole] = temp;
      
}


void Heap::flush(int val)
{
  
  if(heapArray[1] == val){
    remove();
  }

  for(int i = 1; i < heapCount + 1; i++){
    
    if(heapArray[i] == val){

      heapArray[i] = heapArray[1];
      remove();
      i--;
      
    }
  }
}

void Heap::resize()
{
 
  heapSize = heapSize * 1.5;
  int* temp = new int[heapSize];
  for(int i = 1; i < heapCount + 1; i++){
    temp[i] = heapArray[i];
  }

  delete heapArray;
  heapArray = temp;
}

bool Heap::isFull() const
{

  return heapCount == heapSize;

}

bool Heap::isEmpty() const
{

  return heapCount == 0;

}
