class Solution {
public:
  int countNodes(TreeNode* root) {
    auto p = root;
    int left = 0;
    int right = 0;
    while(p) {
      left++;
      p = p->left;
    }
    p = root;
    while(p) {
      right++;
      p = p->right;
    }
    if (left == right) {
      return left >0 ? pow(2, left) - 1 : 0;
    } else {
      return countNodes(root->left) + countNodes(root->right) + 1;
    }
  }
};
