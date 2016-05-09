class Solution {
public:
  //check
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int h = matrix.size();
    if (h == 0) return false;
    int w= matrix[0].size();
    return search(matrix, 0, 0, h-1, w-1, target);
  }

  bool search(vector<vector<int>>& matrix, int i, int j, int h, int w, int target) {
    if (i > h || j > w) return false;
    if (h == i) {
      int s = j, e = w;
      while(s <= e) {
        int m = (s + e) / 2;
        if (target > matrix[i][m]) {
          s = m + 1;
        } else if (target < matrix[i][m]) {
          e = m - 1;
        } else {
          return true;
        }
      }
      return false;
    }
    if (w == j) {
      int s = i, e = h;
      while(s <= e) {
        int m = (s + e) / 2;
        if (target > matrix[m][j]) {
          s = m + 1;
        } else if (target < matrix[m][j]) {
          e = m - 1;
        } else {
          return true;
        }
      }
      return false;
    }
    if (matrix[i][j] == target) return true;
    int ii = i, jj = j;
    while (matrix[ii][jj] < target) {
      if (ii == h && jj == w) return false;
      else if (ii == h) return search(matrix, i, jj + 1, h, w, target);
      else if (jj == w) return search(matrix, ii + 1, j, h, w, target);
      ii++;
      jj++;
    }
    if (matrix[ii][jj] == target) return true;
    return search(matrix, ii, j, h, jj - 1, target) || search(matrix, i, jj, ii - 1, w, target);
  }
};
