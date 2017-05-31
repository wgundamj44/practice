#include "common.h"
using namespace std;

class Solution {
public:
  //check
  vector<vector<string>> solveNQueens(int n) {
    vector<int> current;
    vector<vector<string>> res;
    DFS(0, res, current, n);
    return res;
  }

  bool isValid(vector<int>& current, int i, int j, int n) {
    for(int k = 0; k < i; k++) {
      if (current[k] == j) {
        return false;
      }
    }
    for(int k = i-1, z = j-1; k < n && k >= 0 && z < n && z >=0; k=k-1, z=z-1) {
      if (current[k] == z) return false;
    }
    for(int k = i-1, z = j+1; k < n && k >= 0 && z < n && z >=0; k=k-1, z=z+1) {
      if (current[k] == z) return false;
    }
    return true;
  }

  void DFS(int i, vector<vector<string>>& res, vector<int>& current, int n) {
    if (i == n) {
      vector<string> ret;
      for(int j : current) {
        string tmp = string(n, '.');
        tmp[j] = 'Q';
        ret.push_back(tmp);
      }
      res.push_back(ret);
      return;
    }
    for(int j = 0; j < n; j++) {
      if (!isValid(current, i, j, n)) continue;
      current.push_back(j);
      DFS(i + 1, res, current, n);
      current.pop_back();
    }
  }
};

int main() {
  Solution s;
  auto res = s.solveNQueens(4);
  for (auto v : res) {
    for(string s : v) {
      cout << s << endl;
    }
    cout << endl;
  }
}
