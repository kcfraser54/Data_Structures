// Kyle Fraser
// Tree.cpp
// implementation file for tree described in Tree.h


#include "tree.h"
#include <stack>
#include <iostream>
using namespace std;

Tree::Tree()
{

  root = nullptr;
 
}

Tree::~Tree()
{

  deleteTree(root);

}


Tree::Tree(const Tree &obj)
{
  if(obj.root == nullptr){
    root = nullptr;
  }
  else{
    root = copyTree(obj.root);
  }
}

Tree& Tree::operator=(const Tree &rhs)
{
  if(this != &rhs){
    deleteTree(root);
    root = copyTree(rhs.root);
  }

  return *this;
  
}

bool Tree::insertValue(int num)
{
  
  return insertValue(root, num);
}

bool Tree::findKey(int num)
{

  return findKey(root, num);


}

int Tree::findMinKey()
{
  
  return findMinKey(root);

}

int Tree::findHeight()
{
  return findHeight(root);

}

void Tree::preOrder()
{

  preOrder(root);

}

void Tree::inOrder()
{
  stack<TreeNode*> s;

  TreeNode* current = root;

  while(current != nullptr || !s.empty()){


    while(current != nullptr){
      
      s.push(current);
      current = current->left;
    }

    current = s.top();
    s.pop();

    cout << current->key << ' ';
    current = current->right;

  }
  
}

void Tree::deleteTree(TreeNode*& r)
{
  if(r != nullptr){
    deleteTree(r->left);
    deleteTree(r->right);
    delete r;
    r = nullptr;
  }
  
}

Tree::TreeNode* Tree::copyTree(TreeNode* r)
{
  if(r == nullptr){
    return nullptr;
  }

  else{
    TreeNode* temp = new TreeNode;
    temp->key = r->key;
    temp->left = copyTree(r->left);
    temp->right = copyTree(r->right);
    return temp;
  }

}

bool Tree::insertValue(TreeNode*& r, int k)
{

  if(r == nullptr){
    r = new TreeNode;
    r->key = k;
    r->left = nullptr;
    r->right = nullptr;
    return true;
  }

  else if(r->key == k){
    return false;
  }

  else if(r->key > k){
    return insertValue(r->left, k);

  }

  else{

    return insertValue(r->right, k);

  }

}

bool Tree::findKey(TreeNode* r, int k)
{
  if(r == nullptr){
    return false;
  }

  else if(r->key == k){
    return true;
  }

  else if(r->key > k){
    return findKey(r->left, k);
  }
  else{
    return findKey(r->right, k);

  }
}

int Tree::findMinKey(TreeNode* r)
{
  
  int small = r->key;
  if(r->left != nullptr){
    small = findMinKey(r->left);
  }

  return small;
}

int Tree::findHeight(TreeNode* r)
{
  

 
  if(r == nullptr){
    return 0;
  }
  else{
    int lHeight = findHeight(r->left);
    int rHeight = findHeight(r->right);

    if(lHeight > rHeight){
      return 1 + lHeight;
    }
    else{
      return 1 + rHeight; 
    }
    
  }

}

void Tree::preOrder(TreeNode* r)
{

  if(r != nullptr){

    cout << r->key << ' ';
    preOrder(r->left);
    preOrder(r->right);

  }

}










