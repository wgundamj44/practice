class Solution {
public:
  void solve(vector<vector<char>>& board) {
    if(board.size() == 0) return;
    int h = board.size();
    if(board[0].size() == 0) return;
    int w = board[0].size();
    for(int i = 0; i < w; i++) {
      BFS(i, 0, board, w, h);
      BFS(i, h-1, board, w, h);
    }
    for(int i = 0; i < h; i++) {
      BFS(0, i, board, w, h);
      BFS(w -1 , i, board, w, h);
    }
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if (board[i][j] == 'O') board[i][j] = 'X';
        if (board[i][j] == '-') board[i][j] = 'O';
      }
    }
  }

  void DFS(int i, int j, vector<vector<char>>& board, int w, int h) {
    if(board[j][i] != 'O') return;
    stack<vector<int>> q;
    q.push({i, j});
    board[j][i] = '-';
    while(!q.empty()) {
      auto p = q.top();
      i = p[0];
      j = p[1];
      q.pop();
      if(i + 1 < w && board[j][i+1] == 'O') {
        q.push({i + 1, j});
        board[j][i+1] = '-';
      }
      if(i - 1 >=0 && board[j][i-1] == 'O') {
        q.push({i - 1, j});
        board[j][i-1] = '-';
      }
      if(j + 1 < h && board[j+1][i] == 'O') {
        q.push({i, j + 1});
        board[j+1][i] = '-';
      }
      if(j - 1 >=0 && board[j-1][i] == 'O') {
        q.push({i, j - 1});
        board[j-1][i] = '-';
      }
    }
  }

};
