#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int h = obstacleGrid.size(), w = obstacleGrid[0].size();
        vector<vector<int>> paths = vector<vector<int>>(h, vector<int>(w, 0));
        for(int i = 0; i < h + w - 1; i++) {
            if (i == 0) paths[h-1][w-1] = obstacleGrid[h-1][w-1] == 1 ? 0 : 1;
            else {
                int x = w - 1 - i >= 0 ? w - 1 - i : 0;
                int y = w - 1 - i >= 0 ? h - 1 : h - 1 - (i - w + 1);
                for(; x >= 0 && x < w && y >= 0 && y < h; x = x + 1, y = y - 1) {
                    if (obstacleGrid[y][x] == 1) paths[y][x] = 0;
                    else {
                        if (x + 1 < w) {
                            paths[y][x] = obstacleGrid[y][x+1] == 1  ? 0 : paths[y][x+1];
                        }
                        if (y + 1 < h) {
                            if (x + 1 < w) {
                                if (obstacleGrid[y+1][x] == 0) {
                                    paths[y][x] += paths[y+1][x];
                                }
                            } else {
                                paths[y][x] = obstacleGrid[y+1][x] == 1 ? 0 : paths[y+1][x];
                            }
                        }
                    }
                }
            }
        }
        return paths[0][0];
    }
};

int main() {
  Solution s;
  vector<vector<int>> grid = [[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[1,0],[0,0],[0,0],[0,0],[0,0],[0,0],[1,0],[0,0],[0,0],[0,0],[0,0],[0,1],[0,0],[0,0],[1,0],[0,0],[0,0],[0,1],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,1],[0,0],[0,0],[0,0],[0,0],[1,0],[0,0],[0,0],[0,0],[0,0]] ;
  cout << s.uniquePathsWithObstacles(grid);
}
