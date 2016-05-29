class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    while(root) {
        if (root->left) {
          auto p = root->left;
          while(p->right && p->right != root) p = p->right;
          if (!p->right) {
            p->right = root;
            res.push_back(root->val);
            root = root->left;
          } else {
            p->right = nullptr;
            root = root->right;
          }
        } else {
          res.push_back(root->val);
          root = root->right;
        }
    }
    return res;
  }
};
