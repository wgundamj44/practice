#include "../TreeNode.h"
using namespace std;

class Solution {
public:
  bool isBalanced(TreeNode* root) {
    int height = 0;
    return traverse(root, height);
  }

  bool traverse(TreeNode* root, int&  height) {
    if (root) {
      int heightLeft = height, heightRight = height;
      if (!traverse(root->left, heightLeft)) return false;
      if (!traverse(root->right, heightRight)) return false;
      if (abs(heightLeft - heightRight) > 1) return false;
      height = max(heightLeft, heightRight) + 1;
      return true;
    } else {
      return true;
    }
  }
};
