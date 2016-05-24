class Solution {
public:
  void flatten(TreeNode* root) {
    if (!root) return;
    TreeNode* tail = root;
    if (root->left) {
      TreeNode* p = root->left;
      while(p->left || p->right) {
        if (p->right) p = p->right;
        else p = p->left;
      }
      tail = p;
      flatten(root->left);
      TreeNode* right = root->right;
      root->right = root->left;
      root->left = nullptr;
      flatten(right);
      tail->right = right;
    } else {
      flatten(root->right);
    }

  }
};
