class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size();
        if (h == 0) return false;
        int w = board[0].size();
        if (w == 0) return false;
        
        vector<vector<bool>> flags(h, vector<bool>(w, false));
        for(int i = 0; i < w; i++) {
            for(int j = 0; j < h; j++) {
                bool ret = search(board, word, j, i, 0, h, w, flags);
                if (ret) return true;
            }
        }
        return false;
    }
    
    bool search(vector<vector<char>>& board, string& word, int j, int i, int l, int h, int w, vector<vector<bool>>& flags) {
        if (board[j][i] != word[l]) return false;
        if (l >= word.length()) return false;
        
        if (l == word.length() - 1) return true;
        
        flags[j][i] = true;
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int k = 0; k < 4; k++) {
            int ni = i + dir[k][0], nj = j + dir[k][1];
            if (ni >=0 && ni < w && nj >=0 && nj < h && flags[nj][ni] == false) {
                bool ret = search(board, word, nj, ni, l + 1, h, w, flags);
                if (ret) return true;
            } 
        }
        flags[j][i] = false;
        return false;
    }
};
