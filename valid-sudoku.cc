class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int w = board.size();
        if (w == 0) return false;
        
        for(auto row: board) {
            set<char> st;
            for(int i = 0; i < w; i++) {
                if (row[i] != '.' && st.find(row[i]) != st.end()) {
                    return false;
                }
                st.insert(row[i]);
            }
        }
        for(int i = 0; i < w; i++) {
            set<char> st;
            for(int j = 0; j < w; j++) {
                if (board[j][i] != '.' && st.find(board[j][i]) != st.end()) {
                    return false;
                }
                st.insert(board[j][i]);
            }
        }
        
        int i = 0, j = 0;
        for(int i = 0; i <= w - 3; i += 3) {
            for(int j = 0; j <= w - 3; j += 3) {
                set<char> st;
                for(int k = 0; k < 3; k++)  {
                    for(int z = 0; z < 3; z++) {
                        if (board[i + k][j + z] != '.' && st.find(board[i+k][j+z]) != st.end()) {
                            return false;
                        }
                        st.insert(board[i+k][j+z]);
                    }
                }
            }
        }
        
        return true;
    }
};