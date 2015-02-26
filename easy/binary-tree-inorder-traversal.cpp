#include<vector>
#include "../TreeNode.h"
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> t;
        if (root == NULL) {
            return t;
        }
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        if (left.size()) {
            t.insert(t.end(), left.begin(), left.end());
        }
        t.push_back(root->val);
        if (right.size()) {
            t.insert(t.end(), right.begin(), right.end());
        }
        
        return t;
    }
};
