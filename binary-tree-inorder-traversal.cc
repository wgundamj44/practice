#include "TreeNode.h"
#include<iostream>
using namespace std;

class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    // iteratively
    vector<int> res;
    TreeNode* p = root;
    while(p) {
      if (p->left == nullptr) {
	res.push_back(p->val);
	p = p->right;
	continue;
      }
      TreeNode* p1 = p->left;
      
      while(p1->right) {
	if (p1->right == p) {
	  break;
	}
	p1 = p1->right;
      }
      //left subtree visisted
      if (p1->right == p) {
	res.push_back(p->val);
	p = p->right;
	p1->right = nullptr;
      } else {
	p1->right = p;
	p = p->left;
      }
    }

    return res;
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  TreeNode* p = new TreeNode(2);
  root->left = p;
  Solution* s = new Solution();
  auto res = s->inorderTraversal(root);
  for(auto v : res) cout << v << " ";
}
