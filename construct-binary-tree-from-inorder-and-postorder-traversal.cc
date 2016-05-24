class Solution {
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);

  }

  TreeNode* build(vector<int>& inorder, int b1, int e1, vector<int>& postorder, int b2, int e2) {
    if (b1 > e1) return nullptr;
    int val = postorder[e2];
    int i;
    for(i = b1; i <= e1; i++) {
      if (inorder[i] == val) break;
    }
    TreeNode* root = new TreeNode(val);
    root->left = build(inorder, b1, i - 1, postorder, b2, b2 + i - b1 - 1);
    root->right = build(inorder, i + 1, e1, postorder, b2 + i - b1, e2 - 1);
    return root;
  }
};
