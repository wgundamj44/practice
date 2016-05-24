class Solution {
  TreeNode* first = nullptr;
  TreeNode* second = nullptr;
  TreeNode* pre = nullptr;
public:
  //check: inorder sequence
  void recoverTree(TreeNode* root) {
    traverse(root);
    swap(first->val, second->val);
  }

  void traverse(TreeNode* root) {
    if (!root) return;
    traverse(root->left);
    if (!first && pre && pre->val > root->val) first = pre;
    if (first && pre->val > root->val) second = root;
    pre = root;
    traverse(root->right);
    
  }
};
