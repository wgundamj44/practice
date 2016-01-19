#include"TreeNode.h"
using namespace std;

class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
  }

  TreeNode* build(vector<int>& preorder, int b1, int e1, vector<int>& inorder, int b2, int e2) {
    if (b1 > e1) return nullptr;
    TreeNode* root = new TreeNode(preorder[b1]);
    int i;
    for(i = b2; i <= e2; i++) {
      if (inorder[i] == preorder[0]) {
	break;
      }
    }
    if (i > b2) {
      root->left = build(preorder, b1 + 1, b1 + i, inorder, b2, b2 + i - 1);
    }
    if (i < e2) {
      root->right = build(preorder, b1 + i + 1, e1, inorder, b2 + i + 1, e2);
    }
 
    return root;
  }

};
