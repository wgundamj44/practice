class Solution {
public:
  //check: use start index or end index when binary search quit
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h = matrix.size();
        if (h == 0) return false;
        int w = matrix[0].size();
        
        int column = bSearchColumn(matrix, 0, h - 1, target);
        if (column == -1) return false;
        int row = bSearchRow(matrix, 0, w - 1, column, target);
        
        return row != -1 ? true : false;
    }
    
    int bSearchColumn(vector<vector<int>>& matrix, int s, int e, int target) {
        if (matrix[s][0] > target) return - 1;
        
        while(s <= e) {
            int mid = (s + e) / 2;
            if (matrix[mid][0] == target) {
                return mid;
            } else if(matrix[mid][0] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return e;
    }
    
    int bSearchRow(vector<vector<int>>& matrix, int s, int e, int col, int target) {
        while(s <= e) {
            int mid = (s + e) / 2;
            if (matrix[col][mid] == target) {
                return mid;
            } else if(matrix[col][mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return -1;
    }
};
