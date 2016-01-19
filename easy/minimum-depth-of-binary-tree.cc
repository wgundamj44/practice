#include "../TreeNode.h"
using namespace std;

class Solution {
public:
  int minDepth(TreeNode* root) {
    if(!root) return 0;
    int height = 0;
    traverse(root, height);
    return height;
  }

  void traverse(TreeNode* root, int& height) {
    if (!root->left && !root->right) {
      height += 1;
      return;
    }
    if(root->left && root->right) {
      int heightLeft = height, heightRight = height;
      traverse(root->left, heightLeft);
      traverse(root->right, heightRight);
      height = min(heightLeft, heightRight) + 1;
      return;
    }
    TreeNode* node = root->left ? root->left : root->right;
    if(node) {
      int heighttmp = height;
      traverse(node, heighttmp);
      height = heighttmp + 1;
      return;
    }

  }
};
