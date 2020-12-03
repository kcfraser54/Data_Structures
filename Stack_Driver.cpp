// Kyle Fraser
// p1.cpp
// 4/10/18

// Purpose: Creates a stack test program which tests all
// necessay functions of a stack which only stores odd integers.
// these include copy constructor,
// overloaded assignment operator, pop, push, isEmpty,
// resize, and isFull.

// Input: Press enter to test, Press enter to pop values.

// Process: Test push and pop, test isEmpty,
// test if stack accepts even integers, test copy constructor,
// test isFull and resize, test overloaded assignment operator.

// Output: Messages to the screen describing the state of
// the tests. Also integers popped from stack.


#include "stack.h"
#include <iostream>
using namespace std;

const int testNum1 = 5;
const int testNum2 = 6;
const int testNum3 = 9;
const int emptyTestNum = 10;

int main()
{

  Stack s1(50);
  Stack s2(6);
  int data;
  int count = 0;
  int test[testNum1];
  int test2[testNum2];
  int test3[testNum2];
  int test4[testNum3];
  int test5[testNum3];
  bool copy = true;

  cout << endl;
  cout << "Press enter to begin the stack test...";
  cin.get();
  cout << endl;

  cout << "Press enter to test push and pop functions...";
  cin.get();
  
  cout << endl << endl;
  cout << "Pushing 5 odd integers onto a stack of size 50...";
  cout << endl << endl;

  data = 1;
  for(int i = 0; i < testNum1; i++){
    s1.push(data);
    data += 2;
  }

  cout << "Expected Output" << endl;
  cout << "---------------" << endl << endl;
  cout << "9 " << endl;
  cout << "7 " << endl;
  cout << "5 " << endl;
  cout << "3 " << endl;
  cout << "1 " << endl;
  cout << endl;
  
  cout << "Press enter to pop all values from the stack...";
  cin.get();
  cout << endl;
  for(int i = 0; i < testNum1; i++){
    test[i] = s1.pop();
    cout << test[i] << endl;
  }
  
  if(test[0] == 9 && test[1] == 7 && test[2] == 5
     && test[3] == 3 && test[4] == 1){

    cout << endl << endl;
    cout << "Push and Pop Test: Success";
    cout << endl << endl << endl;

  }
  else{

    cout << endl;
    cout << "Push and Pop Test: Fail";
    cout << endl;
  }


  cout << "Press enter to test isEmpty function...";
  cin.get();

  cout << endl << endl;
  cout << "Pushing 10 values onto stack s1...";
  data = 15;
  for(int i = 0; i < emptyTestNum; i++){
    s1.push(data);
  }

  cout << endl << endl;
  cout << "Press enter to pop 10 values off of stack s1...";
  cin.get();
  while(!s1.isEmpty()){
    s1.pop();
    count++;
  }

  cout << endl;
  cout << "Expected Result" << endl;
  cout << "---------------" << endl;
  cout << "Stack will be empty after popping 10 times.";
  cout << endl << endl;

  if(s1.isEmpty()){
    cout << endl;
    cout << "isEmpty test: Success";
    cout << endl << endl << endl;
  }

  else{
    cout << endl;
    cout << "isEmpty test: Fail";
    cout << endl << endl << endl;
  }

  
  cout << "Press enter to test even integer push...";
  cin.get();
  cout << endl << endl;
  cout << "Attempting to push 5 even values onto a stack of " << endl;
  cout << "size 50...";
  cout << endl << endl;
  data = 10;
  for(int i = 0; i < testNum1; i++){
    s1.push(data);
    data += 2;
  }

  cout << "Expected Result" << endl;
  cout << "---------------" << endl;
  cout << "Stack will be empty." << endl;
  cout << "Tested by trying to catch EmptyStack exception. ";
  cout << endl << endl;
  cout << "Press enter to test...";
  cin.get();
  cout << endl;
  try{
    s1.pop();
  }
  catch(Stack::EmptyStack){
    cout << "Error: Cannot pop from an empty stack.";
  }

  cout << endl << endl;

  if(s1.isEmpty()){
    cout << endl;
    cout << "Odd integer stack test: Success";
    cout << endl;
  }
  else{
    cout << endl;
    cout << "Odd integer stack test: Fail";
    cout << endl;
  }

  
  cout << endl << endl;
  cout << "Press enter to test the copy constructor...";
  cin.get();

  cout << endl << endl;
  cout << "Pushing 6 integers onto a stack of size 50...";
  cout << endl << endl;
  data = 15;
  for(int i = 0; i < testNum2; i++){
    s1.push(data);
    data += 2;
  }

  cout << "Copying s1 to new instance...";
  cout << endl << endl;
  Stack s3(s1);

  cout << "Expected Result" << endl;
  cout << "---------------" << endl;
  cout << "Values popped off the original and new instance " << endl;
  cout << "will be the same." << endl << endl;

  cout << "Press enter to pop all values from original stack...";
  cin.get();
  cout << endl;
  
  for(int i = 0; i < testNum2; i++){
    test2[i] = s1.pop();
    cout << test2[i] << endl;
  }

  cout << endl;
  cout << "Press enter to pop all values from new instance...";
  cin.get();
  cout << endl;

  for(int i = 0; i < testNum2; i++){
    test3[i] = s3.pop();
    cout << test3[i] << endl;
  }
  count = 0;
  while(count < testNum2 && copy){
    if(test2[count] != test3[count]){
      copy = false;
    }
    count++;
  }

  if(copy){
    cout << endl << endl;
    cout << "Copy constructor test: Success";
    cout << endl << endl << endl;
  }
  else{
    cout << endl << endl;
    cout << "Copy constructor test: Fail";
    cout << endl << endl << endl;
  }

  copy = true;
  cout << "Press enter to to test the isFull and resize functions...";
  cin.get();
  cout << endl << endl;
  cout << "Pushing 9 values onto stack(s2) of size 6...";
  cout << endl << endl;
  data = 5;
  for(int i = 0; i < testNum3; i++){
    s2.push(data);
    data += 2;
  }

  cout << "Expected Output" << endl;
  cout << "---------------" << endl << endl;
  data -=2;
  for(int i = 0; i < testNum3; i++){
    cout << data << endl;
    data -= 2;
  }
  
  cout << endl;
  count = 0;
  cout << "Press enter to pop values from s2...";
  cin.get();
  cout << endl;
  while(!s2.isEmpty()){
    cout << s2.pop() << endl;
    count++;
  }

  if(count == testNum3){
    cout << endl;
    cout << "isFull and resize test: Success";
    cout << endl;
  }
  
  else{
    cout << endl;
    cout << "isFull and resize test: Fail";
    cout << endl;
  }
  count = 0;
  cout << endl;
  cout << "Press enter to test the overloaded assignment operator...";
  cin.get();

  cout << endl << endl;
  cout << "Pushing 9 values onto s2...";
  cout << endl << endl;
  data = 5;
  for(int i = 0; i < testNum3; i++){
    s2.push(data);
    data += 2;
  }
  
  cout << "Copying s2 into s1 using the overloaded " << endl;
  cout << "assignment operator..." << endl;

  s1 = s2;

  cout << endl;
  cout << "Expected Result" << endl;
  cout << "---------------" << endl;
  cout << "Values popped from s1 will be the same as " << endl;
  cout << "values popped from s2." << endl;

  cout << endl;
  cout << "Press enter to pop values from s2...";
  cin.get();
  cout << endl;
  while(!s2.isEmpty()){
    test4[count] = s2.pop();
    cout << test4[count] << endl;
    count++;
  }


  count = 0;
  cout << endl;
  cout << "Press enter to pop values from s1...";
  cin.get();
  cout << endl;
  while(!s1.isEmpty()){
    test5[count] = s1.pop();
    cout << test5[count] << endl;
    count++;
  }
  count = 0;
  while(count < testNum3 && copy){
    if(test4[count] != test5[count]){
      copy = false;
    }
    count++;
  }

  if(copy){
    cout << endl;
    cout << "Overloaded assignment operator test: Success";
    cout << endl;
  }

  else{
    cout << endl;
    cout << "Overloaded assignment operator test: Fail";
    cout << endl;
  }

 

  cout << endl;
  cout << "Testing finished.";
  cout << endl << endl;
     

  return 0; 

}
