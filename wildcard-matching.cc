class Solution {
public:
  //check: how to deal with *
  bool isMatch(string s, string p) {
    vector<vector<bool>> res = vector<vector<bool>>(s.length() + 1, vector<bool>(p.length() + 1, false));
    for(int i = 0; i <= s.length(); i++) {
      for(int j = 0; j <= p.length(); j++) {
        if (i == 0) {
          if (j == 0) {
            res[i][j] = true;
          } else {
            if (p[j-1] == '*') {
              res[i][j] = res[i][j-1];
            } else {
              res[i][j] = false;
            }
          }
        } else if (j == 0) {
          res[i][j] = false;
        } else {
          if (s[i-1] == p[j-1]) {
            res[i][j] = res[i-1][j-1];
          } else {
            if (p[j-1] == '?') {
              res[i][j] = res[i-1][j-1];
            } else if (p[j-1] == '*') {
              res[i][j] = res[i-1][j] || res[i][j-1];
            } else {
              res[i][j] = false;
            }
          }
        }
      }
    }
    return res[s.length()][p.length()];
  }
};
