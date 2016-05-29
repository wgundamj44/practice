#include "TreeNode.h"

class Solution {
public:
    //check: Do mirror of preorder traversal
    vector<int> postorderTraversal(TreeNode* root) {
          list<int> res;
          while(root) {
            auto p = root;
            if (p->right) {
              p = p->right;
              while(p->left && p->left != root) p = p->left;
              if (!p->left) {
                p->left = root;
                res.push_front(root->val);
                root = root->right;
              } else {
                p->left = nullptr;
                root = root->left;
              }
            } else {
              res.push_front(root->val);
              root = root->left;
            }
          }
          return vector<int>(res.begin(), res.end());
    }
};
