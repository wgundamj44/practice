class Solution {
public:
  //check
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int h = dungeon.size();
    int w = dungeon[0].size();
    vector<vector<int>> hp(h, vector<int>(w, 0));
    int i1 = w - 1, j1 = h - 1;
    while(true) {
      for(int j = j1, i = i1; i <= w - 1 && j >= 0; j--, i++) {
        if (i1 == w -1 && j == h - 1) {
          hp[j][i] = dungeon[j][i] > 0 ? 1 : 1 - dungeon[j][i];
        } else {
          int next;
          if (j + 1 > h - 1) {
            next = hp[j][i+1];
          } else if (i + 1 > w - 1) {
            next = hp[j+1][i];
          } else {
            next = min(hp[j+1][i], hp[j][i+1]);
          }
          if (dungeon[j][i] >= 0) {
            if (dungeon[j][i] >= next) {
              hp[j][i] = 1;
            } else {
              hp[j][i] = next - dungeon[j][i];
            }
          } else {
            hp[j][i] = next - dungeon[j][i];
          }
        }
      }
      if (i1 == 0 && j1 == 0) break;
      if (i1 > 0) i1--;
      else j1--;
    };
    return hp[0][0];
  }
};
