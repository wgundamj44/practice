#include "TreeNode.h"
#include<algorithm>
using namespace std;

class Solution {
public:
  //check: clear thought
  int maxPathSum(TreeNode* root) {
    int maxRoot, maxPath;
    if (!root) return 0;
    tie(maxRoot, maxPath) = traverse(root);
    return max(maxRoot, maxPath);
  }

  tuple<int, int> traverse(TreeNode* root) {
    int leftRoot, leftPath, rightRoot, rightPath;
    if (!root->left && !root->right) return make_tuple(root->val, root->val);
    if (root->left && root->right) {
      tie(leftRoot, leftPath) = traverse(root->left);
      tie(rightRoot, rightPath) = traverse(root->right);
      vector<int> v1 = {leftRoot + root->val, rightRoot + root->val, root->val};
      auto it1 = max_element(v1.begin(), v1.end());
      vector<int> v2 = {leftPath, rightPath, *it1, leftRoot + root->val + rightRoot, root->val};
      auto it2 = max_element(v2.begin(), v2.end());
      return make_tuple(*it1, *it2);
    } else if (root->left) {
      tie(leftRoot, leftPath) = traverse(root->left);
      int maxRoot = max(leftRoot + root->val, root->val);
      vector<int> v = {leftPath, maxRoot, leftRoot + root->val, root->val};
      auto it = max_element(v.begin(), v.end());
      return make_tuple(maxRoot, *it);
    } else {
      tie(rightRoot, rightPath) = traverse(root->right);
      int maxRoot = max(rightRoot + root->val, root->val);
      vector<int> v = {rightPath, maxRoot, rightRoot + root->val, root->val};
      auto it = max_element(v.begin(), v.end());
      return make_tuple(maxRoot, *it);
    }
  }
};


int main() {
  Solution s;
  TreeNode* t = new TreeNode(-3);
  cout << s.maxPathSum(t) << endl;
}
