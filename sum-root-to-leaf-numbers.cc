class Solution {
public:
  int sumNumbers(TreeNode* root) {
    int sum = 0;
    if (!root) return 0;
    traverse(root, sum, 0);
    return sum;
  }

  void traverse(TreeNode* root, int& sum, int val) {
    if (!root->left && !root->right) {
      val = val * 10 + root->val;
      sum += val;
      return;
    }
    if (root->left) {
      traverse(root->left, sum, val * 10 + root->val);
    }
    if (root->right) {
      traverse(root->right, sum, val * 10 + root->val);
    }
  }
};
