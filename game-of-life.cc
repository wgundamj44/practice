class Solution {
public:
  void gameOfLife(vector<vector<int>>& board) {
    int h = board.size();
    if (h == 0) return;
    int w = board[0].size();
    if (w == 0) return;
    vector<int> pre, current;
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        int live = 0;
        if (i - 1 >= 0 && (board[i-1][j] == 1 || board[i-1][j] == 2)) {
          live++;
        }
        if (i + 1 < h && (board[i+1][j] == 1 || board[i+1][j] == 2)) {
          live++;
        }
        if (j - 1 >= 0 && (board[i][j-1] == 1 || board[i][j-1] == 2)) {
          live++;
        }
        if (j + 1 < w && (board[i][j+1] == 1 || board[i][j+1] == 2)) {
          live++;
        }
        if (i - 1 >= 0 && j - 1 >= 0 && (board[i-1][j-1] == 1 || board[i-1][j-1] == 2)) {
          live++;
        }
        if (i - 1 >= 0 && j + 1 < w && (board[i-1][j+1] == 1 || board[i-1][j+1] == 2)) {
          live++;
        }
        if (i + 1 < h && j -1 >= 0 && (board[i+1][j-1] == 1 || board[i+1][j-1] == 2)) {
          live++;
        }
        if (i + 1 < h && j + 1 < w && (board[i+1][j+1] == 1 || board[i+1][j+1] == 2)) {
          live++;
        }
        if (board[i][j] == 1) {
          if (live < 2) {
            board[i][j] = 2;
          } else if (live > 3) {
            board[i][j] = 2;
          }
        } else {
          if (live == 3) board[i][j] = 3;
        }
      }
    }
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if (board[i][j] == 2) {
          board[i][j] = 0;
        }
        if (board[i][j] == 3) {
          board[i][j] = 1;
        }
      }
    }
  }
};
