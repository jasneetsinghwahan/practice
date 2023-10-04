#include "tree.h"

#include <iostream>
#include <stack>

bool Tree::empty() { return root_ == nullptr; }

int Tree::size() {
  // Incomplete!
  return 0;
}

// Inorder (LNR): Left, Node, Right
void Tree::InOrder(TreeNode *start) {
  if (start == nullptr) {
    return;
  }

  InOrder(start->left);
  std::cout << "val: " << start->val << std::endl;
  InOrder(start->right);
};

// Preorder (NLR): Node, Left, Right.
void Tree::PreOrder(TreeNode *start) {
  if (start == nullptr) {
    return;
  }

  std::cout << "val: " << start->val << std::endl;
  PreOrder(start->left);
  PreOrder(start->right);
};

// LRN
void Tree::PostOrder(TreeNode *start) {
  if (start == nullptr) {
    return;
  }

  PostOrder(start->left);
  PostOrder(start->right);
  std::cout << "val: " << start->val << std::endl;
};

void Tree::CreateSampleTree1() {
  root_ = new TreeNode(60, new TreeNode(20), new TreeNode(80));
}

void Tree::CreateSampleTree2() {
  root_ = new TreeNode(
      60,
      new TreeNode(20, new TreeNode(10),
                   new TreeNode(30, new TreeNode(25), new TreeNode(50))),
      new TreeNode(80));
}

TreeNode*
Tree::returnroot(){
    return root_;
}

/**
 * for finding the first smallest element, k should be 1
*/
int
Tree::kthsmallestelement(int k){
    std::stack<TreeNode *> s;
    TreeNode *temp = root_;
    while (temp != nullptr || (!s.empty())){
        while (temp != nullptr) {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        k -= 1;
        if (k == 0)
            break;
        temp = temp->right;
    }
    return temp->val;

}
