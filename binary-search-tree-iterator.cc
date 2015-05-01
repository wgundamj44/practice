/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "TreeNode.h"
#include <stack>
using namespace std;
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        traverseLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !path.empty();
    }

    /** @return the next smallest number */
    int next() {
        auto node = path.top();
        path.pop();
        traverseLeft(node->right);
        return node->val;
    }
private:
    void traverseLeft(TreeNode* current) {
        if (current == nullptr) {
            return;
        }
        path.push(current);
        while(current->left) {
            path.push(current->left);
            current = current->left;
        }
    }
    stack<TreeNode*> path;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
