class Solution {
public:
  //check
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> cur;
    DFS(k, n, 0, cur, res);
    return res;
  }

  void DFS(int k, int n, int sum, vector<int>& cur, vector<vector<int>>& res) {
    int s = cur.size() ? cur.back() + 1 : 1;
    for(int i = s; i <= 9 - (k - cur.size() - 1); i++) {
      if (cur.size() + 1 == k) {
        if (sum + i == n) {
          cur.push_back(i);
          res.push_back(cur);
          cur.pop_back();
        } else {
          continue;
        }
      } else {
        if (sum + i >= n) {
          return;
        } else {
          cur.push_back(i);
          DFS(k, n, sum + i, cur, res);
          cur.pop_back();
        }
      }
    }
  }
};
