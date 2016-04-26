//check
class NumMatrix {
  vector<vector<int>> cache;
public:
  NumMatrix(vector<vector<int>> &matrix) {
    for(int i = 0 ;i < matrix.size(); i++) {
      for(int j = 0; j < matrix[0].size(); j++) {
        if (j == 0) {
          cache.push_back(vector<int>(matrix[0].size(), 0));
          cache[i][j] = i == 0 ? matrix[i][j] : cache[i-1][j] + matrix[i][j];
        } else {
          if (i == 0) {
            cache[i][j] = cache[i][j-1] + matrix[i][j];
          } else {
            cache[i][j] = cache[i-1][j] + cache[i][j-1] + matrix[i][j] - cache[i-1][j-1];
          }
        }
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    if (col1 == 0 && row1 == 0) {
      return cache[row2][col2];
    } else if (row1 == 0) {
      return cache[row2][col2] - cache[row2][col1 - 1];
    } else if (col1 == 0) {
      return cache[row2][col2] - cache[row1 - 1][col2];
    } else {
      return cache[row2][col2] - cache[row1 - 1][col2] - cache[row2][col1-1] + cache[row1-1][col1-1];
    }
  }
};
