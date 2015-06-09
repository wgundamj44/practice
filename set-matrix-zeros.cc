class Solution {
public:
    int h = 0;
    int w = 0;
    void setZeroes(vector<vector<int>>& matrix) {
        h = matrix.size();
        if (h == 0) return;
        w = matrix[0].size();
        // make use of the first row / column
        bool firstRowZero = false, firstColumnZero = false;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) {
                        firstRowZero = true;
                    }
                    if (j == 0) {
                        firstColumnZero = true;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < h; i++) {
            if (matrix[i][0] == 0) {
                for(int j = 1; j < w; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < w; i++) {
            if (matrix[0][i] == 0) {
                for(int j = 1; j < h; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        if (firstRowZero) {
            for(int i = 0; i < w; i++) {
                matrix[0][i] = 0;
            }
        }
        
        if (firstColumnZero) {
            for(int i = 0; i < h; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
