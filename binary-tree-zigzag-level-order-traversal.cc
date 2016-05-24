class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<TreeNode*> level;
    bool forward = true;
    level.push_back(root);
    vector<vector<int>> res;
    if (!root) return res;
    while(!level.empty()) {
      vector<int> row;
      if (forward) {
        for(auto it = level.begin(); it != level.end(); it++) {
          row.push_back((*it)->val);
        }
      } else {
        for(auto it = level.rbegin(); it != level.rend(); it++) {
          row.push_back((*it)->val);
        }
      }
      res.push_back(row);
      vector<TreeNode*> next;
      for(auto it = level.begin(); it != level.end(); it++) {
        if ((*it)->left) {
          next.push_back((*it)->left);
        }
        if ((*it)->right) {
          next.push_back((*it)->right);
        }
      }
      level = next;
      forward = !forward;
    }
    return res;
  }
};
