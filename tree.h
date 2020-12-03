// Kyle Fraser
// Tree specification file


#ifndef TREE_H
#define TREE_H

class Tree
{

 public:
  
  Tree();
  // Constructor allocates memory and initializes
  // variables for an instance of the tree object.
  
  ~Tree();
  // Destructor deallocates memory for an instance
  // of the tree object
  
  Tree(const Tree &obj);
  // Copy constructor uses data stored in another
  // tree object to allocate memory and initialize
  // variables for a new tree object.
  
  Tree& operator=(const Tree& rhs);
  // Overloaded assignment operator overwrites data
  // from one instance of a tree to another instance
  // of a tree object.
  
  bool insertValue(int num);
  // Pre: Requires an integer to be inserted as a parameter.
  
  // Post: A value is inserted into a binary search tree.
  
  bool findKey(int num);
  // Pre: Requires an integer to search for as a parameter.
  
  // Post: Returns whether the integer is present in the tree.
  
  int findMinKey();
  // Pre: Requires an available root node for a binary search tree.
  
  // Post: Returns the minimum value in the tree.
  
  int findHeight();
  // Pre: Requires an available root node for a binary search tree.
  
  // Post: Returns the height of the binary search tree.
  
  void preOrder();
  // Pre: Requires an available root node for a binary search tree.
  
  // Post: The contents of a binary search tree are printed using
  // a preorder traversal.
  
  void inOrder();
  // Pre: Requires an available root node for a binary search tree.
  
  // Post: The contents of a binary search tree are printed in order.

 private:

  struct TreeNode
  {
    int key;
    TreeNode* left;
    TreeNode* right;
  };

  void deleteTree(TreeNode*& r);
  // Pre: Requires a reference pointer to the binary tree
  // as a parameter.
  
  // Post: Memory for the tree is deallocated.
  
  TreeNode* copyTree(TreeNode* r);
  // Pre: Requires a pointer to the binary search tree as
  // a parameter.
  
  // Post: A binary tree instance is copied into another
  // instance of a binary tree.
  
  bool insertValue(TreeNode*& r, int k);
  // Pre: Requires a reference pointer to a binary search tree
  // and an integer to be inserted into the tree as parameters.
  
  // Post: An integer is entered into the binary search tree.
  
  bool findKey(TreeNode* r, int k);
  // Pre: Requires a pointer to a binary search tree
  // and an integer to search for in the tree as
  // parameters.
  
  // Post: Returns whether the integer is present in the tree.
  
  int findMinKey(TreeNode* r);
  // Pre: Requires a pointer to a binary search tree
  // as a parameter.
  
  // Post: Returns the minimum value in the tree.
  
  int findHeight(TreeNode* r);
  // Pre: Requires a pointer to a binary search tree
  // as a parameter.
  
  // Post: Returns the height of the tree.
  
  void preOrder(TreeNode* r);
  // Pre: Requires a pointer to a binary search tree.
  
  // Post: Prints the contents of the tree using a
  // preorder traversal.

  TreeNode* root; 

  
};

#endif
