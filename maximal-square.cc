class Solution {
public:
  //check
  int maximalSquare(vector<vector<char>>& matrix) {
    int ret = 0;
    int h = matrix.size();
    if (h == 0) return 0;
    int w = matrix[0].size();
    vector<vector<int>> res(h + 1, vector<int>(w + 1, 0));
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if (matrix[i][j] == '0') res[i+1][j+1] = 0;
        else {
          res[i+1][j+1] = 1 + min({res[i][j], res[i][j+1], res[i+1][j]});
        }
        ret = max(ret, res[i+1][j+1]);
      }
    }
    return ret * ret;
  }
};
