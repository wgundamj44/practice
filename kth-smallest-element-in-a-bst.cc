class Solution {
public:
  int kthSmallest(TreeNode* root, int k) {
    int i = 0;
    return search(root, k, i)->val;
  }

  TreeNode* search(TreeNode* root, int k, int& index) {
    if(root->left) {
      TreeNode* ret = search(root->left, k, index);
      if(ret) return ret;
    }
    index++;
    if (index == k) return root;
    if(root->right) {
      TreeNode* ret = search(root->right, k, index);
      if (ret) return ret;
    }
    return nullptr;
  }
};
