class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int h = grid.size();
        if (h == 0) return 0;
        int w = grid[0].size();
        if (w == 0) return 0;

        vector<vector<int>> res = vector<vector<int>>(h, vector<int>(w, 0));
        for(int i = 0; i < h + w - 1; i++) {
            if (i == 0) res[h-1][w-1] = grid[h-1][w-1];
            else {
                int x = w - 1 - i >= 0 ? w - 1 - i : 0;
                int y = w - 1 - i >= 0 ? h - 1 : h - 1 - (i - w + 1);
                for(; x < w && x >= 0 && y < h && y >= 0; x = x + 1, y = y - 1) {
                    if (x + 1 < w) {
                        res[y][x] = grid[y][x] + res[y][x+1];
                    }
                    if (y + 1 < h) {
                        if (x + 1 < w) res[y][x] = min(res[y][x], grid[y][x] + res[y+1][x]);
                        else res[y][x] = grid[y][x] + res[y+1][x];
                    }
                }
            }
        }
        return res[0][0];
    }
};
