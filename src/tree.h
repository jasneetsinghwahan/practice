#ifndef TREE_H
#define TREE_H

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left_ptr, TreeNode *right_ptr)
      : val(x), left(left_ptr), right(right_ptr) {}
};

class Tree {
public:
  Tree() { root_ = nullptr; }
  bool empty();
  int size();
  void InOrder(TreeNode *start);
  void PreOrder(TreeNode *start);
  void PostOrder(TreeNode *start);
  TreeNode *Find(TreeNode *start, int val){
    if(start == nullptr){
      return nullptr;
    }
    if(start->val == val){
      return start;
    }

    // Homework: complete the following two lines.
    Find(start->left, val);
    Find(start->right, val);

    return nullptr;

  }
  void CreateSampleTree1();
  void CreateSampleTree2();
  TreeNode *returnroot(); // returns the root node
  int kthsmallestelement(int k);
  TreeNode *root_;
};

#endif