class Solution {
  //check
public:
  bool exist(vector<vector<char>>& board, string word) {
    if (board.size() == 0 || board[0].size() == 0) return false;
    vector<vector<bool>> visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
    for(int i = 0; i < board.size(); i++) {
      for(int j = 0; j < board[0].size(); j++) {
        if(DFS(board, visited, word, 0, i, j)) return true;
      }
    }
    return false;
  }

  bool DFS(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int index, int i, int j) {
    if (board[i][j] != word[index]) return false;
    if (index == word.length() - 1) return true;
    visited[i][j] = true;
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    for(int k = 0; k < 4; k++) {
      int ii = i + dir[k][0], jj = j + dir[k][1];
      if (ii >= 0 && ii < board.size() && jj >= 0 && jj < board[0].size() && !visited[ii][jj]) {
        if (DFS(board, visited, word, index + 1, ii, jj)) return true;
      }
    }
    visited[i][j] = false;
    return false;
  }
};
