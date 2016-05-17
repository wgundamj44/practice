class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    vector<TreeNode*> cur, pre;
    vector<int> res;
    if (!root) return res;
    cur.push_back(root);
    while(cur.size() != 0) {
      res.push_back((*cur.rbegin())->val);
      for(auto it = cur.begin(); it != cur.end(); it++) {
        if ((*it)->left) pre.push_back((*it)->left);
        if ((*it)->right) pre.push_back((*it)->right);
      }
      cur = pre;
      pre.clear();
    }
    return res;
  }
};
