class Solution {
public:
  //check
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int h = matrix.size();
    if (h == 0) return 0;
    int w = matrix[0].size();
    vector<vector<int>> res = vector<vector<int>>(h, vector<int>(w, -1));
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        DFS(matrix, res, i, j);
      }
    }
    int m = 0;
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if (res[i][j] > m) m = res[i][j];
      }
    }
    return m;
  }

  void DFS(vector<vector<int>>& matrix, vector<vector<int>>& res, int i, int j) {
    if (res[i][j] != -1) return;
    pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int r = 0;
    for(auto p : dir) {
      int ii = i + p.first, jj = j + p.second;
      if (ii < matrix.size() && ii >= 0 && jj < matrix[0].size() && jj >=0 && matrix[ii][jj] > matrix[i][j]) {
        DFS(matrix, res, ii, jj);
        if (res[ii][jj] > r) r = res[ii][jj];
      }
    }
    res[i][j] = r == 0 ? 1 : r + 1;
  }
};
