class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int len = triangle.size();
    if (len == 0) return 0;
    vector<int> res = vector<int>(0, len);
    for(auto it = triangle.rbegin(); it != triangle.rend(); it++) {
      if (it == triangle.rbegin()) {
        res = *it;
      } else {
        for(int i = 0; i < it->size(); i++) {
          res[i] = min((*it)[i] + res[i], (*it)[i] + res[i+1]);
        }
      }
    }
    return res[0];
  }
};
