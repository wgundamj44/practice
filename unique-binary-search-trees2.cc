#include "TreeNode.h"
#include<iostream>
using namespace std;

class Solution {
public:
  vector<TreeNode*> generateTrees(int n) {
    return generate(1, n);
  }

  vector<TreeNode*> generate(int b, int e) {
    vector<TreeNode*> res;
    if (b > e) {
      return res;
    }
    for (int i = b; i <= e; i++) {
      vector<TreeNode*> leftTrees = generate(b, i - 1);
      vector<TreeNode*> rightTrees = generate(i + 1, e);
      if (leftTrees.size() == 0) {
	leftTrees.push_back(nullptr);
      }
      if (rightTrees.size() == 0) {
	rightTrees.push_back(nullptr);
      }
      for(auto left : leftTrees) {
	for(auto right : rightTrees) {
	  TreeNode* root = new TreeNode(i);
	  root->left = left;
	  root->right = right;
	  res.push_back(root);
	}
      }
    }
    return res;
  }
};
