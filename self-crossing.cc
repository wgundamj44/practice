class Solution {
public:
  //check: 3 patterns
  bool isSelfCrossing(vector<int>& x) {
    for(int i = 0; i < x.size(); i++) {
      if (i >= 3) {
        if (x[i] + x[i-4] >= x[i-2] && x[i-1] == x[i-3]) return true;
        if (x[i] >= x[i-2] && x[i-1] <= x[i-3]) return true;
        if (i >= 5) {
          if (x[i-1] <= x[i-3] && x[i-1] + x[i-5] >= x[i-3] && x[i] + x[i-4] >= x[i-2] && x[i-2] > x[i-4]) return true;
        }
      }
    }
    return false;
  }
};
