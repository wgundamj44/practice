class Solution {
public:
  //check: ac!
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int h = matrix.size();
    if (h == 0) return res;
    int w=  matrix[0].size();
    if (w == 0) return res;
    int x = 0, y = 0;
    while(h > 0 && w > 0) {
      for(int i = 0; i < w; i++) {
        res.push_back(matrix[y][x + i]);
      }
      for(int i = 1; i < h; i++) {
        res.push_back(matrix[y + i][x + w - 1]);
      }
      if (h != 1) {
        for(int i = w - 2; i >= 0; i--) {
          res.push_back(matrix[y + h - 1][x + i]);
        }
      }
      if (w != 1) {
        for(int i = h - 2; i > 0; i--) {
          res.push_back(matrix[y + i][x]);
        }
      }
      h -= 2;
      w -= 2;
      x += 1;
      y += 1;
    }
    return res;
  }
};
