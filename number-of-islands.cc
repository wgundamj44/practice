class Solution {
public:
  //check
  int numIslands(vector<vector<char>>& grid) {
    int h= grid.size();
    if (h == 0) return 0;
    int w = grid[0].size();
    int ret = 0;
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if (grid[i][j] == '0') continue;
        if (grid[i][j] == '1') {
          cout << i << " " << j << endl;
          ret++;
          queue<tuple<int, int>> q;
          q.push(make_tuple(i, j));
          grid[i][j] = '2';
          while(!q.empty()) {
            int ii, jj;
            tie(ii, jj) = q.front();
            q.pop();
            if (jj + 1 < w && grid[ii][jj+1] == '1') {
              grid[ii][jj+1] = '2';
              q.push(make_tuple(ii, jj + 1));
            }
            if (jj - 1 >= 0 && grid[ii][jj-1] == '1') {
              grid[ii][jj-1] = '2';
              q.push(make_tuple(ii, jj - 1));
            }
            if (ii - 1 >= 0 && grid[ii-1][jj] == '1') {
              grid[ii-1][jj] = '2';
              q.push(make_tuple(ii - 1, jj));
            }
            if (ii + 1 < h && grid[ii+1][jj] == '1') {
              grid[ii+1][jj] = '2';
              q.push(make_tuple(ii +1 ,jj));
            }
          }
        }
      }
    }
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if (grid[i][j] == '2') grid[i][j] = '1';
      }
    }
    return ret;
  }
};
